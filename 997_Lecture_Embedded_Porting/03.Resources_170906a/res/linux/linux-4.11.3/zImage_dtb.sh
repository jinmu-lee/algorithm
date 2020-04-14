#!/bin/bash

cd arch/arm/boot
cat zImage dts/exynos4412-wt4412.dtb > zImage_dtb
echo "zImage_dtb: ready in $(pwd)/dts"

cp zImage_dtb /tftpboot
echo "zImage_dtb: copied to /tftpboot"
