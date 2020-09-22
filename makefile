all: gpio pwm clean

gpio.o: gpio.cpp
	g++ -c gpio.cpp

gpio: gpio.o
	g++ -o gpio gpio.o

pwm.o: pwm.cpp
	g++ -c pwm.cpp

pwm: pwm.o
	g++ -o pwm pwm.o -lwiringPi

clean:
	rm -f *.o
