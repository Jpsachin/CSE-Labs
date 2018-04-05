#include <stdio.h>
#include <limits.h>

int noOfFrames;
int memory[1000] = {0};
int requestTime[1000] = {0};
int occupied = 0;

int noOfPageFaults = 0;

int queryPage(int, int);

void main() {
    
    // input
    printf("Enter number of frames in main memory: ");
    scanf("%d", &noOfFrames);
    
    // page no queries
    int q;
    int done = 1;
    int time = 0;
    while(done) {
    
        printf("Enter page number: ");
        scanf("%d", &q);
        time++;
        
        // queryPage
        printf("%s\n", queryPage(q, time)?"Found":"Added");
    
        printf("Do you want to continue(1/0)?: ");
        scanf("%d", &done);
    }
    
    printf("Number of page faults: %d\n", noOfPageFaults);        
}

// LRU 
int queryPage(int pageNo, int time) {

    // check if the page is already present
    int i;
    for (i = 0; i < occupied; i++) {
        if (memory[i] == pageNo) {
            requestTime[i] = time;
            return 1;
        }
    }

    // add to memory
    if (occupied < noOfFrames) {
        memory[occupied] = pageNo;
        requestTime[occupied++] = time;
        noOfPageFaults++;   
    }
    else if (occupied == noOfFrames) {
        // get lru page
        int j;
        int minTime = INT_MAX;
        int index = 0;
        for (j = 0; j < noOfFrames; j++) {
            if (minTime > requestTime[j]) {
                minTime = requestTime[j];
                index = j;
            }
        }
        // replace it with current request
        memory[index] = pageNo;
        requestTime[index] = time;
        noOfPageFaults++;
    }
 
    
    // display memory layout
    printf("FRAME NO\t\tPAGE NO\t\t\tTIME\n");
    for (i = 0; i < noOfFrames; i++) {
        printf("%d\t\t\t%d\t\t\t%d\n", i, memory[i], requestTime[i]);
    }
    
    return 0;
}

