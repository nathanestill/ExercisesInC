test_util: test_util.o util.o
	gcc test_util.o util.o -o test_util

test_util.o: test_util.c util.h minunit.h
	gcc -c test_util.c

trout: main.o trout.o util.o
	gcc main.o trout.o util.o -o trout

main.o: main.c trout.h util.h
	gcc -c -Wall main.c

trout.o: trout.h trout.c util.h
	gcc -c -Wall trout.c

util.o: util.h util.c
	gcc -c -Wall util.c
