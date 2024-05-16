# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Define the target executable
TARGET = dijkstra

# Define the source files
SRCS = 4.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
