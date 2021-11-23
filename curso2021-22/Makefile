CC = g++ 
CFLAGS = -g 
files = main.o p3.o p4.o 

all: $(files)
	$(CC) $(CFLAGS) $(files) -o main -lm

main.o: p3.o
	$(CC) -c main.cpp

p3.o: p3.hpp p3.cpp
	$(CC) -c p3.cpp

p4.o: p4.hpp p4.cpp tads_profesorado/pila_enla.h tads_profesorado/pila_vec.h
	$(CC) -c p4.cpp

clean: 
	del $(files)
	
debug: 
	gdb ./main