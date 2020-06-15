sim : 
	g++ -o chainSIM.o src/chainSIM.cpp 

run :
	./chainSIM.o

clean : 
	rm -rf chainSIM.o