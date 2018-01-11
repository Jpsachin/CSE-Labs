// Client program for communication using socket programming

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

int socketDescriptorClient;
char msg[300];
char resBuffer[300];
struct sockaddr_in serverAddr;

int main(){


	// create socket for communication for the client with IPv4, TCP type socket, TCP protocol
	if ((socketDescriptorClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("\n\n=>=> Socket creation error \n\n");
        return -1;
    }

    // fill server address structure
    serverAddr.sin_family = AF_INET;
    // use a random port preferably not in use
    // htons(): converts host byte order to network byte order.
    //  big-endian byte order is also referred to as network byte order.
    serverAddr.sin_port = htons(5100);
    // specify server address
    // inet_addr: unsigned long value containing a suitable binary representation of the Internet address given.
    serverAddr.sin_addr.s_addr = inet_addr("<SERVERS_IP_ADDRESS>");


    // connect to server passing socketDescriptor, server address structure, size
    if (connect(socketDescriptorClient, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("\n\n=>=> Connection to server failed \n\n");
        return -1;
    }

    // request server
    while(1){

    	// get message
    	printf("\n\nEnter message to send to Server: ");
    	gets(msg);

    	// send message to server passing socketDescriptor, message, size, special flag (usually 0)
    	if (send(socketDescriptorClient, msg, sizeof(msg), 0) == -1){
    		printf("\n\n=>=> Message not sent \n");
    	}
    	else{
    		// wait for response passing socketDescriptor, buffer to store msg into, size, special flag (usually 0)
    		int count = recv(socketDescriptorClient, resBuffer, sizeof(resBuffer), 0);

    		if(count > 0){
    		    printf("\n=>=> Response from Server: %s", resBuffer);
    		}
    	}
    }


    // RETUEN:: 0 : closes the connection, free up the port used by the socket
    //		   -1 : unsuccessful
    close(socketDescriptorClient);


	return 0;
}
