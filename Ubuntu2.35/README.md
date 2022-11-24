# Ubuntu2.35-pwnbase
> 适用glibc2.35以下所有版本elf程序,内置patchelf，可自行更换libc，不必构建多个pwnbase环境
## libc版本
GNU C Library (Ubuntu GLIBC 2.35-0ubuntu3.1) stable release version 2.35.
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 11.2.0.
libc ABIs: UNIQUE IFUNC ABSOLUTE
For bug reporting instructions, please see:
<https://bugs.launchpad.net/ubuntu/+source/glibc/+bugs>.
## 使用方式
```shell
cd ~
mkdir pwn
cd pwn
```
然后在pwn目录下新建Dockfile，如下
```dockerfile
FROM loora1n/ubuntu2.35
COPY pwn /pwn/pwn
COPY ld-2.32.so /pwn/ld-2.32.so
COPY libc-2.32.so /pwn/libc-2.32.so
RUN chmod +x /pwn/ld-2.32.so && \
    patchelf --set-interpreter /pwn/ld-2.32.so /pwn/pwn && \
    patchelf --replace-needed libc.so.6 /pwn/libc-2.32.so /pwn/pwn   
```
把elf, libc, ld 文件都放入你新建的pwn目录,可执行程序命名为pwn，然后根据情况更改dockerfile构建你的dockerfile镜像即可

## 更多详细内容请见博客
[适用多版本libc的pwn-base](https://loora1n.github.io/2022/10/28/%E9%80%82%E7%94%A8%E5%A4%9A%E7%89%88%E6%9C%AClibc%E7%9A%84pwn-base/)
