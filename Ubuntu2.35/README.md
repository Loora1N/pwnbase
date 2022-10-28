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
RUN chmod +x /pwn/pwn && \
    patchelf --set-interpreter /pwn/ld-2.32.so /pwn/pwn && \
    patchelf --replace-needed libc.so.6 /pwn/libc-2.32.so /pwn/pwn   
```
把elf, libc, ld 文件都放入你新建的pwn目录,可执行程序命名为pwn，然后根据情况更改dockerfile构建镜像即可
