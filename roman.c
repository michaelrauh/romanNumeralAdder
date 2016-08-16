#include "roman_converter.h"
#include "string.h"
#include "stdlib.h"

const char* add_roman(const char* x, const char* y){
	int l = roman_to_arabic(x);
	int r = roman_to_arabic(y);

	if (l == ERROR || r == ERROR){
		return INVALID;
	}

	int total = l + r;

	return arabic_to_roman(total);
}

const char* subtract_roman(const char* x, const char* y){
	int l = roman_to_arabic(x);
	int r = roman_to_arabic(y);

	if (l == ERROR || r == ERROR){
		return INVALID;
	}

	int total = l - r;

	return arabic_to_roman(total);
}
