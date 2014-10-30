printer:queue.o
	gcc printer.c queue.o -o printer
queue.o:queue.h queue.c
	gcc -c queue.c -o queue.o
clean:
	rm *.o printer