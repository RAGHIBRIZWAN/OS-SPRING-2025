#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void* arg) {
    while (1) {
        printf("Working...\n");
        sleep(1); // Simulating work
    }
}
int main() {
    pthread_t tid;
    
    // Create a thread
    pthread_create(&tid, NULL, worker, NULL);
    
    // Simulate some work in main thread
    sleep(5);
    
    // Request cancellation of the worker thread
    pthread_cancel(tid);
    
    // Wait for the worker thread to finish and clean up
    pthread_join(tid, NULL);
    
    printf("Worker thread has been terminated and cleaned up.\n");
    
    return 0;
  }
