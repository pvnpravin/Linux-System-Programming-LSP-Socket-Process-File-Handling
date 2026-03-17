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
//  1st Argument

////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int ServerSocket = 0;
    int ClientSocket = 0;
    int Port = 0;
    int iRet = 0;

    

    String socketaddr_in ServerAddr;
    String socketaddr_in ClientAddr;

    socklee_t Addrlen = sizeof(ClientAddr);

    if((argc < 2) || (argc > 2))
    {
        printf("Unable to proceed as invalid number of arguments are provided\n");
        printf("Please provide the following arguments : \n");
        printf("IP Address\nPort Number\nTargeted File\nNew File Name\n");

        return -1;
    }

    Port = atoi(argv[1]);

    ////////////////////////////////////////////////////////////
    //  Step 1 : Create TCP Socket
    ////////////////////////////////////////////////////////////

        ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

        if (ServerSocket < 0)
        {
            printf("Unable to create socket\n");
            return -1;  
        }


    ////////////////////////////////////////////////////////////
    //  Step 2 : Bind the socket with Ip and Port
    ////////////////////////////////////////////////////////////

        memset(&ServerAddr, 0, sizeof(ServerAddr));

        // Initialize the members of sockaddr_in structure
        ServerAddr.sin_family = AF_INET;
        ServerAddr.sin_port = htons(Port);
        serverAddr.sin_addr.s_addr = INADDR_ANY;

        iRet = bind(ServerSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

        if (iRer == -1)
        {
            printf("Unable to bind \n");

            close(ServerSocket);
            return -1;  
        }
    
    ////////////////////////////////////////////////////////////
    //  Step 3 : Listen for the client connections
    ////////////////////////////////////////////////////////////

        iRet = listen(ServerSocket, 11);

        if(iRet == -1)
        {
            printf("Unable to listen for client Request/connections\n");

            close(ServerSocket);
            return -1;  
        }

        printf("Server is Running on port : %d\n", Port);

    ////////////////////////////////////////////////////////////
    //  Loop which accepts the client connection continuously
    ////////////////////////////////////////////////////////////

    // loop to accept the client connection
    while (1)
    {
        ////////////////////////////////////////////////////////////
        //  Step 4 : Listen for the client connections
        ////////////////////////////////////////////////////////////
        ClientSocket = accept(ServerSocket, (struct sockaddr *)&ClientAddr, &Addrlen);

        printf("Server is waiting for the client request\n");
        if (ClientSocket < 0)
        {
            printf("Unable to accept the client connection\n");
            continue;  // used to skip the current iteration and move to next iteration of the loop
        }

        printf("Client gets Connected : %s\n", )
    }   // End of while loop

       
    return 0;
}   // End of main