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
	else if (*x == 'L'){
		return 50;
	}
	else if (*x == 'C'){
		return 100;
	}
	else if (*x == 'D'){
		return 500;
	}
	else{
		return 1000;
	}
}
