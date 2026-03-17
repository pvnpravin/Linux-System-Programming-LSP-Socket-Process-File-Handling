#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("PID of Running Process : %d\n", getpid());

    printf("PPID of Parent Process : %d\n", getppid());

    return 0;
}