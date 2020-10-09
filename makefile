obj-m:=driver_interruption.o
KDIR := /lib/modules/$(shell uname -r)/build

all: gpio pwm camOpen i2c drivers

drivers: main_char
	$(MAKE) -C $(KDIR) SUBDIRS=$(shell pwd) modules

gpio: gpio.cpp
	g++ -o gpio gpio.cpp -lwiringPi

pwm: pwm.cpp
	g++ -o pwm pwm.cpp -lwiringPi -lpthread

camOpen: camOpen.cpp
	g++ -o camOpen camOpen.cpp -I /usr/local/include -L /usr/local/lib -lopencv_core -lopencv_highgui

i2c: i2c.cpp
	g++ -o i2c i2c.cpp -lwiringPi


clean:
	rm -f pwm gpio camOpen i2c *.o *.ko
