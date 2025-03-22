# Makefile for SRK Equation of State Calculator

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = srk_calculator
SOURCES = main.cpp chemicals.cpp srk_solver.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean