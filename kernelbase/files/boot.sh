#!/bin/sh

qemu-system-x86_64  \
-m 128M \
-kernel /home/ctf/bzImage \
-initrd /home/ctf/rootfs.cpio \
-monitor /dev/null \
-cpu kvm64,+smep,+smap \
-append "root=/dev/ram console=ttyS0 oops=panic quiet panic=1 kaslr noapic" \
-nographic \
-no-reboot 
