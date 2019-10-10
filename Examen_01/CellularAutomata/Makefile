CFLAGS = -O0 -g 
CC = g++
NumTest: main.o cellular_automaton.o
	$(CC) $(CFLAGS) -o cellular_automaton main.o cellular_automaton.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
cellular_automaton.o: cellular_automaton.cpp
	$(CC) $(CFLAGS) -c cellular_automaton.cpp
clean:
	rm -f core *.o
