#include<stdio.h>
#define NO_OF_PROCESSES 4


// result variables
int pid[NO_OF_PROCESSES] = {0};
int waitingTime[NO_OF_PROCESSES] = {0};
int turnAroundTime[NO_OF_PROCESSES] = {0};
int totalTurnAroundTime = 0;
int totalWaitingTime = 0;

// function declarations
void shortestJobFirst(int, int [], int[], int[]);



int main() {

    // process variables
    int n = NO_OF_PROCESSES;
    int burstTime[NO_OF_PROCESSES] = {8, 4, 9, 5};
    int c_burstTime[NO_OF_PROCESSES] = {8, 4, 9, 5};
    int arrivalTime[NO_OF_PROCESSES] = {0, 1, 2, 3};
    int c_arrivalTime[NO_OF_PROCESSES] = {0, 1, 2, 3};

    // initialize process id
    int j;
    for (j = 0; j < n; j++){
        pid[j] = j;
    }

    // implement the algorithm
    shortestJobFirst(n, burstTime, c_burstTime, arrivalTime);




    // display results
    printf("Process ID\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");

    int i;
    for (i = 0; i < n; i++) {

        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", pid[i], c_arrivalTime[pid[i]], c_burstTime[pid[i]], waitingTime[i], turnAroundTime[i]);

        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

    }

    printf("Averge Wait Time: %.3f\nAverage Turnaround Time: %.3f\n", (float)totalWaitingTime/n, (float)totalTurnAroundTime/n);

    return 0;
}



/**
 *  Shortest Job First Scheduling Algorithm
 */
void shortestJobFirst(int n, int b[], int c_b[], int a[]) {

    int i, j;

    int time = 0;

    int noOfProcessesCompleted = 0;

    while (noOfProcessesCompleted < n){

        // sort as per burst time considering processes which are present at this time
        for (i = noOfProcessesCompleted; i < n - 1 && a[i] <= time; i++) {

            for (j = i + 1; j < n && a[j] <= time; j++) {

                if (b[i] > b[j]){
                    int tmp = b[i];
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

        if (a[noOfProcessesCompleted] <= time) {


            if (b[noOfProcessesCompleted] > 0) {
                b[noOfProcessesCompleted]--;
                // printf("\n%d\n", noOfProcessesCompleted);

            }

            for (i = noOfProcessesCompleted + 1; i < n && a[i] <= time; i++) {
                waitingTime[i]++;
            }


            if (b[noOfProcessesCompleted] == 0){
                noOfProcessesCompleted++;
                // printf("\n%d\n", noOfProcessesCompleted - 1);
            }

            // printf("++++++++++++++++++++++++++ %d %d\n", time, noOfProcessesCompleted);
            // for (i = 0; i < n; i++) {
            //     printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", pid[i], a[i], b[i], waitingTime[i]);
            // }
        }

        time++;
    }



    // calculate turn around time for each process
    for (i = 0; i < n; i++) {

        turnAroundTime[i] = waitingTime[i] + c_b[pid[i]];

    }
}
