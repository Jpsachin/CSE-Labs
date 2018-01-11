// Server program for communication using socket programming

// Reference
// http://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf
// https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.2.0/com.ibm.zos.v2r2.halc001/socket_parm.htm
// https://stackoverflow.com/questions/16508685/understanding-inaddr-any-for-socket-programming

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


	// create socket for communication for the server with IPv4, TCP type of socket, TCP protocol
	if ((socketDescriptorServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("\n\n=>=> Socket creation error \n");
        return -1;
    }

    // fill server address structure
    serverAddr.sin_family = AF_INET;
    // use a random port preferably not in use
    // htons(): converts host byte order to network byte order.
    //  big-endian byte order is also referred to as network byte order.
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

        // listen for connection passing socketDescriptorServer and  backlog (the maximum length to which the queue of pending connections for socketDescriptorServer may grow)
        if (listen(socketDescriptorServer, 3) == -1){
            printf("\n\n=>=> Failed to listen to client\n\n");
        }
        else {

            // end connection with current client
            int done = 1;

            // get client
            // accept first socket in the queue of pending connections passing socketDescriptorServer, place to store information about client (leaving NULL for convenience)
            // returns: new socket file descriptor, the socket file also contains information about client socket struct 
            //          -1 error
            int newSocket = accept(socketDescriptorServer, NULL, NULL);

            // respond to request
            while(done){

                if(newSocket != -1){

                    // wait for request passing clientSocket, buffer to store msg into, size, special flag (usually 0)
            		int count = recv(newSocket, resBuffer, sizeof(resBuffer), 0);

            		if(count > 0){
            		    printf("\n\n=>=> Response from Client: %s", resBuffer);

            		    // get message
                    	printf("\n\nEnter message to send to Client: ");
                    	getchar();
                    	gets(msg);

                    	// send response to client passing clientSocket, message, size, special flag (usually 0)
                    	if (send(newSocket, msg, sizeof(msg), 0) == -1){
                    		printf("\n\n=>=> Message not sent \n");
                    	}

                    	printf("Enter 0 to end connection: ");
                    	scanf("%d", &done);
            		}
                }
            }

            // closed connection with this client
            close(newSocket);

        }

    }

    // RETUEN:: 0 : closes the connection, free up the port used by the socket
    //		   -1 : unsuccessful

    close(socketDescriptorServer);


	return 0;
}
