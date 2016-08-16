.PHONY: clean
.PHONY: all

all: roman roman_converter

roman: roman-converter.o roman.o roman-test.o
	gcc roman.o roman_converter.o roman-test.o -o roman -lcheck -lm -lpthread -lrt

roman_converter: roman_converter.o roman_converter-test.o
	gcc roman_converter-test.o roman_converter.o -o roman_converter -lcheck -lm -lpthread -lrt

roman_converter-test.o: roman_converter-test.c
	gcc roman_converter-test.c -o roman_converter-test.o -c

roman_converter-test.c: roman_converter-test.check
	checkmk roman_converter-test.check > roman_converter-test.c

roman-converter.o: roman_converter.c
	gcc roman_converter.c -o roman_converter.o -c

roman-test.o: roman-test.c
	gcc roman-test.c -o roman-test.o -c

roman-test.c: roman-test.check
	checkmk roman-test.check > roman-test.c

roman.o: roman.c
	gcc roman.c -o roman.o -c

clean:
	rm -f *.o roman-test.c roman_converter-test.c roman roman_converter
