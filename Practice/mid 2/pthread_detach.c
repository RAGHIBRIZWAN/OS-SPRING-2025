#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by the detached thread
void* threadFunction(void* arg) {
    int* threadID = (int*)arg;
    printf("Thread %d: Starting work...\n", *threadID);
    sleep(2); // Simulating work
    printf("Thread %d: Work completed.\n", *threadID);
    return NULL;
}

int main() {
    pthread_t thread;
    int threadID = 1;

    // Create a detached thread
    if (pthread_create(&thread, NULL, threadFunction, (void*)&threadID) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Detach the thread
    if (pthread_detach(thread) != 0) {
        perror("Failed to detach thread");
        return 1;
    }

    printf("Main thread is free to do other work...\n");
    // Simulating main thread workload
    for (int i = 0; i < 3; i++) {
        printf("Main thread: Working...\n");
        sleep(1);
    }

    // Main thread completes its work
    printf("Main thread: Work completed. Exiting program.\n");
    
    return 0; // No need to join detached thread
}
