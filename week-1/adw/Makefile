CC = g++
EX = $(shell basename $(CURDIR))

all: $(EX).o
	$(CC) $(EX).cpp -o $(EX)

clean:
	rm -rf *.o $(EX)
