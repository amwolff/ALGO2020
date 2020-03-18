#!/usr/bin/env sh

# Usage: ./mkdir.sh directory_name

mkdir -p $1

echo 'CC = g++\nDN = $(shell basename $(CURDIR))\n\nall: $(DN).o\n\t$(CC) -std=c++17 $(DN).cpp -o $(DN)\n\nclean:\n\trm -rf *.o $(DN)' > $1/Makefile

echo 'int main() { return 0; }' > $1/$(basename $1).cpp
