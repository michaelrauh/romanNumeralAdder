#include "roman_converter.h"
#include "constants.h"
#include "string.h"

void handle_roman(const char* x, int x_len, const char* y, int y_len, char* result, const int add){
	memset(result, 0, MAX_SIZE);
	int l = roman_to_arabic(x, x_len);
	int r = roman_to_arabic(y, y_len);
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

void add_roman(const char* x, const int x_len, const char* y, const int y_len, char* result){
	handle_roman(x, x_len, y, y_len, result, 1);
}

void subtract_roman(const char* x, const int x_len, const char* y, const int y_len, char* result){
	handle_roman(x, x_len, y, y_len, result, 0);
}
