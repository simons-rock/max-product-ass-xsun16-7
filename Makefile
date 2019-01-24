CC = gcc
CFLAGS = -Wall -std=c99

all: test

max_product_naive.o: max_product_naive.c max_product.h 
	$(CC) $(CFLAGS) -c max_product_naive.c

max_product_fast.o: max_product_fast.c max_product.h
	$(CC) $(CFLAGS) -c max_product_fast.c
	
test.o: test.c max_product.h
	$(CC) $(CFLAGS) -c test.c
	
test: max_product_naive.o max_product_fast.o test.o
	$(CC) $(CFLAGS) -o test max_product_naive.o max_product_fast.o test.o

clean:
	rm *.o test
