obj-m:=module1.o char.o
KDIR := /lib/modules/$(shell uname -r)/build

default: clean main_char writer reader
	$(MAKE) -C $(KDIR) SUBDIRS=$(shell pwd) modules

main_char:
	gcc -Wall -o main_char main_char.c

writer:
	gcc -Wall -o writer writer.c

reader:
	gcc -Wall -o reader reader.c

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c main_char writer reader
