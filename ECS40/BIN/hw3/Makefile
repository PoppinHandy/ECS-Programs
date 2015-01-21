all: battleship 

CXXFLAGS=-g -Wall

Ship.o: Ship.cpp Ship.h
battleship.o: battleship.cpp 
Board.o: Board.h Board.cpp 
battleship: Ship.o battleship.o Board.o 
	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -f *.o battleship 
