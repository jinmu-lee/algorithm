obj-m := devtest.o

KERNELDIR := ~/work/linux
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	arm-linux-gnueabihf-gcc -Wall -o apptest apptest.c
	sudo cp devtest.ko apptest /nfsroot

clean:
	rm -f *.o *.ko *.mod.c modules.order Module.symvers
	rm -f .*.*.cmd .*.*.*.cmd
	rm -rf .tmp_versions
	rm -f apptest
