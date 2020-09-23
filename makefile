all: gpio pwm camOpen clean

gpio.o: gpio.cpp
	g++ -c gpio.cpp

gpio: gpio.o
	g++ -o gpio gpio.o

pwm.o: pwm.cpp
	g++ -c pwm.cpp

pwm: pwm.o
	g++ -o pwm pwm.o -lwiringPi -lpthread

camOpen.o: camOpen.cpp
	g++ -c camOpen.cpp

camOpen: camOpen.o
	g++ -o camOpen camOpen.o

clean:
	rm -f *.o
