#!/usr/bin/env sh

# Usage: ./mkdir.sh directory_name

mkdir -p $1

echo 'CXXFLAGS = -std=c++17\nFILENAME = $(shell basename $(CURDIR))\n\nall: $(FILENAME)\n\n$(FILENAME): $(FILENAME).o\n\t$(CXX) -o $(FILENAME) $(FILENAME).o\n\n$(FILENAME).o: $(FILENAME).cpp\n\nclean:\n\trm -f *.o $(FILENAME)' > $1/Makefile

echo 'int main() { return 0; }' > $1/$(basename $1).cpp
