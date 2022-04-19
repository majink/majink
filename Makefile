CC = gcc
prod : main.c manager.o
	gcc -o prod main.c manager.o
manager.o : manager.c manager.h
	$(CC) -c manager.c manager.o


clean:
	rm *.o prod
