FROM ubuntu:22.04

COPY ./ctf.xinetd /etc/xinetd.d/ctf

RUN sed -i s/archive.ubuntu.com/mirrors.aliyun.com/g /etc/apt/sources.list && \
    sed -i s/security.ubuntu.com/mirrors.aliyun.com/g /etc/apt/sources.list && \
    apt-get update && apt-get -y dist-upgrade

RUN apt-get install -y xinetd build-essential openssl libssl-dev autoconf automake libtool patchelf&& \
    useradd -m ctf && \
    echo 'ctf - nproc 1500' >>/etc/security/limits.conf

CMD exec /bin/bash -c "chown root:ctf /pwn/pwn && chmod 750 /pwn/pwn && echo $FLAG > /flag && export FLAG=not_flag && FLAG=not_flag && /etc/init.d/xinetd start; trap : TERM INT; sleep infinity & wait"

EXPOSE 10000
