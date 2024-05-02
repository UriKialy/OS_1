CC = g++
CFLAGS = -Wall -g -Wextra -std=c++11

all: q1 q2

q1: q1.cpp q1.hpp
	$(CC) $(CFLAGS) -o q1 q1.cpp

q2: q2.cpp q2.hpp
	$(CC) $(CFLAGS) -o q2 q2.cpp

clean:
	rm -f q1 q2