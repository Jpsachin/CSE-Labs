#include <stdio.h>

int logicalMemSize;
int physicalMemSize;
int pageSize;
int entries;
int noOfFrames;
int pageTable[1000] = {0};

void main() {
    
    // input
    printf("Enter logical memory size: ");
    scanf("%d", &logicalMemSize);
    printf("Enter physical memory size: ");
    scanf("%d", &physicalMemSize);
    printf("Enter page size: ");
    scanf("%d", &pageSize);
    
    // printf("Enter number of enteries: ");
    // scanf("%d", &entries); 
    
    entries = logicalMemSize / pageSize;
    noOfFrames = physicalMemSize / pageSize;
    // get initial page table layout
    int i;
    int q;
    for (i = 0; i < entries; i++) {
        printf("Page no %d ==> Frame No: ", i);
        scanf("%d", &q);
        int j;
        for (j = 0; j < i; j++) {
            if (pageTable[j] == q && q != -1) {
                printf("Entry exists!\n");
                i--;
                break;
            }
        }
        if (j != i) {continue;}
        if (q > noOfFrames - 1) {
            printf("Invalid input!");
            i--;
            continue;
        }
        pageTable[i] = q;
    }
    
    // Queries of logical addresses

    while(1) {
        printf("Enter logical address: ");
        scanf("%d", &q);
        
        int pageNumber = q / pageSize;
        int offset = q % pageSize;
        printf("Page no: %d", pageNumber);
        
        int frameNumber;
        
        if (pageTable[pageNumber] == -1) {
            printf("Page Fault\n");
            continue;
        }
        else {  
            frameNumber = pageTable[pageNumber]; 
            printf("Frame number: %d", frameNumber);
        }
    
        printf("Physical Address: %d, offset: %d", frameNumber * pageSize, offset);    
    }
}

