all: clean gpio.o gpio

gpio.o: gpio.cpp
	g++ -c gpio.cpp

gpio: gpio.o
	g++ -o gpio gpio.o

clean:
	rm -f *.o
