#include <stdio.h>

int main() {
    int n = 5;          //number of processes
    int m = 4;          //number of resources

    int alloc[5][4] = {{0, 1, 0, 3},   //PO allocation matrix
                       {2, 0, 0, 0},   //P1 allocation matrix
                       {3, 0, 2, 0},   //P2 allocation matrix
                       {2, 1, 1, 5},   //P3 allocation matrix
                       {0, 0, 2, 2}};  //P4 allocation matrix
    
    int max[5][4] =   {{6, 4, 3, 4},   //PO max matrix
                       {3, 2, 2, 1},   //P1 max matrix
                       {9, 1, 2, 6},   //P2 max matrix
                       {2, 2, 2, 8},   //P3 max matrix
                       {4, 3, 3, 7}};  //P4 max matrix

    int need[5][4];
    int avail[4] = {3, 3, 2, 1};       //Available resources
    int state[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < 5; i++)  
        for (int j = 0; j < 4; j++)    
            need[i][j] = max[i][j] - alloc[i][j];

    int i = 0, end = 0;
    while(1) {
        if (i == 5) i = 0;

        int flag1 = 1;
        for(int j = 0; j < 4; j++) {
            if (need[i][j] > avail[j]) {
                flag1 = 0;
                break;
            }
        }
        if (flag1) {
            state[i] = 1;
            for(int j = 0; j < 4; j++)  avail[j] += alloc[i][j];
        }

        i++;
        end++;
        if (end == n*3) break;
    }

    int flag = 1;
    for (int i = 0; i < 5; i++) if(state[i] == 0) flag = 0;

    if (flag) printf("Safe Here\n");
    else printf("Deadlock Ahead\n");

    return 0;
}