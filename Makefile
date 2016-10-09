CC = g++
CFLAGS = -Wall -std=c++14

default: cppa2z
	
run:
	./cppa2z

cppa2z: main.o non_modifying_sequence.t.o
	$(CC) $(CFLAGS) -o cppa2z main.o non_modifying_sequence.t.o

main.o: main.cpp
	$(CC) $(CFLAGS) -I. -c main.cpp

non_modifying_sequence.t.o: ./algorithms/non_modifying_sequence.t.cpp
	$(CC) $(CFLAGS) -I. -c ./algorithms/non_modifying_sequence.t.cpp

.PHONY: clean
clean:
	$(RM) cppa2z *.o
