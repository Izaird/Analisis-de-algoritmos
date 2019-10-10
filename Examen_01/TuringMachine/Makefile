CFLAGS = -O0 -g 
CC = g++
NumTest: main.o turing.o
	$(CC) $(CFLAGS) -o turing_machine main.o turing.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
turing.o: turing.cpp
	$(CC) $(CFLAGS) -c turing.cpp
clean:
	rm -f core *.o
