#!/bin/sh

# Usage: ./mkdir.sh directory_name

mkdir $1

# TODO: Update Makefile contents.

echo 'CC = g++\nEX = $(shell basename $(CURDIR))\n\nall: $(EX).o\n\t$(CC) $(EX).cpp -o $(EX)\n\nclean:\n\trm -rf *.o $(EX)' > $1/Makefile

echo 'int main() { return 0; }' > $1/$(basename $1).cpp
