obj-m:=module1.o char.o
KDIR := /lib/modules/$(shell uname -r)/build

default: main_char
	$(MAKE) -C $(KDIR) SUBDIRS=$(shell pwd) modules

main_char:
	gcc -Wall -o main_char main_char.c -lrt

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c
