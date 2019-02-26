main.o: main.c trout.h
	gcc -c main.c

trout.o: trout.h trout.c
	gcc -c trout.c

util.o: util.h util.c
	gcc -c util.c

trout: main.o trout.o util.o
	gcc main.o trout.o util.o -o trout