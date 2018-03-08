#include<stdio.h>

// process
typedef struct process {
    int size;
    int base;
    int end;
    int status;
} process [1000];

// total memory size
int memorySize;

// no of processes
int n;

int count = 0;

void Mvt();
void AllocNewProcess(int);

int main() {

    // input
    printf("Enter memory size: ");
    scanf("%d", &memorySize);
    
    printf("Enter No of Processes: ");
    scanf("%d", &n);
    
    int i
    for (i = 0; i < n; i++) {
        
        scanf("%d", &process[i].size);
        
        process[i].base = -1;
        process[i].end = -1;  
        process[i].status = 0;
    }
    
    Mvt();
    
    
    return 0;
}


void Mvt() {

    int i;
    for (int i = 0; i < n; i++) {       
        AllocNewProcess(i);  
    }
}


void AllocNewProcess(int i) {
    
    if (count == 0) {
        process[i].status = 1;
        process[i].base = 0;
        process[i].end = process[i].size;
        return;   
    }
    
    int j;
    
    int countAlloc = 0;
    int prev = -1;
    
    for (j = 0; j < n; j++) {
    
        if (process[j].alloc == 1) {
            countAlloc++;
            if (countAlloc == 1) {

                if (process[j].base != 0) {
                    
                    if (process[j].base >= process[i].size) {
                        
                        process[i].status = 1;
                        process[i].base = 0;
                        process[i].end = process[i].size;
                         
                        return;       
                    }        
                }

            }
            else {
            
                if (process[prev].end != process[j].size) {
                    
                    if (process[j].size - process[prev].end >= process[i].size) {
                        
                        process[i].status = 1;
                        process[i].base = 0;
                        process[i].end = process[i].size;
                         
                        return;       
                    }    
                   
                
                }
            
                
                
                        
                    
            } 
            
            
            prev = j;
        }
        
        
    }

}




