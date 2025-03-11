```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Function to calculate median
double findMedian(int arr[], int n) {
    // Sorting array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Finding median
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

// Function to calculate factorial
long long factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

int main() {
    int pipe1[2], pipe2[2]; // Two pipes: Parent → Child and Child → Parent

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) { 
        // **CHILD PROCESS**: Receives array, calculates median, sends it back
        close(pipe1[1]); // Close writing end of pipe1
        close(pipe2[0]); // Close reading end of pipe2

        int arr[100], n;
        read(pipe1[0], &n, sizeof(n));  // Read size of array
        read(pipe1[0], arr, sizeof(int) * n);  // Read array elements

        double median = findMedian(arr, n); // Compute median
        int medianInt = (int)median; // Convert to integer for factorial

        write(pipe2[1], &medianInt, sizeof(medianInt)); // Send median back to parent

        close(pipe1[0]); // Close remaining pipe ends
        close(pipe2[1]);
        exit(0);
    } else { 
        // **PARENT PROCESS**: Sends array, receives median, computes factorial
        close(pipe1[0]); // Close reading end of pipe1
        close(pipe2[1]); // Close writing end of pipe2

        int arr[] = {5, 3, 8, 1, 7}; 
        int n = sizeof(arr) / sizeof(arr[0]);

        write(pipe1[1], &n, sizeof(n));  // Send size of array
        write(pipe1[1], arr, sizeof(int) * n); // Send array elements

        int median;
        read(pipe2[0], &median, sizeof(median)); // Read median from child

        long long fact = factorial(median); // Compute factorial

        printf("Median: %d\n", median);
        printf("Factorial of Median: %lld\n", fact);

        close(pipe1[1]); // Close remaining pipe ends
        close(pipe2[0]);
        wait(NULL);
    }

    return 0;
}
```
