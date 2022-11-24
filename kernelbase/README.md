# Kernel-pwnbase使用方法
> 详细说明：[Kernel-pwnbase详解](https://loora1n.github.io/2022/10/18/Kernel-pwnbase%E8%AF%A6%E8%A7%A3/)
1. 将bzImage, rootfs, boot.sh等文件放入file文件夹
2. docker build -t id/name .
3. docker push id/name
4. CTFD 上题时需更改**Docker Container Memory Limit**这一栏>=256m，不然qemu可能会kill
5. helloworld程序是用来初始化输入输出，以及启动boot.sh
6. 这个base里已经放置一个基于CVE-2022-0847的本地提权题目，可以用来测试base，直接替换对应文件即可
