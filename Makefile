
CXX      := g++
CXXFLAGS := -std=c++20 -Wall -g

all: examheap

examheap: heap.o examheap.o
<TAB>$(CXX) $(CXXFLAGS) $^ -o $@

heap.o: heap.cpp heap.h
<TAB>$(CXX) $(CXXFLAGS) -c heap.cpp -o heap.o

examheap.o: examheap.cpp heap.h
<TAB>$(CXX) $(CXXFLAGS) -c examheap.cpp -o examheap.o

clean:
<TAB>rm -f *.o examheap
