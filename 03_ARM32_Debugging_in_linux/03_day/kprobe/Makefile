obj-m = kretprobe_example.o

PWD=${shell pwd}

default:
	make -C /root/linux   M=$(PWD)  modules

clean:
	make -C /root/linux   M=$(PWD)  clean

install:
	scp  $(patsubst %.o,%.ko,$(obj-m)) root@192.168.137.100:
