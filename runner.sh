#!/bin/bash

# compile
gcc -c matrix.c -o matrix.o
gcc -c utils.c -o utils.o
gcc -c main.c -o main.o

# link
gcc main.o matrix.o utils.o -o program

# cleanup object files
rm matrix.o main.o utils.o

# run
./program