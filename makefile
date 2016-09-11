all: mosTar

mosTar: mostar.o main.o
	g++ -o mosTar mostar.o main.o

mostar.o: mostar.cpp
	g++ -c -Wall mostar.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

dep:
	g++ -M *.cpp > .depend

clean:
	rm -f mosTar *.o .depend
