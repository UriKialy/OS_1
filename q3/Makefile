# Define compiler and flags
CC = g++
CFLAGS = -Wall -g -std=c++11
EXEC_NAME = q3

# Define source and object files
POISSON_SRC = Poisson.cpp
Q3_SRC = q3.cpp
POISSON_HDR = Poisson.hpp
POISSON_OBJ = libpoisson.so
Q3_OBJ = q3.o

# All targets (phony target)
all: $(EXEC_NAME)

$(POISSON_OBJ): $(POISSON_SRC) $(POISSON_HDR)
	$(CC) $(CFLAGS) -c -fPIC -o libpoisson.so Poisson.cpp

$(Q3_OBJ): $(Q3_SRC) $(POISSON_HDR)
	$(CC) $(CFLAGS) -c -o q3.o q3.cpp


# Executable target
$(EXEC_NAME): $(Q3_OBJ) $(POISSON_OBJ)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(Q3_OBJ) -L. -lpoisson


# Clean target
clean:
	rm -f $(POISSON_OBJ) $(Q3_OBJ) $(POISSON_OBJ) $(EXEC_NAME)

.PHONY: all clean
