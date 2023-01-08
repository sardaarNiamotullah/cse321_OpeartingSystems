#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main() {
    pid_t childPid, parentPid;
    pid_t grandChild[3];

    if(fork()) {
        wait();
        parentPid = getpid();
    } else {
        childPid = getpid();
        if(!fork()) grandChild[0] = getpid();
        if(!fork()) grandChild[1] = getpid();
        if(!fork()) grandChild[2] = getpid();
    }

    if (parentPid == getpid()) {
        printf("Parent process ID: %d\n", parentPid);
        printf("Child process ID: %d\n", childPid);
        printf("Grand Child process ID: %d\n", grandChild[0]);
        printf("Grand Child process ID: %d\n", grandChild[1]);
        printf("Grand Child process ID: %d\n", grandChild[2]);
    }

    return 0;
}