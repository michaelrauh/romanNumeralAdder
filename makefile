default: roman_converter-test.check roman_converter.c roman_converter.h
	checkmk roman_converter-test.check > roman_converter-test.c && gcc roman_converter-test.c roman_converter.c -o roman_converter -lcheck -lm -lpthread -lrt

clean:
	rm roman_converter roman_converter-test.c
