all: gpio pwm camOpen clean

gpio.o: gpio.cpp
	g++ -c gpio.cpp

gpio: gpio.o
	g++ -o gpio gpio.o -lwiringPi

pwm.o: pwm.cpp
	g++ -c pwm.cpp

pwm: pwm.o
	g++ -o pwm pwm.o -lwiringPi -lpthread

camOpen.o: camOpen.cpp
	g++ -c camOpen.cpp

camOpen: camOpen.o
	g++ -o camOpen camOpen.o -I /usr/local/include -L /usr/local/lib -lopencv_core -lopencv_highgui

clean:
	rm -f *.o
