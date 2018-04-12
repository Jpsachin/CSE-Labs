#include <stdio.h>
#include <math.h>
#define N 100000

int diskCapacity;
int blockCapacity;
int noOfBlocks;

// block
typedef struct {
    int valid;
    int next;
} block;

block blocks[N];
int freeBlocks;

// directory
typedef struct {
    int valid;
	int fileId;
	int start;
	int end;
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
        blocks[i].valid = -1;
        blocks[i].next = -1;
    }
    freeBlocks = noOfBlocks;
    
    while (1) {
        
        int ch;
        printf("\nEnter your choice \n1. Add File\n2. Remove File\n3. Search\n");
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
                printf("Id\t\tStart\t\tEnd\n");
                for (int i = 0; i <= directoryCursor; i++) {
                    if (dir[i].valid == 1) {
                        printf("%d\t\t%d\t\t%d\n", dir[i].fileId, dir[i].start, dir[i].end);
                    }
                }
                
                printf("\nEnter file Id: ");
			    scanf("%d", &id);
			    
                for (int i = 0; i <= directoryCursor; i++) {
                    if (dir[i].fileId == id) {
                        // move through the blocks and free them
                        int done = 1;
                        int curr = dir[i].start;
                        while (done == 1) {
                            printf("%d ", curr);
                            if (curr == dir[i].end) {
                                done = 0;
                            }
                            curr = blocks[curr].next;   
                        }
                    }
                } 
                printf("\n");           
        }
    }   
}


/**
 * add file to disk
 */
int addFile(file f, int cat) {
    // number of blocks for the file
    int noOfFileBlocks = ceil((float)(f.size*8)/(float) ((float)(blockCapacity * 8) - floor(log2(blockCapacity))));
    int n = noOfFileBlocks;
    printf("Number: %d\n", noOfFileBlocks);
    // check is free blocks are available
    if (freeBlocks >= noOfFileBlocks) {
        // link available blocks
        int i; 
        int start = -1;
        int prev = -1; 
        for (i = 0; i < noOfBlocks; i++) {
            if (n >= 1) {
                if (blocks[i].valid == -1) {
                    // first block alllocated
                    if (start == -1) {
                        blocks[i].valid = 0;
                        start = i;
                        prev = i;
                    }
                    // chain the rest to previous
                    else {
                        blocks[i].valid = 0;
                        blocks[prev].next = i;
                        prev = i;
                    }
                    n--;
                }
            }
            else {
                break;
            }
        }
        
        // make directory entry
        dir[++directoryCursor].valid = 1;
        dir[directoryCursor].fileId = f.fileId;
        dir[directoryCursor].start = start;
        dir[directoryCursor].end = prev;
        
        // decrease free blocks count
        freeBlocks -= noOfFileBlocks;
        printf("File allocated\n");
        
        return 1;
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
            // move through the blocks and free them
            int done = 1;
            int start = dir[i].start;
            int end = dir[i].end;
            int curr = dir[i].start;
            while (done == 1) {
                blocks[curr].valid = -1;
                if (curr == dir[i].end) {
                    done = 0;
                }
                curr = blocks[curr].next;   
            }
        
            dir[i].valid = 0; 
            freeBlocks += end - start +1;
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






