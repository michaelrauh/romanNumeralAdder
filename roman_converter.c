#include "roman_converter.h"
#include "constants.h"
#include "string.h"

int roman_char_to_arabic(const char x){
	const char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	const int arabics[] = {1, 5, 10, 50, 100, 500, 1000};
	int size = sizeof(numerals)/sizeof(numerals[0]);
	int i;
	for (i = 0; i < size; i++)
	{
		if (numerals[i] == x)
		{
			return arabics[i];
		}
	}
	return ERROR;
}

int max_repeat(const int x){
	if ((x == 5) || (x == 50) || (x == 500)){
		return 1;
	}
	else{
		return 3;
	}
}

int invalid_subtract(const int cur, const int prev){
	if (cur == 1){
		return !((prev == 5) || (prev == 10));
	}
	if (cur == 10){
		return !((prev == 50) || (prev == 100));
	}
	if (cur == 100){
		return !((prev == 500) || (prev == 1000));
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
	int total = 0;
	int size = strlen(x);
	int i;
	int current_arabic = 0;
	int previous_arabic = 0;
	int repeat = 1;
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
			if (contains(seen, previous_arabic, tracking-2)){
				return ERROR;
			}
			total -= current_arabic;
			subtract = 1;
			repeat = 1;
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
			repeat = 1;
			subtract = 0;
		}
		previous_arabic = current_arabic;
	}
	return total;
}

void arabic_to_max_roman_pattern(const int x, char* result){
	const int arabics[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	const char* numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int size = sizeof(arabics)/sizeof(arabics[0]);
	int i;
	for(i = 0;i < size; i++){
		if (arabics[i] <= x){
			memset(result, 0, MAX_SIZE);
			strcpy(result, numerals[i]);
			break;
		}
	}
}

void arabic_to_roman(int x, char* result){
	memset(result, 0, MAX_SIZE);
	if (x >= 5000 || x < 1){
		strcpy(result, INVALID);
	}
	else{
		while(x > 0){
			char current [2];
			arabic_to_max_roman_pattern(x, current);
			int value = roman_to_arabic(current);
			strcat(result, current);
			x -= value;
		}
	}
}
