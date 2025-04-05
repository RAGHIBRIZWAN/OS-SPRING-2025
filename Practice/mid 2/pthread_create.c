#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *helloWorld(void *vargp) {
  sleep(2);
  printf("Hello World \n");
  return NULL;
}
int main() {
  pthread_t thread_id;
  printf("Before Thread\n");
  pthread_create(&thread_id, NULL, helloWorld, NULL);
  pthread_join(thread_id, NULL);
  printf("After Thread\n");
  exit(0);
}
