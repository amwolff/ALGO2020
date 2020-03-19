CC = g++
DN = $(shell basename $(CURDIR))

all: $(DN).o
	$(CC) -std=c++17 $(DN).cpp -o $(DN)

clean:
	rm -rf *.o $(DN)
