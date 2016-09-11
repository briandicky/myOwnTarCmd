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

help:
	@echo "This is makefile command information:"
	@echo "==============================================="
	@echo "all = compile all the file."
	@echo "DEBUG = enable the debugger mode."
	@echo "clean = remove executable and object file."
	@echo "dep = output the compiling detail to .depend file."
	@echo "==============================================="
	@echo 'Just use "make (FLAG)" then pass argument to make command.'
	@echo ""
