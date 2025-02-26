CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main

main: BigUnsigned.o BigInteger.o BigRational.o main.o
	$(CXX) $(CXXFLAGS) -o main BigUnsigned.o BigInteger.o BigRational.o main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o main