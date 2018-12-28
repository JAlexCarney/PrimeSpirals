CFLAGS = -Wall
CC = g++
FLAGS = $(CFLAGS)

all: ulam clean

ulam: ulam.o bitVec.o
	$(CC) $(FLAGS) -o ulam ulam.o bitVec.o

bitVec.o: bitVec.cc bitVec.h
	$(CC) $(FLAGS) -c bitVec.cc

ulam.o: ulam.cc
	$(CC) $(FLAGS) -c ulam.cc

clean:
	rm -f *o ulam outspiral.txt
