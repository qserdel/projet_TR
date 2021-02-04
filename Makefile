obj-m:=driver.o
KDIR := /lib/modules/$(shell uname -r)/build

all: drivers mcc pwm camOpen zeone 

drivers:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

gpio: gpio.cpp
	g++ -o gpio gpio.cpp -lwiringPi

pwm: pwm.cpp pwm.hpp
	g++ -o pwm pwm.cpp -lwiringPi -lpthread

camOpen: camOpen.cpp
	g++ -o camOpen camOpen.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

i2c: ir.cpp ir.hpp
	g++ -o ir ir.cpp -lwiringPi

mcc: mcc.cpp mcc.hpp
	g++ -o mcc mcc.cpp -lwiringPi 

zeone: Zeone.cpp mcc.hpp camOpen.hpp ir.hpp pwm.hpp
	g++ -o Zeone Zeone.cpp -lwiringPi -lpthread `pkg-config --cflags opencv` `pkg-config --libs opencv`

clean:
	rm -f pwm gpio camOpen i2c mcc zeone *.o *.ko
