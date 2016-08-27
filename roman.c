#include "roman_converter.h"
#include "constants.h"
#include "string.h"

void handle_roman(const char* x, const char* y, char* result, const int add){
	memset(result, 0, MAX_SIZE);
	int l = roman_to_arabic(x);
	int r = roman_to_arabic(y);
	int total;

	if (l == ERROR || r == ERROR){
		strcpy(result, INVALID);
	}else{

		if(add){
			total = l + r;
		}else{
			total = l - r;
		}
		arabic_to_roman(total, result);
	}
}

void add_roman(const char* x, const char* y, char* result){
	handle_roman(x, y, result, 1);
}

void subtract_roman(const char* x, const char* y, char* result){
	handle_roman(x, y, result, 0);
}
