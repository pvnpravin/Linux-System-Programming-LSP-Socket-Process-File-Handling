// Client Application which accepts the file name from user and sends the file to server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet>
#include<stdbool.h>


////////////////////////////////////////////////////////////
//  Command Line Arguments Application
//  1st Argument    : IP Address
//  2nd Argument    : Port Number
//  3rd Argument    : Target File
//  4th Argument    : New File Name
//  
// ./client     127.0.0.1   9000        Demo.txt    A.txt
// argv[0]      argv[1]     argv[2]     argv[3]     argv[4]

// argc = 5
////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int Sock = 0;                       // argv[2] : Port Number
    int Port = 0;
    int iRet = 0;

    char *ip = NULL;                    // argv[1] : IP Address
    char *FileName = NULL;              // argv[3] : Target File
    char *OutFileName = NULL;           // argv[4] : New File Name

    struct sockaddr_in ServerAddr;   
    

    if((argc < 5) || (argc > 5))
    {
        printf("Unable to proceed as invalid number of arguments are provided\n");
        printf("Please provide the following arguments : \n");
        printf("1st Argument    : IP Address\n");
        printf("2nd Argument    : Port Number\n");
        printf("3rd Argument    : Target File\n");
        printf("4th Argument    : New File Name\n");
        
        return -1;
    }

    // Store command line arguments in respective variables for further processing
    ip = argv[1];
    Port = atoi(argv[2]);
    FileName = argv[3];
    OutFileName = argv[4];

    /////////////////////////////////////////////////////////////////////////
    //  Step 1 : Create TCP Socket
    /////////////////////////////////////////////////////////////////////////

        Sock = socket(AF_INET, SOCK_STREAM, 0);

        if (Sock < 0)
        {
            printf("Unable to create client socket\n");
            return -1;  
        }
    /////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////
    //  Step 2 : Connect to the server
    /////////////////////////////////////////////////////////////////////////
        memset(&ServerAddr, 0, sizeof(ServerAddr));

        // Initialize the members of sockaddr_in structure
        ServerAddr.sin_family = AF_INET;
        ServerAddr.sin_port = htons(Port);
        inet_pton(AF_INET, ip, &ServerAddr.sin_addr);

        // Convert the IP Addredd into Binary format
        inet_pton(AF_INET, ip, &ServerAddr.sin_addr);

       iRet = connect(Sock, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

        if (iRet == -1)
        {
            printf("Unable to connect with server\n");
            close(Sock);
            return -1;  
        }

        // Sending the file name to server
        write(Sock, FileName, strlen(FileName));



    return 0;
}   // End of main