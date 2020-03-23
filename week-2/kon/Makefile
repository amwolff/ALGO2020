CXXFLAGS = -std=c++17
FILENAME = $(shell basename $(CURDIR))

all: $(FILENAME)

$(FILENAME): $(FILENAME).o
	$(CXX) -o $(FILENAME) $(FILENAME).o

$(FILENAME).o: $(FILENAME).cpp

clean:
	rm -f *.o $(FILENAME)
