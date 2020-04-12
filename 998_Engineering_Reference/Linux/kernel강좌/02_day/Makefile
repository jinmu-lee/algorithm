obj-m = module_param.o

KDIR = /root/tegra
PWD  = $(shell pwd)

default :
	$(MAKE) -C $(KDIR)  SUBDIRS=$(PWD) modules

clean :
	$(MAKE) -C $(KDIR)  SUBDIRS=$(PWD) clean
