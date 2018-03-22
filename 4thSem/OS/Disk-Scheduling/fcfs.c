#include<stdio.h>
#include<stdlib.h>
int curr_pos;

void main() {
    
    printf("Enter current position of head: ");
    scanf("%d", &curr_pos);
    
    int n;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int total_dist = 0;
    
    int i;
    int req;
    for (i = 0; i < n; i++) {
        scanf("%d", &req);
        printf("From %d to %d\n", curr_pos, req);
        printf("Distance moved: %d\n", req - curr_pos); 
        total_dist += abs(req - curr_pos);
        curr_pos = req;
    }
    
    printf("Total distance moved: %d", total_dist);
}
