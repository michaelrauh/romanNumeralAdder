.PHONY: clean
.PHONY: all

all: target/roman target/roman_converter

target/roman: target target/roman_converter.o target/roman.o target/roman_test.o
	gcc target/roman.o target/roman_converter.o target/roman_test.o -o target/roman -lcheck -lm -lpthread -lrt

target/roman_converter: target target/roman_converter.o target/roman_converter_test.o
	gcc target/roman_converter_test.o target/roman_converter.o -o target/roman_converter -lcheck -lm -lpthread -lrt

target/roman_converter_test.o: target target/roman_converter_test.c
	gcc target/roman_converter_test.c -o target/roman_converter_test.o -c

target/roman_converter_test.c: target test/roman_converter_test.check
	checkmk test/roman_converter_test.check > target/roman_converter_test.c

target/roman_converter.o: target src/roman_converter.c
	gcc src/roman_converter.c -o target/roman_converter.o -c

target/roman_test.o: target target/roman_test.c
	gcc target/roman_test.c -o target/roman_test.o -c

target/roman_test.c: target test/roman_test.check
	checkmk test/roman_test.check > target/roman_test.c

target/roman.o: target src/roman.c
	gcc src/roman.c -o target/roman.o -c

clean:
	rm -rf target

target:
	mkdir target
