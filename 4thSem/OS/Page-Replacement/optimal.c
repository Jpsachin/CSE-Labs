#include <stdio.h>
#include <limits.h>

int noOfFrames;
int memory[1000] = {0};
int futureRequestTime[1000] = {0};
int occupied = 0;
int n;
int pageQueries[1000];

int noOfPageFaults = 0;

int queryPage(int);
void fillFutureRequestTime(int);

void main() {
    
    // input
    printf("Enter number of frames in main memory: ");
    scanf("%d", &noOfFrames);
    printf("Enter no of page queries: ");
    scanf("%d", &n);
    
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &pageQueries[i]);
    }
    
    for (i = 0; i < n; i++) {
        fillFutureRequestTime(i);
        printf("%s\n", queryPage(pageQueries[i])?"Found":"Added");
    } 
    
    printf("Number of page faults: %d\n", noOfPageFaults);         
}

// optimal algorithm 
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
        // get lru page
        int j;
        int maxTime = INT_MIN;
        int index = 0;
        for (j = 0; j < noOfFrames; j++) {
            if (maxTime < futureRequestTime[j]) {
                maxTime = futureRequestTime[j];
                index = j;
            }
        }
        // replace it with current request
        memory[index] = pageNo;
        noOfPageFaults++;
    }
 
    
    // display memory layout
    printf("FRAME NO\t\tPAGE NO\t\t\tFUTURE REQUEST TIME USED FOR REPLACEMENT\n");
    for (i = 0; i < noOfFrames; i++) {
        printf("%d\t\t\t%d\t\t\t%d\n", i, memory[i], futureRequestTime[i]);
    }
    
    return 0;
}


void fillFutureRequestTime(int time) {
    int i, j;
    for (i = 0; i < noOfFrames; i++) {
        for (j = time + 1; j < n; j++) {
            if (memory[i] == pageQueries[j]) {
                futureRequestTime[i] = j;
                break;                        
            }
        }
        if (j == n) {
            futureRequestTime[i] = INT_MAX;
        }   
    }
}

// 4 11 1 3 2 7 5 1 2 1 4 2 3 2
// 4 11 0 2 1 6 4 0 1 0 3 1 2 1


// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
