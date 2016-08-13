#include "roman.h"

int roman_to_arabic(char* x) {
	if (*x == 'I'){
		return 1;
	}
	else if (*x == 'V'){
		return 5;
	}
	else if (*x == 'X'){
		return 10;
	}
	else{
		return 50;
	}
}
