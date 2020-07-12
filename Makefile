HOME = Chain-IC
CXX = g++

CXXFLAGS = -g -Wall -std=c++14
SRCS = Main.cpp src_new/chain.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: Main

test-cpp:
	python3 project_test.py test-cpp

Main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Main

Main.o: Main.cpp src_new/chain.h	src_new/timer.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

chain.o: src_new/chain.cpp src_new/chain src_new/timer.h	
	$(CXX) $(CXXFLAGS) -c src_new/chain.cpp

clean:
	rm -rf *.o Main
	rm -rf src_new/chain.o
