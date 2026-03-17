#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    if (iRet == 0)
    {
        printf("Child Process is running with PID : %d\n", getpid());
    }
    else
    {
        printf("Parent Process is running with PID : %d\n", getpid());
        printf("Child Process is created with PID : %d\n", iRet);
    }
    

    return 0;
}