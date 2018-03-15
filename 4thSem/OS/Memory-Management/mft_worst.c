#include<stdio.h>

int n;
int b;

// block information
int blockSize[1000];
int occupied[1000];

// process information
int processSize[1000];
int allocBlock[1000];

// free space available at any time
int freeSpace = 0;    
// no of processes allocated
int count = 0;


void Mft();
void CalFreeSpaceAndInit();
void AllocNewProcess(int); 


int main() {

    // input 
    printf("Enter No of Processes: ");
    scanf("%d", &n);
    
    printf("Enter No of Blocks: ");
    scanf("%d", &b);
    
    printf("Enter block sizes:\n");
    int i;
    for (i = 0; i < b; i++) {
        scanf("%d", &blockSize[i]); 
    }
    
    printf("Enter process sizes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processSize[i]); 
    }
    
    // MVT
    CalFreeSpaceAndInit();
    Mft();
    
    
    // enter new process
    int c;
    x:
    printf("Do you want to continue: ");
    scanf("%d", &c);
  
    if (c == 1){
        n++;
        printf("Enter process size: \n");
        scanf("%d", &processSize[n - 1]);
        printf("\t\t");
        allocBlock[n - 1] = -1;
        AllocNewProcess(n - 1);  
        
        goto x;      
    } 
    
    

    return 0;
}

/**
 *  Calulate Free Space before starting allocation
 *  Initialize allocBlock array to -1 indicating which block a processes is allocated
 */
void CalFreeSpaceAndInit() {
    
    int i;
    for (i = 0; i < b; i++) {
        freeSpace += blockSize[i];
    } 
    
    for (i = 0; i < n; i++) {
        allocBlock[i] = -1;
    }
}


/**
 * Multiprogramming with Fixed Tasks with First Fit
 */
void Mft() {

    printf("Process\t\t\tBlock\t\tFragmentation\n");
    
    // move through each process request
    int i;
    for (i = 0; i < n; i++) {
    
        printf("%d\t\t\t", i);
        
        AllocNewProcess(i);
 
    }
  
}

void AllocNewProcess(int i) {

    int j;
    
    // check if all blocks are occupied
    if (count == b) {
            
            // PID of process to be removed
            int pid;
            printf("\nFull!, Enter which process to swap: ");
            scanf("%d", &pid);     
            
            // free that block occupied by the process
            occupied[allocBlock[pid]] = 0;
            freeSpace += blockSize[allocBlock[pid]];
            
            printf("%d removed from %d block\n", pid, allocBlock[pid]);
            
            // remove process 
            allocBlock[pid] = -1;
            count--;
            
            printf("%d\t\t\t", i);
    }
    
    int allocPos = -1;
        
    // move through blocks
    for (j = 0; j < b; j++) {
        // skip blocks for which processes are allocated       
        if (occupied[j] != 1) {
            
            // compare sizes    
            if (blockSize[j] >= processSize[i]) {
                // find block with largest size
                if (allocPos == -1)
                    allocPos = j;
                else if (blockSize[allocPos] < blockSize[j])
                    allocPos = j;                      
            }        
        }         
    }
    // check if worst fit block
    if (j == b && allocPos != -1) {
        // allocate current process to this block    
        allocBlock[i] = allocPos;
                    
        printf("%d\t\t\t", allocPos);
        printf("%d\t\t\t\n", blockSize[allocPos] - processSize[i]); 
                    
        occupied[allocPos] = 1;
        freeSpace -= blockSize[allocPos];    
        count++;
        return;     
    }
    
    // partition not found    
    if (j == b && allocPos == -1) {
       
        if (freeSpace >= processSize[i]) {
            printf("Not possible\t\tExternal:%d\n", freeSpace);
        }
        else {
            printf("Memory not sufficient\n");
        }
        
    }
    
    //for (j = 0; j < b; j++) {
    //    printf("%d ", occupied[j]);
    //}
    //printf("\n");
            
}

