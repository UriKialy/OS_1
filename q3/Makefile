# Compiler
CC := g++

# Compiler flags
CFLAGS := -Wall -g -Wextra -pedantic -std=c++11

# Source files
SRC := q3.cpp

# Header files
HEADERS := q3.hpp

# Object files
OBJ := $(SRC:.cpp=.o)

# Library name
LIB := libpoisson.so

# Build target
all: $(LIB)

# Compile source files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Create dynamic library
$(LIB): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $^

# Clean build artifacts
clean:
	rm -f $(OBJ) $(LIB)