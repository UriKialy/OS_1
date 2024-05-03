# Define compiler and flags
CC = g++
CFLAGS = -Wall -g -std=c++11

# Define library and executable names
LIB_NAME = libpoisson.so
EXEC_NAME = q3

# Define source and object files
POISSON_SRC = Poisson.cpp
Q3_SRC = q3.cpp
Q3_HDR = q3.hpp

# Object files for library and executable
POISSON_OBJ = $(POISSON_SRC:.cpp=.o)
Q3_OBJ = $(Q3_SRC:.cpp=.o)

# All targets (phony target)
all: $(EXEC_NAME)

# Library target
$(LIB_NAME): $(POISSON_OBJ) $(Q3_HDR)
	$(CC) $(CFLAGS) -fPIC -shared -o $(LIB_NAME) $(POISSON_OBJ)

# Executable target
$(EXEC_NAME): $(Q3_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(Q3_OBJ) -L. -lpoisson

$(Q3_OBJ): $(Q3_SRC) $(Q3_HDR)
	$(CC) -o $(Q3_OBJ) $(Q3_SRC)

# Clean target
clean:
	rm -f $(POISSON_OBJ) $(Q3_OBJ) $(LIB_NAME) $(EXEC_NAME)

.PHONY: all clean
