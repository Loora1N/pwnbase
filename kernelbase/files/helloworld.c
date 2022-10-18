#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void init()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
}

int main()
{
    init();   
    signal(SIGCHLD, SIG_DFL);
    system("/home/ctf/boot.sh");
}