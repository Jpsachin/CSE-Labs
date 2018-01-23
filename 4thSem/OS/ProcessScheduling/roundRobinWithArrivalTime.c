#include<stdio.h>
#define NO_OF_PROCESSES 5
#define TIME_QUANTUM 3

// result variables
int waitingTime[NO_OF_PROCESSES] = {0};
int turnAroundTime[NO_OF_PROCESSES] = {0};
int completed[NO_OF_PROCESSES] = {0};
int visited[NO_OF_PROCESSES] = {0};
int totalTurnAroundTime = 0;
int totalWaitingTime = 0;

// function declarations
void roundRobin(int, int [], int, int [], int []);



int main(){

    // process variables
    int n = NO_OF_PROCESSES;
    int burstTime[NO_OF_PROCESSES] = {4, 2, 3, 5, 1};
    int c_burstTime[NO_OF_PROCESSES] = {4, 2, 3, 5, 1};
    int arrivalTime[NO_OF_PROCESSES] = {0, 2, 4, 6, 7};
    int c_arrivalTime[NO_OF_PROCESSES] = {0, 2, 4, 6, 7};

    int timeQuantum = TIME_QUANTUM;

    // implement the algorithm
    roundRobin(n, burstTime, timeQuantum, c_burstTime, arrivalTime);


    // display results
    printf("Process ID\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");

    int i;
    for (i = 0; i < n; i++){

        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", i, c_arrivalTime[i], c_burstTime[i], waitingTime[i], turnAroundTime[i]);

        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("Averge Wait Time: %.3f\nAverage Turnaround Time: %.3f\n", (float)totalWaitingTime/n, (float)totalTurnAroundTime/n);

    return 0;
}



/**
 *  Round Robin Scheduling Algorithm
 */
void roundRobin(int n, int b[], int t, int c_b[], int a[]){


    int i, j, k;

    // completion status for all process
    int allProcessesCompleted = n;

    int totalTime = 0;

    i = 0;

    // calculate waiting time for all processes
    // repeat until all process are completed
    while (allProcessesCompleted) {

        // printf("%d %d\n\n", totalTime, i);

        // check if a process has completed status
        if (completed[i] == 0) {
            
            // check if process is present at the current time stamp
            if (a[i] <= totalTime) {
                
                // register visited process
                visited[i] = 1;
                
                // check if time quantum is greater than the burst time of the process to which token is allocated
                if(b[i] - t <= 0){
                    
                    totalTime += b[i];

                    // increment waiting times for other processes by the execution time remaining for current process
                    for (k = 0; k < n && a[k] <= totalTime; k++) {

                        if (k != i && completed[k] == 0){

                            // if process is not visited before (generated while some other process was executing) 
                            // waiting time is total time(which includes the current procecss execution time) - arrival time of the process
                            if (visited[k] == 0){
                                waitingTime[k] += totalTime - a[k];    
                                visited[k] = 1;
                            }
                            // waiting time is incremented by the execution time of the current process
                            else {
                                waitingTime[k] += b[i]; 
                            }


                        }
                    }
                    
                    // finish current process execution
                    b[i] = 0;
                    completed[i] = 1;
                    allProcessesCompleted--;



                }
                else{
                    
                    // reduce execution time for current process by time quantum
                    b[i] = b[i] - t;
                    
                    // update total time 
                    totalTime += t;
                    
                    // increment waiting times for other processes by time quantum
                    for (k = 0; k < n && a[k] <= totalTime; k++) {

                        if (k != i && completed[k] == 0){
                        
                            // if process is not visited before (generated while some other process was executing) 
                            // waiting time is total time(which includes time quantum) - arrival time of the process
                            if (visited[k] == 0){
                                waitingTime[k] += totalTime - a[k];    
                                visited[k] = 1;
                            }
                            // waiting time is incremented by the time quantum
                            else {
                                waitingTime[k] += t; 
                            }
     
                        }
                    }
                    
                }
                // printf("\t");
                // for (k = 0; k < n; k++) {

                //         if (completed[k] == 0){

                //             printf("%d- %d ",k,  waitingTime[k]);


                //     }
                // }
                // printf("\n");

                i = (i + 1) % n;

            }
            else{
                totalTime++;
            }

        }
        else {
            i = (i + 1) % n;
        }



    }

    // calculate turn around time for each process
    for (i = 0; i < n; i++) {

        turnAroundTime[i] = waitingTime[i] + c_b[i];

    }

}




