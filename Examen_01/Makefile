CFLAGS = -O0 -g 
CC = g++
NumTest: main.o cellular_turing.o
	$(CC) $(CFLAGS) -o cellular_turing main.o cellular_turing.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
cellular_turing.o: cellular_turing.cpp
	$(CC) $(CFLAGS) -c cellular_turing.cpp
clean:
	rm -f core *.o
