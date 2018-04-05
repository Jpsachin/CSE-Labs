#include <stdio.h>

int noOfFrames;
int memory[1000];
int occupied = 0;
int lastRemoved = 0;

int noOfPageFaults = 0;

int queryPage(int);

void main() {
    
    // input
    printf("Enter number of frames in main memory: ");
    scanf("%d", &noOfFrames);
    
    // page no queries
    int q;
    int done = 1;
    while(done) {
    
        printf("Enter page number: ");
        scanf("%d", &q);
        
        // queryPage
        printf("%s\n", queryPage(q)?"Found":"Added");
            
        printf("Do you want to continue(1/0)?: ");
        scanf("%d", &done);
    
    }    
    
    printf("Number of page faults: %d\n", noOfPageFaults);    
}

// FIFO 
int queryPage(int pageNo) {
  
    // check if the page is already present
    int i;
    for (i = 0; i < occupied; i++) {
        if (memory[i] == pageNo) {
            return 1;
        } 
    }
    
    // add to memory
    if (occupied < noOfFrames) {
        memory[occupied++] = pageNo;
        noOfPageFaults++;
    }
    else if (occupied == noOfFrames) {
        // fifo stratergy
        memory[lastRemoved] = pageNo;
        lastRemoved = (lastRemoved + 1) % noOfFrames; 
        noOfPageFaults++;
    }
    
    // display memory layout
    printf("FRAME NO\t\tPAGE NO\n");
    for (i = 0; i < noOfFrames; i++) {
        printf("%d\t\t\t%d\n", i, memory[i]);
    }
    
    return 0;
}

// 7 1 0 1 1 1 2 1 0 1 3 1 0 1 4 1 2 1 3 1 0 1 3 1 2 1 1 1 2 1 0 1 1 1 7 1 0 1 1

