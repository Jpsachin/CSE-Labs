#include <stdio.h>
#include <math.h>
#define N 100000

int diskCapacity;
int blockCapacity;
int noOfBlocks;

int blocks[N];
int freeblocks;

// directory
typedef struct {
    int valid;
	int fileId;
	int start;
	int size;
} directory;


// file
typedef struct {
	int fileId;
	int size;
} file;

// file queue
file queue[N];
int front = 0, rear = -1;

// directories
directory dir[N];
int directoryCursor = -1;

// function declarations
int addFile(file f, int cat);
void removeFile(int id);


void main() {
    
    // inputs
	printf("Enter Disk Capacity : ");
	scanf("%d", &diskCapacity);

	printf("Enter Block Capacity : ");
    scanf("%d", &blockCapacity);
    
    noOfBlocks = diskCapacity / blockCapacity; 
	for (int i = 0; i < noOfBlocks; i++) {
        blocks[i] = -1;
    }
    freeblocks = noOfBlocks;
    
    while (1) {
        
        int ch;
        printf("\nEnter your choice \n1. Add File\n2. Remove File\n3. Display\n");
	    scanf("%d", &ch);
        
        int id, size;
        file f;
        
        switch (ch) {
            case 1: 
                // input file
			    printf("\nEnter file Id: ");
			    scanf("%d", &id);

			    printf("Enter file size: ");
                scanf("%d", &size);
                
                // create file
                file f;
                f.fileId = id;
                f.size = size;
                
                // add file 
                addFile(f, 0);
                break;
            case 2: 
                printf("\nEnter file Id: ");
			    scanf("%d", &id);
			    
                removeFile(id); 
                break;
            case 3: 
                printf("\nDirectory: \n");
                printf("Id\t\tStart\t\tLength\n");
                for (int i = 0; i <= directoryCursor; i++) {
                    if (dir[i].valid == 1) {
                        printf("%d\t\t%d\t\t%d\n", dir[i].fileId, dir[i].start, dir[i].size);
                    }
                }            
        }
    }   
}


/**
 * add file to disk
 */
int addFile(file f, int cat) {
    // number of blocks for the file
    int noOfFileBlocks = f.size / blockCapacity;
    
    if (freeblocks >= noOfFileBlocks) {
        int i;  
        for (i = 0; i < noOfBlocks; i++) {
            if (blocks[i] == -1) {
                // check contiguous space
                int j;
                for (j = i; j < i + noOfFileBlocks && j < noOfBlocks; j++) {
                    if (blocks[j] == 0) {
                        break;  
                    }
                }
                // check contiguous space is free
                if (j == i + noOfFileBlocks) {
                    // fill blocks
                    for (j = i; j < i + noOfFileBlocks && j < noOfBlocks; j++) {
                        blocks[j] = 0;
                    }
                    // add file to the directory
                    dir[++directoryCursor].valid = 1;
                    dir[directoryCursor].fileId = f.fileId;
                    dir[directoryCursor].start = i;
                    dir[directoryCursor].size = noOfFileBlocks;
                    freeblocks -= noOfFileBlocks;
                    printf("File allocated\n");
                    return 1;
                }
            }
        }
    }
    
    if (cat == 0) {   
        // add to file queue

            printf("File not allocated\n");
            queue[++rear] = f; 
            return 1;   
        
    }
    
    return -1;
}


/**
 * Remove a file and add another from queue
 */
void removeFile(int id) {
    
    // invalidate directory entry and free blocks
    for (int i = 0; i <= directoryCursor; i++) {
        if (dir[i].fileId == id) {
        
            for (int j = dir[i].start; j <= dir[i].start + dir[i].size; j++) {
                blocks[j] = -1;
            }
            freeblocks += dir[i].size;
            dir[i].valid = 0; 
        }
    }
    
    // check queue for file allocation
    for (int i = front; i <= rear; i++) {
        printf("Check Queue: file %d\n", queue[i].fileId); 
        int status = addFile(queue[front], 1);
        
        if (status == 1) {
            for (int j = i; j <= rear; j++) {
                queue[i] = queue[i+1]; 
            }
            rear--;
            return;
        }       
    }
}






