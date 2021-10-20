FLAGS = -Wall -pedantic-errors -o

compile:
	g++ -c Matrix.cpp
	g++ -c p1.cpp
	g++ -o p1 Matrix.o p1.o

run: compile
	./p1

clean:
	rm -f p1
	rm -f *.o
