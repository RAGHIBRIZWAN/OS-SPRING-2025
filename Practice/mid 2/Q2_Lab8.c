#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000
#define THREADS 3
#define PIECE (SIZE / THREADS)

typedef struct {
    int start;
    int end;
} ThreadData;

void *maximum(void *arg) {
    int *array = (int *)arg;
    int max = array[0];
    for (int i = 0; i < 9; i++) {
        if(array[i] > max){
          max = array[i];
        }
    }
    int *result = (int *)malloc(sizeof(int));
    *result = max;
    return (void *) result;
}

void *minimum(void *arg) {
    int *array = (int *)arg;
    int min = array[0];
    for (int i = 0; i < 9; i++) {
        if(array[i] < min){
          min = array[i];
        }
    }
    int *result = (int *)malloc(sizeof(int));
    *result = min;
    return (void *) result;
}

void *mean(void *arg) {
    int *array = (int *)arg;
    int x = 0;
    for (int i = 0; i < 9; i++) {
        x = x + array[i];
    }
    x = x / 9;
    
    int *result = (int *)malloc(sizeof(int));
    *result = x;
    return (void *) result;
}

int main(int argc, char *argv[]) {
    pthread_t thread[THREADS];
    int array[] = {1,2,3,4,5,6,7,8,9};
    void *rc;
    pthread_create(&thread[0], NULL, maximum, (void *)array);
    pthread_join(thread[0], &rc);
    printf("MAXIMUM: %d\n",*(int*) rc);
    pthread_create(&thread[1], NULL, minimum, (void *)array);
    pthread_join(thread[1], &rc);
    printf("MINIMUM: %d\n",*(int*) rc);
    pthread_create(&thread[2], NULL, mean, (void *)array);
    pthread_join(thread[2], &rc);
    printf("MEAN: %d\n",*(int*) rc);

    return 0;
}
