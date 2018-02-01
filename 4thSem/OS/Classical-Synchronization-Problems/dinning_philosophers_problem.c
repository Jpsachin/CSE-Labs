#include<stdio.h>
#include<string.h>

// pthread support library
#include<pthread.h>
// semaphore support library
#include<semaphore.h>

#define N 5

// semaphores for dinning philosophers problem
sem_t forks[N];


/**
 *  initialize semaphore varilables
 */ 
void initSemaphores() {
    
    // sem_init(semaphore variable reference, 0 to share semaphore between all threads, inital value)
    
    int i;
    for (i = 0; i < N; i++) {
        // forks semaphore for the each fork on the table
        sem_init(&forks[i], 0, 1);
    } 
} 



/**
 *  Dinning Philosopher program with semaphores
 */
void *philosopher(void *arg) {
    
    // index of the philosopher
    int index = (int) arg;
    
    // hungry state
    sleep(2);
    printf("Philosopher %d, is hungry\n", index);
   
   
   
   
   
   //================== PICK FIRST FORK =============================== 
    // check if it is the last philosopher
    if (index == N - 1){
        // try to pick up right fork if it is the last philosopher
        sem_wait(&forks[(index + 1)%N]);
    }
    else {
        // try to pick up left fork if it is not the last philosopher
        sem_wait(&forks[index]);
    } 
    
    // the philosopher has picked up 1 fork
    printf("Philosopher %d, picked up 1 fork\n", index);
    sleep(1);
   
    //================== PICK OTHER FORK ===============================
    // check if it is the last philosopher
    if (index == N - 1){
        // try to pick up left fork if it is the last philosopher  
        sem_wait(&forks[index]);
    }
    else {
        // try to pick up right fork if it is not the last philosopher
        sem_wait(&forks[(index + 1)%N]);
    }
    
    
    
    
    
    //================== CRITICAL SECTION =========================
    
    // the philosopher has picked up both forks
    printf("Philosopher %d, picked up both forks (right and left) \n", index);
    sleep(1);
    
    // the philosopher is eating as he picked up both forks
    printf("Philosopher %d, is eating \n", index);
    sleep(3);
    
    //================== END CRITICAL SECTION =========================
    
    
    
    
    
    //================== DROP FIRST FORK =============================== 
    // check if it is the last philosopher
    if (index == N - 1){
        // drop right fork if its the last philosopher
        sem_post(&forks[(index + 1)%N]);
    }
    else {
        // drop the left fork if it is not the last philosopher
        sem_post(&forks[index]);
    }
    
    // the philosopher drops 1 fork
    printf("Philosopher %d, dropped up 1 fork\n", index);
    sleep(1);
    
    //================== DROP OTHER FORK =============================== 
    // check if it is the last philosopher
    if (index == N - 1){
        // drop right fork if its the last philosopher
        sem_post(&forks[index]);
    }
    else {
        // drop the left fork if it is not the last philosopher
        sem_post(&forks[(index + 1)%N]);
    }
    
    
    
   
    // the philosopher has dropped both forks
    printf("Philosopher %d, dropped up both fork (dropped both)\n", index);
    sleep(1);
    
    // the philosopher is thinking
    printf("Philosopher %d, is thinking\n", index);

        
}      
      
        
int main() {
            
    initSemaphores();
    
    // declare pthread (POSIX threads) ids
    // A thread is a single sequence stream within in a process
    pthread_t philosophers[N];
    
    // create semaphore threads
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
    }
    
    // join threads
    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
    
    return 0;
}
