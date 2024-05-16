# Define the base name for executables (without extension)
TARGET = main

# Define the header file
HEADER = q5.hpp

# Define all .cpp files (excluding main.cpp)
Q_FILES = q51.cpp q52.cpp q53.cpp

CXX = g++

# Define compiler flags for debugging and profiling
CXXFLAGS = -Wall -pg -std=c++11
all: main_q52 main_q51 main_q53
# Rule to compile each .cpp file into an object file
%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to compile each variant of main executable
main_q51: main.o q51.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main_q52: main.o q52.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main_q53: main.o q53.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Phony target for cleaning up object files and executables
.PHONY: clean
clean:
	rm -f main_* *.o
