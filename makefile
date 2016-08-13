default: roman-test.check roman.c roman.h
	checkmk roman-test.check > roman-test.c && gcc roman-test.c roman.c -o roman -lcheck -lm -lpthread -lrt

clean:
	rm roman roman-test.c
