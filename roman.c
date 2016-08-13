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
	while(*x)
	{
		total += roman_char_to_arabic(x);
		x++;
	}
	return total;
}
