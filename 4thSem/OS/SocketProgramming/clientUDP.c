// Client program for communication using socket programming using UDP

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

int socketDescriptorClient;
char msg[300];
char resBuffer[800];
struct sockaddr_in clientAddr;
struct sockaddr_in serverAddr;
int serverAddrLength;

int main(){


	// create socket for communication for the client with IPv4, UDP type of socket, UDP protocol
	if ((socketDescriptorClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        printf("\n\n=>=> Socket creation error \n\n");
        return -1;
    }
    
    // fill server address structure
    serverAddr.sin_family = AF_INET;
    // use a random port preferably not in use
    // htons(): converts host byte order to network byte order.
    serverAddr.sin_port = htons(5100);
    // specify server address 0.0.0.0
    // used to bind socket to any ip address alloted to the system
    serverAddr.sin_addr.s_addr = inet_addr("<SERVER_IP_ADDRESS>");
    
    

    // request server
    while(1){

		// set server socket struct size
		serverAddrLength = sizeof(serverAddr);

    	// get message
    	printf("\n\nEnter message to send to Server: ");
    	gets(msg);

    	// send message to server passing socketDescriptor, message, size, special flag (usually 0), specifying server socket address 
    	if (sendto(socketDescriptorClient, msg, sizeof(msg), 0, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1){
    		printf("\n\n=>=> Message not sent \n");
    	}
    	else{
    	    printf("\n\nMessage sent\n\n");
    		// wait for response passing socketDescriptor, buffer to store msg into, size, special flag (usually 0), in which sockaddr struct server address recieved, pointer to address where length is stored
    		int count = recvfrom(socketDescriptorClient, resBuffer, sizeof(resBuffer), 0, (struct sockaddr *) &serverAddr, &serverAddrLength);

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
