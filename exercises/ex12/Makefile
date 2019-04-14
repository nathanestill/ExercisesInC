all: 
	make counter; make counter_array; make counter_array_mutex;

counter: counter.c
	gcc -Wall -o counter counter.c -lpthread

counter_array: counter_array.c
	gcc -Wall -o counter_array counter_array.c -lpthread

counter_array_mutex: counter_array_mutex.o mutex.o
	gcc -Wall -o counter_array_mutex counter_array_mutex.o mutex.o -lpthread

mutex.o: mutex.c mutex.h
	gcc -c mutex.c	

counter_array_mutex.o: counter_array_mutex.c mutex.h
	gcc -c counter_array_mutex.c

counter_mutex: counter_mutex.c
	gcc -Wall -o counter_mutex counter_mutex.c -lpthread

barrier: barrier.c utils.c
	gcc -Wall -std=c99 -o barrier barrier.c utils.c -lpthread

barrier_soln: barrier_soln.c utils.c
	gcc -Wall -std=c99 -o barrier_soln barrier_soln.c utils.c -lpthread

read_write: read_write.c utils.c
	gcc -Wall -std=c99 -o read_write read_write.c utils.c -lpthread

read_write_soln: read_write_soln.c utils.c
	gcc -Wall -std=c99 -o read_write_soln read_write_soln.c utils.c -lpthread
