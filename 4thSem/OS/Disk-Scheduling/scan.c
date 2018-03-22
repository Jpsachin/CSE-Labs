#include<stdio.h>

int curr_pos;
int size;
int requests[1000];
int n;

void sort(); 
    
int main() {
    
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
    
    sort();
    
    int curr_req_greater;
    
    for (i = 0; i < n; i++) {
        if (requests[i] > curr_pos) {
            curr_req_greater = i;
            break;        
        }
    }
   
    
    
    int curr_req = curr_req_greater;
    for (i = curr_pos; i < size && curr_req < n; i++) {
        //printf("Pos: %d req : %d\n\n", i, requests[curr_req]); 
        if(i == requests[curr_req]) {
            printf("From %d to %d\n", curr_pos, i);
            printf("Distance moved: %d\n", abs(i - curr_pos)); 
            total_dist += abs(i - curr_pos);
            curr_pos = i;
            curr_req++;
        }            
    }
    
    total_dist += abs(curr_pos - size);
    curr_pos = size;

    
    curr_req = curr_req_greater - 1;
    for (i = curr_pos; i >= 0 && curr_req >= 0; i--) {
        if(i == requests[curr_req]) {
            printf("From %d to %d\n", curr_pos, i);
            printf("Distance moved: %d\n", abs(i - curr_pos)); 
            total_dist += abs(i - curr_pos);
            curr_pos = i;
            curr_req--;
        }         
    }
   
    printf("Total distance moved: %d", total_dist);
    
    return 0;
}


void sort() {
    int i, j;
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[j] < requests[i]) {
                int tmp = requests[i];
                requests[i] = requests[j];    
                requests[j] = tmp;
            }
        }
    }
}
