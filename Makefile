HOME = Chain-IC
CXX = g++

CXXFLAGS = -g -Wall -std=c++14 -pthread
SRCS = Main.cpp src/chain.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: Main

test-cpp:
	python3 project_test.py test-cpp

Main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Main

Main.o: Main.cpp src/chain.h src/timer.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

chain.o: src/chain.cpp src/chain src/timer.h 
	$(CXX) $(CXXFLAGS) -c src/chain.cpp

clean:
	rm -rf *.o Main
	rm -rf src/chain.o