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

    int curr_req_smaller = curr_req_greater - 1;

    while(n > 0) {
        if (curr_req_greater < n && (requests[curr_req_greater] - curr_pos <= curr_pos - requests[curr_req_smaller])) {
            printf("From %d to %d\n", curr_pos, requests[curr_req_greater]);
            printf("Distance moved: %d\n", requests[curr_req_greater] - curr_pos); 
            total_dist += requests[curr_req_greater] - curr_pos;
            curr_pos = requests[curr_req_greater];
            curr_req_greater++;
            n--;
        }
        else if (curr_req_smaller >= 0 && (requests[curr_req_greater] - curr_pos >= curr_pos - requests[curr_req_smaller])) {
            printf("From %d to %d\n", curr_pos, requests[curr_req_smaller]);
            printf("Distance moved: %d\n", requests[curr_req_smaller] - curr_pos); 
            total_dist += curr_pos - requests[curr_req_smaller];
            curr_pos = requests[curr_req_smaller];
            curr_req_smaller--;
            n--;
        }
    }

    printf("Total distance moved: %d", total_dist);
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
