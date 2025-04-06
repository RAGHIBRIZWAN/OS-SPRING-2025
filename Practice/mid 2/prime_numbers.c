#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

void *runner(void* arg){
  int x = *(int *)arg;
  for (int i = 2; i <= x; i++){
    bool check = true;
    for (int j = 2; j  * j <= i; j++){
      if (i % j == 0){
        check = false;
        break;
      }
    }
    if(check){
      printf("%d\n",i);
    }
  }
  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t thread;
  int num = 50;
  pthread_create(&thread,NULL,runner,(void *)&num);
  pthread_join(thread,NULL);
  return 0;
}
