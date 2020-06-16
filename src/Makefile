all: Main.out

Main.out: Main.cpp chainSIM.h chain.c chainSIM.cpp Matrix.h Matrix.cpp
	g++ Main.cpp chainSIM.cpp Matrix.cpp -lstdc++ -o Main.out

clean:
	rm -rf Main.out
