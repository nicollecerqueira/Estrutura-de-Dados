CXX = g++
CXXFLAGS = -Wall -O2
TARGET = main

all: $(TARGET)

main: main.o selection-sort.o insertion-sort.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o selection-sort.o insertion-sort.o

main.o: main.cpp selection-sort.h insertion-sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

selection-sort.o: selection-sort.cpp selection-sort.h
	$(CXX) $(CXXFLAGS) -c selection-sort.cpp

insertion-sort.o: insertion-sort.cpp insertion-sort.h
	$(CXX) $(CXXFLAGS) -c insertion-sort.cpp

clean:
	rm -f $(TARGET) *.o
