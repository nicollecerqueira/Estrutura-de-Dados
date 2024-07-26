CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: main

main: main.o selection-sort.o insertion-sort.o
	$(CXX) $(CXXFLAGS) -o main main.o selection-sort.o insertion-sort.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

selection-sort.o: selection-sort.cpp
	$(CXX) $(CXXFLAGS) -c selection-sort.cpp

insertion-sort.o: insertion-sort.cpp
	$(CXX) $(CXXFLAGS) -c insertion-sort.cpp

clean:
	rm -f *.o main