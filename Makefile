# Makefile

CXX      := g++
CXXFLAGS := -std=c++20 -Wall -g

all: heap.o

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp -o heap.o

clean:
	rm -f *.o
