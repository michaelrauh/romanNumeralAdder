#include "roman_converter.h"
#include "constants.h"
#include "string.h"

int roman_char_to_arabic(const char x){
	const char numerals[] = {ROMAN_CHAR_I, ROMAN_CHAR_V, ROMAN_CHAR_X, ROMAN_CHAR_L, ROMAN_CHAR_C, ROMAN_CHAR_D, ROMAN_CHAR_M};
	const int arabics[] = {ARABIC_ONE, ARABIC_FIVE, ARABIC_TEN, ARABIC_FIFTY, ARABIC_ONE_HUNDRED, ARABIC_FIVE_HUNDRED, ARABIC_ONE_THOUSAND};
	int i;
	for (i = 0; i < NUMBER_OF_NUMERALS; i++)
	{
		if (numerals[i] == x)
		{
			return arabics[i];
		}
	}
	return ERROR;
}

int max_repeat(const int x){
	if ((x == ARABIC_FIVE) || (x == ARABIC_FIFTY) || (x == ARABIC_FIVE_HUNDRED)){
		return SMALLER_MAX_REPEAT;
	}
	else{
		return LARGER_MAX_REPEAT;
	}
}

int invalid_subtract(const int cur, const int prev){
	if (cur == ARABIC_ONE){
		return !((prev == ARABIC_FIVE) || (prev == ARABIC_TEN));
	}
	if (cur == ARABIC_TEN){
		return !((prev == ARABIC_FIFTY) || (prev == ARABIC_ONE_HUNDRED));
	}
	if (cur == ARABIC_ONE_HUNDRED){
		return !((prev == ARABIC_FIVE_HUNDRED) || (prev == ARABIC_ONE_THOUSAND));
	}
}

int contains(const int seen[], const int current, const int size){
	int i;
	for (i = 0;i<size;i++){
		if (seen[i] == current){
			return 1;
		}
	}
	return 0;
}

int roman_to_arabic(const char* x) {
	if (x == NULL){
		return ERROR;
	}
	int total = 0;
	int size = strlen(x);
	int i;
	int current_arabic = 0;
	int previous_arabic = 0;
	int repeat = MINIMUM_REPEAT;
	int subtract = 0;
	int seen[size];
	int tracking = 0;
	for (i = size -1; i >=0; --i)
	{
		current_arabic = roman_char_to_arabic(x[i]);
		seen[tracking] = current_arabic;
		tracking++;
		if (current_arabic == ERROR){
			return ERROR;
		}
		if (current_arabic < previous_arabic){
			if (invalid_subtract(current_arabic, previous_arabic)){
				return ERROR;
			}
			if (contains(seen, previous_arabic, tracking-PLACE_VALUE_LOOK_BACK)){
				return ERROR;
			}
			total -= current_arabic;
			subtract = 1;
			repeat = MINIMUM_REPEAT;
		}
		else if(current_arabic == previous_arabic){
			total += current_arabic;
			repeat++;
			if (repeat > max_repeat(current_arabic)){
				return ERROR;
			}
			if (subtract){
				return ERROR;
			}
		}
		else{
			total += current_arabic;
			repeat = MINIMUM_REPEAT;
			subtract = 0;
		}
		previous_arabic = current_arabic;
	}
	return total;
}

void arabic_to_max_roman_pattern(const int x, char* result){
	const int arabics[] = {ARABIC_ONE_THOUSAND, ARABIC_NINE_HUNDRED, ARABIC_FIVE_HUNDRED, ARABIC_FOUR_HUNDRED, ARABIC_ONE_HUNDRED, ARABIC_NINETY, ARABIC_FIFTY, ARABIC_FORTY, ARABIC_TEN, ARABIC_NINE, ARABIC_FIVE, ARABIC_FOUR, ARABIC_ONE};
	const char* numerals[] = {ROMAN_STRING_M, ROMAN_STRING_CM, ROMAN_STRING_D, ROMAN_STRING_CD, ROMAN_STRING_C, ROMAN_STRING_XC, ROMAN_STRING_L, ROMAN_STRING_XL, ROMAN_STRING_X, ROMAN_STRING_IX, ROMAN_STRING_V, ROMAN_STRING_IV, ROMAN_STRING_I};
	int i;
	for(i = 0;i < NUMBER_OF_NUMERAL_PATTERNS; i++){
		if (arabics[i] <= x){
			memset(result, 0, MAX_SIZE);
			strcpy(result, numerals[i]);
			break;
		}
	}
}

void arabic_to_roman(int x, char* result){
	memset(result, 0, MAX_SIZE);
	if (x >= TOO_LARGE_ARABIC || x < SMALLEST_ARABIC){
		strcpy(result, INVALID);
	}
	else{
		while(x > 0){
			char current [PATTERN_SIZE];
			arabic_to_max_roman_pattern(x, current);
			int value = roman_to_arabic(current);
			strcat(result, current);
			x -= value;
		}
	}
}
