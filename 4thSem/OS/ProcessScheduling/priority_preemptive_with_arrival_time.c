#include<stdio.h>
#define NO_OF_PROCESSES 4


// result variables
int pid[NO_OF_PROCESSES] = {0};
int waitingTime[NO_OF_PROCESSES] = {0};
int turnAroundTime[NO_OF_PROCESSES] = {0};
int totalTurnAroundTime = 0;
int totalWaitingTime = 0;

// function declarations
void priorityPreemptiveWithArrivalTime(int, int [], int[], int[], int[]);



int main() {

    // process variables
    int n = NO_OF_PROCESSES;
    int priority[NO_OF_PROCESSES] = {3, 2, 1, 4};
    int burstTime[NO_OF_PROCESSES] = {8, 3, 4, 6};
    int c_burstTime[NO_OF_PROCESSES] = {8, 3, 4, 6};
    int arrivalTime[NO_OF_PROCESSES] = {0, 2, 3, 4};
    int c_arrivalTime[NO_OF_PROCESSES] = {0, 2, 3, 4};

    // initialize process id
    int j;
    for (j = 0; j < n; j++){
        pid[j] = j;
    }

    // implement the algorithm
    priorityPreemptiveWithArrivalTime(n, burstTime, c_burstTime, arrivalTime, priority);




    // display results
    printf("Process ID\t\tArrival Time\t\tPriority Time\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");

    int i;
    for (i = 0; i < n; i++) {

        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", pid[i], c_arrivalTime[pid[i]], priority[i], c_burstTime[pid[i]], waitingTime[i], turnAroundTime[i]);

        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

    }

    printf("Averge Wait Time: %.3f\nAverage Turnaround Time: %.3f\n", (float)totalWaitingTime/n, (float)totalTurnAroundTime/n);

    return 0;
}



/**
 *  Priority Scheduling Preemptive With Arrival Time Algorithm
 */
void priorityPreemptiveWithArrivalTime(int n, int b[], int c_b[], int a[], int p[]) {

    int i, j;

    int time = 0;

    int noOfProcessesCompleted = 0;

    // repeat till completion of all processes
    while (noOfProcessesCompleted < n){

        // sort as per priority considering processes which are present at this time
        for (i = noOfProcessesCompleted; i < n - 1 && a[i] <= time; i++) {

            for (j = i + 1; j < n && a[j] <= time; j++) {

                if (p[i] > p[j]){
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                    
                    tmp = b[i];
                    b[i] = b[j];
                    b[j] = tmp;

                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;

                    tmp = waitingTime[i];
                    waitingTime[i] = waitingTime[j];
                    waitingTime[j] = tmp;

                    tmp = pid[i];
                    pid[i] = pid[j];
                    pid[j] = tmp;
                }
            }
        }

        // printf("++++++++++++++++++++++++++ %d %d\n", time, noOfProcessesCompleted);
        //     for (i = 0; i < n; i++) {
        //         printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", pid[i], a[i], b[i], waitingTime[i]);
        // }

        // check if process is present in buffer
        if (a[noOfProcessesCompleted] <= time) {

            // decrease burst time for the current process
            if (b[noOfProcessesCompleted] > 0) {
                b[noOfProcessesCompleted]--;
                // printf("\n%d\n", noOfProcessesCompleted);

            }

            // update waiting time for the other processes
            for (i = noOfProcessesCompleted + 1; i < n && a[i] <= time; i++) {
                waitingTime[i]++;
            }

            // check if current process has completed
            if (b[noOfProcessesCompleted] == 0){
                noOfProcessesCompleted++;
                // printf("\n%d\n", noOfProcessesCompleted - 1);
            }

            // printf("++++++++++++++++++++++++++ %d %d\n", time, noOfProcessesCompleted);
            // for (i = 0; i < n; i++) {
            //     printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", pid[i], a[i], b[i], waitingTime[i]);
            // }
        }

        // increment time
        time++;
    }



    // calculate turn around time for each process
    for (i = 0; i < n; i++) {

        turnAroundTime[i] = waitingTime[i] + c_b[pid[i]];

    }
}
