#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main() {
    int a, b, c;
    double pCount = 3.0;
    pid_t pid, parentPid;

    parentPid = getpid();

    a = fork();
    b = fork();
    c = fork();

    int array[] = {a, b, c};

    for (int i = 0; i < sizeof(array); i++) {
        if (array[i] == 0) {
            pid = getpid();

            if (pid % 2 != 0) {
                pCount++;
                fork();
            }
        }
    }

    pid = getpid();

    if (pid == parentPid) printf("%d", (int)(pow(2.0, pCount)));
    
    return 0;
}