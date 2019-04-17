test3: test3.o rand.o
	gcc test3.o rand.o -o test3

test3.o: test3.c rand.h
	gcc -c test3.c

rand.o: rand.c rand.h
	gcc -c rand.c