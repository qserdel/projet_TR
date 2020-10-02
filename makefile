all: gpio pwm camOpen clean

gpio: gpio.cpp
	g++ -o gpio gpio.cpp -lwiringPi

pwm: pwm.cpp
	g++ -o pwm pwm.cpp -lwiringPi -lpthread

camOpen: camOpen.cpp
	g++ -o camOpen camOpen.cpp -I /usr/local/include -L /usr/local/lib -lopencv_core -lopencv_highgui

clean:
	rm -f *.o
