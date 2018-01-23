#include<stdio.h>
#define NO_OF_PROCESSES 4


// result variables
int pid[NO_OF_PROCESSES] = {0}; 
int waitingTime[NO_OF_PROCESSES] = {0};
int turnAroundTime[NO_OF_PROCESSES] = {0};
int totalTurnAroundTime = 0;
int totalWaitingTime = 0; 

// function declarations
void shortestJobFirst(int, int []);



int main(){

    // process variables
    int n = NO_OF_PROCESSES;
    int burstTime[NO_OF_PROCESSES] = {2 ,3, 4, 1};
    int arrivalTime[NO_OF_PROCESSES] = {0, 5, 5 , 7};
    int c_arrivalTime[NO_OF_PROCESSES] = {0, 5, 5 , 7};

    // initialize process id
    int j;
    for (j = 0; j < n; j++){
        pid[j] = j;
    }
    
    // implement the algorithm
    shortestJobFirst(n, burstTime); 
    
  
    
    
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
 *  Shortest Job First Scheduling Algorithm
 */
void shortestJobFirst(int n, int b[]){
    
    int i, j;
    
    int time = 0;

    allProcessesCompleted = n;

    while (allProcessesCompleted){

        // sort as per burst time considering processes which are present at this time 
        for (i = 0; a[i] <= time; i++){
            
            for (j = i; a[j] <= time; j++){
                
                if (b[i] > b[j]){
                    int tmp = b[i];
                    b[i] = b[j];
                    b[j] = tmp;
                    
                    tmp = pid[i];
                    pid[i] = pid[j];
                    pid[j] = tmp;
                }
            }
        }
        
        // time for execution of a process before a particular process
        int timeForExec[NO_OF_PROCESSES] = {0};
        
        // initialize for first process
        timeForExec[0] = 0;
        waitingTime[0] = 0;
        
        
        // calculate waiting time for each process
        for (i = 1; a[i] <= time ; i++){
        
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



    }

     
    
    // calculate turn around time for each process
    for (i = 0; i < n; i++){
        
        turnAroundTime[i] = waitingTime[i] + b[i];
        
    } 
} 
