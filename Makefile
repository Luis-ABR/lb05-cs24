CXX      := g++
CXXFLAGS := -std=c++20 -Wall -g

# Default target: builds the examheap executable
all: examheap

# Link heap.o and examheap.o into examheap
examheap: heap.o examheap.o
	$(CXX) $(CXXFLAGS) heap.o examheap.o -o examheap

# Compile your implementation
heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp -o heap.o

# Compile the provided driver
examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp -o examheap.o

clean:
	 rm -f *.o examheap
