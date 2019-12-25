all: pj10

pj10: main.o listA.o listN.o
	g++ main.o listA.o listN.o -o pj10

main.o: main.cpp
	g++ -c main.cpp

listA.o: listA.cpp
	g++ -c listA.cpp

listN.o: listN.cpp
	g++ -c listN.cpp

clean:
	rm -f *.o pj10
