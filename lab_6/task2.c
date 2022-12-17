#include <stdio.h>

int main() {
    int n = 6;          //number of processes
    int m = 4;          //number of resources

    int alloc[6][4] = {{0, 1, 0, 3},   //PO allocation matrix
                       {2, 0, 0, 3},   //P1 allocation matrix
                       {3, 0, 2, 0},   //P2 allocation matrix
                       {2, 1, 1, 5},   //P3 allocation matrix
                       {0, 0, 2, 2},   //P4 allocation matrix
                       {1, 2, 3, 1}};  //P5 allocation matrix
    
    int max[6][4] =   {{6, 4, 3, 4},   //PO max matrix
                       {3, 2, 2, 4},   //P1 max matrix
                       {9, 1, 2, 6},   //P2 max matrix
                       {2, 2, 2, 8},   //P3 max matrix
                       {4, 3, 3, 7},   //P4 max matrix
                       {6, 2, 6, 5}};  //P5 max matrix

    int avail[4] = {2, 2, 2, 1};       //Available resources


    int need[6][4];
    int state[6] = {0, 0, 0, 0, 0, 0};
    int process[n*3];
    for(int i=0; i < n*3; i++) process[i] = -2;

    for(int i = 0; i < 6; i++)  
        for (int j = 0; j < 4; j++)    
            need[i][j] = max[i][j] - alloc[i][j];
    
    int i = 0, end = 0, al = 0;
    while(1) {
        if (i == 6) i = 0;

        int flag1 = 1;
        for(int j = 0; j < 4; j++) {
            if (need[i][j] > avail[j]) {
                flag1 = 0;
                break;
            }
        }
        if (flag1) {
            state[i] = 1;
            process[al] = i;
            al++;
            for(int j = 0; j < 4; j++)  avail[j] += alloc[i][j];
        }

        i++;
        end++;
        if (end == n*3) break;
    }

    int flag = 1;
    for (int i = 0; i < 6; i++) if(state[i] == 0) flag = 0;

    if (flag) {
        printf("Safe sequence of process execution is: \n");

        int printArray[6] = {-1, -1, -1, -1, -1, -1};
        printArray[0] = process[0];
        int k = 0;

        for (int i = 1; i < n*3; i++) {
            int flagActivate = 0;
            for (int j = 0; j < 6; j++) {
                if (process[i] == printArray[j]) {
                    flagActivate = 1;
                }
            }
            if (flagActivate == 0) {
                k++;
                printArray[k] = process[i];
            }
        }
        for(int i = 0; i < 6; i++) printf("P%d ", printArray[i]);
        printf("\n");
    } else printf("Deadlock Ahead\n");

    return 0;
}