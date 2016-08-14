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

int roman_to_arabic(const char* x) {
	int total = 0;
	int size = strlen(x);
	int i;
	int current_arabic = 0;
	int previous_arabic = 0;
	int repeat = 1;
	for (i = size; i >= 0; --i)
	{
		current_arabic = roman_char_to_arabic(x[i]);
		if (current_arabic < previous_arabic){
			if (current_arabic == 1 && (previous_arabic == 50) || (previous_arabic == 100) || (previous_arabic == 500)){
				return ERROR;
			}
			total -= current_arabic;
			repeat = 1;
		}
		else if(current_arabic == previous_arabic){
			total += current_arabic;
			repeat++;
			if (repeat > max_repeat(current_arabic)){
				return ERROR;
			}
		}
		else{
			total += current_arabic;
			repeat = 1;
		}
		previous_arabic = current_arabic;
	}
	return total;
}
