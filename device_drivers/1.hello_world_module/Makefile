obj-m = hello_world.o
BDIR=/lib/modules/$(shell uname -r)/build
all:
	make -C $(BDIR) M=$(shell pwd) modules
clean:
	make -C $(BDIR) M=$(shell pwd) clean