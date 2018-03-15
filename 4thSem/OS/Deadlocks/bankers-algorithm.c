#include <stdio.h>
#include <stdlib.h>

#define N 5

int max_resources[N][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};;
int alloc_resources[N][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};;
int need_resources[N][3];
int avail_resources[3] = {3, 3, 2};
int completed[N] = {0};

void CalcNeededResources() {
    int i;
    for (i = 0; i < N; i++) {
        need_resources[i][0] = max_resources[i][0] - alloc_resources[i][0];
        need_resources[i][1] = max_resources[i][1] - alloc_resources[i][1];
        need_resources[i][2] = max_resources[i][2] - alloc_resources[i][2];
    }
}

void CheckSafeState() {
    
    int process_found = 0;
    int completed_processes = 0;
    int safe_order[N];
    
    while (completed_processes < N) {
        
        // look through all processes
        int i;
        for (i = 0; i < N; i++) {
            // check only processes which are not complete
            if (completed[i] != 1) {
                // compare needed resources with available ones
                if (need_resources[i][0] <= avail_resources[0] && need_resources[i][1] <= avail_resources[1] && need_resources[i][2] <= avail_resources[2]) {
                    // execute the process and free its resources
                    process_found = 1;
                    avail_resources[0] += alloc_resources[i][0];
                    avail_resources[1] += alloc_resources[i][1];
                    avail_resources[2] += alloc_resources[i][2];
                    // printf("\n\n%d %d %d\n\n", avail_resources[0], avail_resources[1], avail_resources[2]);
                    safe_order[completed_processes] = i;
                    completed_processes++;
                    
                    completed[i] = 1;

                    break;
                }    
            }
            
        }
        
        if (process_found == 0) {
            break;
        }
        else {
            process_found = 0;
        }
    }
    
    if (completed_processes != N) {  
        printf("\nNot in safe state!\n\n");
    }
    else {
        printf("\nSafe order: \n");
        int i;
        for (i = 0; i < N; i++) {
            printf("%d ", safe_order[i]);
        }
        printf("\n");
    }
    
    
}



int main() {
    
    CalcNeededResources();
    
    // process first request
    int pid, req_resources[3];
    
    printf("Enter pid: ");
    scanf("%d", &pid);
    
    printf("Enter resources requested(A B C): ");
    scanf("%d %d %d", &req_resources[0], &req_resources[1], &req_resources[2]);
    
    if (req_resources[0] > avail_resources[0] || req_resources[1] > avail_resources[1] || req_resources[2] > avail_resources[2]) {
        printf("\nIncorrect request!\n\n");
        exit(0);    
        
    }

    if (req_resources[0] > need_resources[pid][0] || req_resources[1] > need_resources[pid][1] || req_resources[2] > need_resources[pid][2]) {
        printf("\nIncorrect request!\n\n");
        exit(0);
    }
    
    // update the processes reources
    alloc_resources[pid][0] += req_resources[0];
    alloc_resources[pid][1] += req_resources[1];
    alloc_resources[pid][2] += req_resources[2];
    
    CalcNeededResources();
    
    // update available resources 
    avail_resources[0] -= req_resources[0];
    avail_resources[1] -= req_resources[1];
    avail_resources[2] -= req_resources[2];
    
    
    
    // check safe state after giving resources to the requested process
    CheckSafeState();
    
    return 0;
}