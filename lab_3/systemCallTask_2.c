#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void makeFork() {

	if (fork() == 0) {
        if (fork() == 0) {
            printf("I am grandchild\n");
        } else {
            wait();
            printf("I am child\n");
        }
    } else {
        wait();
        printf("I am parent\n");
    }
}


int main() {
	makeFork();
	return 0;
}