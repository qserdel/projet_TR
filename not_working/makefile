all: clean gpio.o gpio

gpio.o: gpio.cpp gpio.hpp
	g++ -c gpio.cpp

gpio: gpio.o
	g++ -o gpio gpio.o

clean:
	rm -f *.o
