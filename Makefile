# Makefile
all: setup

setup: main.o
	g++ main.o -o setup

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f main.o KeyLogger.o
