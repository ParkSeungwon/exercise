CFLAG = -std=c++11 -pthread -g -fmax-errors=1
CC = g++
SRC = $(wildcard *.cc)
EXE = $(patsubst %.cc, %.x, $(SRC))

all : $(EXE)

%.x : %.cc
	$(CC) $< -o $@ $(CFLAG)
#	./$@

clean:
	rm $(EXE)
