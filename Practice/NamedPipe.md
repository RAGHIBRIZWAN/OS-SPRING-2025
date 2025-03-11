# PRODUCER:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]){
  char buffer[BUFSIZ];

  mkfifo("myfifo1",0777);
  
  int fd = open("myfifo1",O_WRONLY);
  
  printf("Write a message: ");
  fgets(buffer, BUFSIZ, stdin);
  
  write(fd, buffer, BUFSIZ);
  
  close(fd);
  unlink("myfifo1"); 
  return 0;
}
```

# CONSUMER:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]){
  char buffer[BUFSIZ];

  mkfifo("myfifo1",0777);
  
  int fd = open("myfifo1",O_RDONLY);
  
  read(fd, buffer, BUFSIZ);
  printf("Consumer read message: %s",buffer);
  
  close(fd);
  unlink("myfifo1"); 
  return 0;
}
```
