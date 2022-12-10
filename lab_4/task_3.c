#include <stdio.h>


int main() {
    int numberOfProcess = 0;
    int gChart[500];
    for (int i = 0; i < 500; i++) gChart[i] = -1;

    printf("Please enter how many process you have: ");
    scanf("%d", &numberOfProcess);
    printf("\n");

    int processArray[numberOfProcess][7];

    for (int i=0; i < numberOfProcess; i++) {
        printf("Please enter the arival time for P%d: ", i);
        scanf("%d", &processArray[i][0]);                                //Arival Time
        printf("Please enter the burst time for P%d: ", i);
        scanf("%d", &processArray[i][1]);                                //Burst Time
        printf("Please enter the priority for P%d: ", i);
        scanf("%d", &processArray[i][6]);                                //Priority
        printf("\n");
        processArray[i][2] = processArray[i][1];                         //Remaining Burst Time
        processArray[i][3] = 0;                                          //Completation Time
        processArray[i][4] = 0;                                          //Turnaround Time
        processArray[i][5] = 0;                                          //Waiting Time
    }


    int time = 0;

    while(1) {
        int breaker = 1;
        for (int k=0; k < numberOfProcess; k++) {if (processArray[k][2] != 0) breaker = 0;}
        if (breaker == 1) break;

        int lowestPriority = 999, executableProcess = -1;
        for (int j = 0; j < numberOfProcess; j++) {
            if (processArray[j][2] <= 0) continue;

            if ((processArray[j][6] < lowestPriority) && (processArray[j][0] <= time)) {
                lowestPriority = processArray[j][6];
                executableProcess = j;
            }
        }
        gChart[time] = executableProcess;
        
        processArray[executableProcess][2] -= 1;

        if (processArray[executableProcess][2] == 0) processArray[executableProcess][3] = time + 1;

        time++;
    }

    printf("\nGantt chart: P%d", gChart[0]);

    for (int i = 1; i < 500; i++) {
        if (gChart[i] == -1) break;
        if (gChart[i] == gChart[i-1]) continue;
        else printf("  P%d", gChart[i]);
    }

    printf("\n\nProc     AT     BT     CT     WT     TAT\n");

    int totalWT = 0, totalTAT = 0;

    for (int i=0; i < numberOfProcess; i++) {
        int TAT = processArray[i][3] - processArray[i][0];
        int WT = TAT - processArray[i][1];

        totalWT += WT;
        totalTAT += TAT;

        printf("%d        %d      %d      %d      %d      %d\n", i, processArray[i][0], processArray[i][1], processArray[i][3], WT, TAT);
    }

    printf("\n");
    printf("\n\nAverage wating time: %f\nAverage turnaround time: %f\n\n\n", totalWT/(double)(numberOfProcess), totalTAT/(double)(numberOfProcess));

    return 0;
}