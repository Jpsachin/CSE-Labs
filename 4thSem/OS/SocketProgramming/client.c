// Client program for communication using socket programming

// Reference
// http://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf
// https://stackoverflow.com/questions/16508685/understanding-inaddr-any-for-socket-programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// header file for socket related system calls
#include <sys/socket.h>

// header file for constants and structures needed for internet domain addresses
#include <netinet/in.h>

#define INTERNET_PROTOCOL 0

int socketDescriptorClient;
char msg[300];

int main(){


	// create socket for communication for the client with IPv4, TCP, IP types of protocols
	if ((socketDescriptorClient = socket(AF_INET, SOCK_STREAM, INTERNET_PROTOCOL)) < 0) {
        printf("\n\n=>=> Socket creation error \n");
        return -1;
    }
    
    // connect to server 
    if (connect() == -1) {
        printf("\n\n=>=> Connection to server failed \n");
        return -1;
    }
    
    while(1){
    
    	// get message 
    	printf("\nEnter message to send to Server: ");
    	gets(msg);
    	
    	// send message to server 
    	if (send() == -1){
    		printf("\n\n=>=> Message not sent \n");
    	}
    	else{
    		// wait for response
    		while()
    	}
    }
    
    // RETUEN:: 0 : closes the connection, free up the port used by the socket
    //		   -1 : unsuccessful 	 
    
    close(socketDescriptorClient);
    
    
	return 0;
}
