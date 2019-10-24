Lab07: main.o MinMaxHeap.o Menu.o
	g++ -std=c++11 main.o MinMaxHeap.o Menu.o -o Lab07
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.h
	g++ -std=c++11 -c MinMaxHeap.cpp

clean:
	rm -f test *.o