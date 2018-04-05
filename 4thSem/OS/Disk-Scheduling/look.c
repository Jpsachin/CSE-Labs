#include <stdio.h>

int curr_pos;
int size;
int requests[1000];
int n;

void sort(); 
    
int main() {
    
    // inputs
    printf("Enter current position of head: ");
    scanf("%d", &curr_pos);

    printf("Enter size: ");
    scanf("%d", &size);   
    
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int total_dist = 0;
    
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    // sort as per location
    sort();
    
    // get location of greater than the curr head position
    int curr_req_greater = n + 1;
    
    for (i = 0; i < n; i++) {
        if (requests[i] >= curr_pos) {
            curr_req_greater = i;
            break;        
        }
    }

    // respond all requests to the right
    for (i = curr_req_greater; i < n; i++) {
        printf("From %d to %d\n", curr_pos, requests[i]);
        printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
        total_dist += abs(requests[i] - curr_pos);
        curr_pos = requests[i];           
    }
     
    // respond to all requests to the left
    for (i = curr_req_greater - 1; i >= 0; i--) {
        printf("From %d to %d\n", curr_pos, requests[i]);
        printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
        total_dist += abs(requests[i] - curr_pos);
        curr_pos = requests[i];
           
    }
   
    printf("Total distance moved: %d", total_dist);
    return 0;
}


/**
 * Sort requests as per location
 */ 
void sort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[j] < requests[i]) {
                int tmp = requests[i];
                requests[i] = requests[j];    
                requests[j] = tmp;
            }
        }
    }
}
