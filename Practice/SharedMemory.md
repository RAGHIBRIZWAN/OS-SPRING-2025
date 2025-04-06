# PRODUCER:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // For O_* constants
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SIZE 1024

int main() {
    // Create or open shared memory
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // Set size of shared memory
    if (ftruncate(fd, SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Map shared memory
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Write to shared memory
    char message[SIZE];
    printf("Enter message to write: ");
    fgets(message, SIZE, stdin);
    memcpy(ptr, message, strlen(message) + 1);

    printf("Message written to shared memory.\n");

    // Cleanup
    munmap(ptr, SIZE);
    close(fd);

    return 0;
}
```

# CONSUMER:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // For O_* constants
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SIZE 1024

int main() {
    // Open existing shared memory
    int fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // Map shared memory
    void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Read from shared memory
    printf("Message from shared memory: %s\n", (char *)ptr);

    // Cleanup
    munmap(ptr, SIZE);
    close(fd);

    // Optional: unlink the shared memory
    shm_unlink(SHM_NAME);

    return 0;
}
```
