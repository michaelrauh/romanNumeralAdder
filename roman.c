#include "roman.h"
#include "string.h"

int roman_char_to_arabic(const char x){
	char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int arabics[] = {1, 5, 10, 50, 100, 500, 1000};
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

int roman_to_arabic(const char* x) {
	int total = 0;
	int size = strlen(x);
	int i;
	int current_arabic = 0;
	int previous_arabic = 0;
	int repeat = 1;
	int subtract = 0;
	for (i = size -1; i >=0; --i)
	{
		current_arabic = roman_char_to_arabic(x[i]);
		if (current_arabic == ERROR){
			return ERROR;
		}
		if (current_arabic < previous_arabic){
			if (invalid_subtract(current_arabic, previous_arabic)){
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

const char* arabic_to_roman(int x){
	if (x == 1){
		return "I";
	}else if (x == 5){
		return "V";
	}else if (x == 10){
		return "X";
	}else if (x == 50){
		return "L";
	}else if (x == 100){
		return "C";
	}else{
		return "D";
	}
}
