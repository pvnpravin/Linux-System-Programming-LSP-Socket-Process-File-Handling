#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("NUmber of cmmd line argument are : %d\n", argc);

    if (argc != 5)
    {
        printf("Invalid number of command line arguments\n");
        printf("Please provide : \n");
        printf("IP Address\nPort Number\nTargeted File\nNew File Name\n");
    }
    

    printf("Executable Name : %s", argv[0]);
    printf("IP Address : %s\n", argv[1]);
    printf("Port Number : %s\n", argv[2]);
    printf("Targeted File : %s\n", argv[3]);
    printf("New File Name : %s", argv[4]);

    return 0;
}