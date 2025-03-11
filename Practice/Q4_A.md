```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "10 PID: " << getpid() << " ParentID: " << getppid() << endl;

    int pid = fork();
    if (pid == 0) {  // Left child (6)
        cout << "6 PID: " << getpid() << " ParentID: " << getppid() << endl;

        int pid1 = fork();
        if (pid1 == 0) {  // Left child (4)
            cout << "4 PID: " << getpid() << " ParentID: " << getppid() << endl;
            exit(0);
        }

        int pid2 = fork();
        if (pid2 == 0) {  // Right child (8)
            cout << "8 PID: " << getpid() << " ParentID: " << getppid() << endl;
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    } else {
        int pid2 = fork();
        if (pid2 == 0) {  // Right child (18)
            cout << "18 PID: " << getpid() << " ParentID: " << getppid() << endl;

            int pid3 = fork();
            if (pid3 == 0) {  // Left child (15)
                cout << "15 PID: " << getpid() << " ParentID: " << getppid() << endl;
                exit(0);
            }

            int pid4 = fork();
            if (pid4 == 0) {  // Right child (21)
                cout << "21 PID: " << getpid() << " ParentID: " << getppid() << endl;
                exit(0);
            }

            wait(NULL);
            wait(NULL);
            exit(0);
        }

        wait(NULL);
        wait(NULL);
    }

    return 0;
}
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/8716c8e5-263d-4e73-8900-3f8e0a05c372)
