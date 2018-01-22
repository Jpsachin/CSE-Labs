#include<stdio.h>
#define NO_OF_PROCESSES 4


// result variables 
int waitingTime[NO_OF_PROCESSES] = {0};
int turnAroundTime[NO_OF_PROCESSES] = {0};
int totalTurnAroundTime = 0;
int totalWaitingTime = 0;

// function declarations
void firstComeFirstServe(int, int [], int[]);



int main(){

    // process variables
    int n = NO_OF_PROCESSES;
    int burstTime[NO_OF_PROCESSES] = {2 ,3, 4, 1};
    int arrivalTime[NO_OF_PROCESSES] = {0, 5, 5 , 7};
    int c_arrivalTime[NO_OF_PROCESSES] = {0, 5, 5 , 7};
    
    // implement the algorithm
    firstComeFirstServe(n, burstTime, arrivalTime); 
    
    
    // display results
    printf("Process ID\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");
     
    int i;
    for (i = 0; i < n; i++){
        
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n\n", i, c_arrivalTime[i], burstTime[i], waitingTime[i], turnAroundTime[i]); 
        
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i]; 
    }   
    
    printf("Averge Wait Time: %.3f\nAverage Turnaround Time: %.3f\n", (float)totalWaitingTime/n, (float)totalTurnAroundTime/n);   

    return 0;
}



/**
 *  First Come First Serve Scheduling Algorithm
 */
void firstComeFirstServe(int n, int b[], int a[]){
    
    int i;
    
    // time for execution of a process before a particular process
    int timeForExec[NO_OF_PROCESSES] = {0};
    
    // initialize for first process
    timeForExec[0] = 0;
    waitingTime[0] = 0;
    
    
    // calculate waiting time for each process
    for (i = 1; i < n; i++){
    
        // calculate the time left for execuion of processes before current process 
        timeForExec[i] = timeForExec[i - 1] + b[i - 1];
               
        // waiting time is (time for completion of processes before the current process) - (arrival time of the current process)
        waitingTime[i] = timeForExec[i] - a[i];
        
        
        // if before arrival of the current process the previous processes complete
        if (waitingTime[i] < 0){
        
            // set waiting times and time for execution to 0    
            waitingTime[i] = 0;
            timeForExec[i] = 0;
            
            // shift arrival time of future processe relative to the current process
            int j;
            for (j = i + 1; j < n; j++){
                a[j] = a[j] - a[i];  
            }
        }
                
    } 
   
    // calculate turn around time for each process 
    for (i = 0; i < n; i++){
        
        turnAroundTime[i] = waitingTime[i] + b[i];
        
    } 
} 

