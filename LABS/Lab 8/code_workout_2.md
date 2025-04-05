# a)

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

static volatile int counter = 0;

void *mythread(void *arg) {
  printf("%s: begin\n",(char *) arg);
  int i;
  for (i = 0; i < 1e7; i++){
    counter = counter + 1;
  }
  printf("%s: done. Counter = %d\n",(char *)arg,counter);
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t p1,p2;
  
  printf("main: begin (counter = %d)\n",counter);
  pthread_create(&p1,NULL,mythread,"A");
  pthread_create(&p2,NULL,mythread,"B");
  
  pthread_join(p1,NULL);
  pthread_join(p2,NULL);
  
  printf("main: done with both (counter = %d)\n",counter);
  return 0;
}
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/4b189360-849b-4c99-a986-089d5ac673c2)

# b) Explanation of the Problem:

## Race Condition: In the mythread function, both threads A and B are incrementing the shared variable counter without any form of synchronization.
## This means that when one thread reads the value of counter,it may not see the most upto date value if the other thread has also modified it at the same time.
## This leads to inconsistent and unpredictable results. If two threads perform increment simultaneously, they can read the same initial value of counter, increment it, 
## and then write back the same incremented value, effectively losing one increment.

# c)
![image](https://github.com/user-attachments/assets/3e208858-1762-41cd-bdfd-45081f92552c)

## Now the name of both global and local variables are same, so the counter variable the function will use is its local variable not gloab variable.
## That's why the output of part b and part c are different.
