FLAGS = -Wall -pedantic-errors

compile:
	g++ $(FLAGS) -c Matrix.cpp
	g++ $(FLAGS) -c p1.cpp
	g++ $(FLAGS) -o p1 Matrix.o p1.o

run: compile
	./p1

clean:
	rm -f p1
	rm -f *.o
