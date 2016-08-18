#include "roman_converter.h"
#include "constants.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


void add_roman(const char* x, const char* y, char* result){
	memset(result, 0, MAX_SIZE);
	int l = roman_to_arabic(x);
	int r = roman_to_arabic(y);

	if (l == ERROR || r == ERROR){
		strcat(result, INVALID);
	}else{

	int total = l + r;

	arabic_to_roman(total, result);
}
}
void subtract_roman(const char* x, const char* y, char* result){
	memset(result, 0, MAX_SIZE);
	int l = roman_to_arabic(x);
	int r = roman_to_arabic(y);

	if (l == ERROR || r == ERROR){
		strcat(result, INVALID);
	}else{

	int total = l - r;

	arabic_to_roman(total, result);
}}
