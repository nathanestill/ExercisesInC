main.o: main.c trout.h util.h
	gcc -c -Wall main.c

trout.o: trout.h trout.c util.h
	gcc -c -Wall trout.c

util.o: util.h util.c
	gcc -c -Wall util.c

trout: main.o trout.o util.o
	gcc main.o trout.o util.o -o trout