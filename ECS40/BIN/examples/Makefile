all: useFraction calculator


useFraction: useFraction.o Fraction.o
	g++ -g -Wall -o useFraction useFraction.o Fraction.o

calculator: calculator.o Fraction.o
	g++ -g -Wall -o calculator calculator.o Fraction.o

calculator.o: calculator.cpp
	g++ -g -Wall -c calculator.cpp

useFraction.o: useFraction.cpp
	g++ -g -Wall -c useFraction.cpp

Fraction.o: Fraction.cpp
	g++ -g -Wall -c Fraction.cpp

clean:
	rm -rf *.o calculator useFraction
