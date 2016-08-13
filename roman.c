#include "roman.h"

int roman_char_to_arabic(char* x){
	char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int arabics[] = {1, 5, 10, 50, 100, 500, 1000};
	int size = sizeof(numerals)/sizeof(numerals[0]);
	int i;
	for (i = 0; i < size; i++)
	{
		if (numerals[i] == *x)
		{
			return arabics[i];
		}
	}
	return ERROR;
}

int roman_to_arabic(char* x) {
	int total = 0;
	int size = sizeof(x);
	int i;
	int current_arabic = 0;
	int previous_arabic = 0;
	for (i = size; i >= 0; --i)
	{
		current_arabic = roman_char_to_arabic(&x[i]);
		if (current_arabic < previous_arabic){
			total -= current_arabic;
		}
		else{
			total += current_arabic;
		}
		previous_arabic = current_arabic;
	}
	return total;
}
