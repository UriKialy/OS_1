# Define the base name for executables (without extension)
TARGET = main

# Define the header file
HEADER = q5.hpp

# Define all .cpp files (excluding main.cpp)
Q_FILES = q51.cpp q52.cpp q53.cpp
OBJECTS = $(Q_FILES:.cpp=.o) main.o  
# Define the C++ compiler (adjust if needed)
CXX = g++

# Define compiler flags (feel free to add more flags)
CXXFLAGS = -Wall -g -std=c++11
# Object file for main.cpp
main.o: main.cpp $(HEADER)
    $(CXX) $(CXXFLAGS) -c $<  # Compile main.cpp

# Pattern rule to build executables with different q files
$(TARGET)%: $(OBJECTS) $(HEADER)
    $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

# Define object files for each executable variant
q51.o: q51.cpp $(HEADER)
q52.o: q52.cpp $(HEADER)
q53.o: q53.cpp $(HEADER)

# Rule to compile each .cpp file into an object file
%.o: %.cpp $(HEADER)
    $(CXX) $(CXXFLAGS) -c $<  # $< refers to the current source file

# Phony target for cleaning up object files
clean:
    rm -f $(TARGET)*.o
