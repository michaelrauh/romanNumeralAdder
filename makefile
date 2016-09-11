.PHONY: clean
.PHONY: all

all: roman roman_converter

roman: roman_converter.o roman.o roman_test.o
	gcc roman.o roman_converter.o roman_test.o -o roman -lcheck -lm -lpthread -lrt

roman_converter: roman_converter.o roman_converter_test.o
	gcc roman_converter_test.o roman_converter.o -o roman_converter -lcheck -lm -lpthread -lrt

roman_converter_test.o: roman_converter_test.c
	gcc roman_converter_test.c -o roman_converter_test.o -c

roman_converter_test.c: roman_converter_test.check
	checkmk roman_converter_test.check > roman_converter_test.c

roman_converter.o: roman_converter.c
	gcc roman_converter.c -o roman_converter.o -c

roman_test.o: roman_test.c
	gcc roman_test.c -o roman_test.o -c

roman_test.c: roman_test.check
	checkmk roman_test.check > roman_test.c

roman.o: roman.c
	gcc roman.c -o roman.o -c

clean:
	rm -f *.o roman_test.c roman_converter_test.c roman roman_converter
