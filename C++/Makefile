# Makefile
all: setup

setup: main.o KeyLogger.o
	g++ main.o -o setup

main.o: main.cpp
	g++ -c main.cpp -o main.o

KeyLogger.o: KeyLogger.cpp
	g++ -c KeyLogger.cpp -o KeyLogger.o

clean:
	rm -f main.o KeyLogger.o