# OBSERVATIONS AND DISCUSSION:

## a) pthread_create function pass argument num in runner function. 

## b) We have done default attributes only in this lab.

## c)
```asm
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *argc){
    printf("Thread executing.....\n");
    pthread_exit((void *)42);
}

int main(){
    pthread_t threadID; 
    pthread_attr_t attributes;
    void *exit_status;

    pthread_attr_init(&attributes);
    pthread_create(&threadID, NULL, thread_function, NULL); 
    pthread_join(threadID, &exit_status); // Wait for thread to complete
    printf("Thread exited with status %ld:\n",(long)exit_status);
    return 0;
}
```
