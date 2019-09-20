CFLAGS = -O
CC = g++
NumTest: main.o automata.o
	$(CC) $(CFLAGS) -o main main.o automata.o -g
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -g
automata.o: automata.cpp
	$(CC) $(CFLAGS) -c automata.cpp -g
clean:
	rm -f core *.o
