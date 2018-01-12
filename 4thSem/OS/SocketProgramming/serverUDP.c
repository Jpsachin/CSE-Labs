// Server program for communication using socket programming using UDP 

// Reference
// http://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf
// https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.2.0/com.ibm.zos.v2r2.halc001/socket_parm.htm
// https://stackoverflow.com/questions/16508685/understanding-inaddr-any-for-socket-programming
// https://cboard.cprogramming.com/networking-device-communication/71964-udp-client-needs-bind.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header file for socket related system calls
#include <sys/socket.h>

// header file for constants and structures needed for internet domain addresses
#include <netinet/in.h>

#define DEFAULT_PROTOCOL 0

int socketDescriptorServer;
int socketAfterAcceptDescriptor;
char msg[300];
char resBuffer[300];
struct sockaddr_in serverAddr;

int main(){


	// create socket for communication for the server with IPv4, UDP type of socket, UDP protocol
	if ((socketDescriptorServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        printf("\n\n=>=> Socket creation error \n");
        return -1;
    }

    // fill server address structure
    serverAddr.sin_family = AF_INET;
    // use a random port preferably not in use
    // htons(): converts host byte order to network byte order.
    serverAddr.sin_port = htons(5100);
    // specify server address 0.0.0.0
    // used to bind socket to any ip address alloted to the system
    serverAddr.sin_addr.s_addr = INADDR_ANY;


    // bind to server socket to address passing socketDescriptorServer, server address structure, size
    if (bind(socketDescriptorServer, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("\n\n=>=> Unable to bind\n");
        return -1;
    }


    // keep waiting for connections even after ending one connection
    while(1){
    
        // client's socket address
        struct sockaddr_in clientAddr;

        // varible for storing clients socket struct size
        int clientAddrLength = sizeof(clientAddr);
            
        // end connection with current client
        int done = 1;

        // respond to request
        while(done){

            // wait for request passing socketDescriptorServer, buffer to store msg into, size, special flag (usually 0), with sockaddr_in struct for storing socket information about client's socket, pointer to store size of clients socket struct
            int count = recvfrom(socketDescriptorServer, resBuffer, sizeof(resBuffer), 0, (struct sockaddr *) &clientAddr, &clientAddrLength);
            printf("%d", count);
            if(count > 0){
            		printf("\n\n=>=> Response from Client: %s", resBuffer);

            		// get message
                    printf("\n\nEnter message to send to Client: ");
                    getchar();
                    gets(msg);
                    

                // send response to client passing clientSocket, message, size, special flag (usually 0), with socket address of client, and size
                if (sendto(socketDescriptorServer, msg, sizeof(msg), 0, (struct sockaddr *) &clientAddr, sizeof(clientAddr)) == -1){
                    printf("\n\n=>=> Message not sent \n");
                }

                printf("Enter 0 to end connection: ");
                scanf("%d", &done);
            }
                
        }
    }

    // RETUEN:: 0 : closes the connection, free up the port used by the socket
    //		   -1 : unsuccessful

    close(socketDescriptorServer);


	return 0;
}
