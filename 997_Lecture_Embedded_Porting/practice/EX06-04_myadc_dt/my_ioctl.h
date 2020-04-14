#include <linux/ioctl.h>

#define MY_IOCTL_MAGIC 'k'

#define MY_IOCTL_CMD_SET_MAX_COUNT     _IOW(MY_IOCTL_MAGIC, 1, int)
