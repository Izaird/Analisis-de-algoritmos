CFLAGS = -O0 -g
CC = g++
NumTest: main.o automata.o
	$(CC) $(CFLAGS) -o DFA main.o automata.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
automata.o: automata.cpp
	$(CC) $(CFLAGS) -c automata.cpp
clean:
	rm -f core *.o
