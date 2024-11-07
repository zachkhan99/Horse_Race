# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = horse_race

.PHONY: all clean valgrind

# Default target: compile
all: $(TARGET)

# Compile the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile and run the program
run: $(TARGET)
	./$(TARGET)

# Clean up executable and object files
clean:
	rm -f $(TARGET) $(OBJS)

# Check for memory leaks using Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)



