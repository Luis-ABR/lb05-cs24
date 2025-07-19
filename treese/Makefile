CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: treese

treese: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp Treese.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o treese
