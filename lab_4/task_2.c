#include <stdio.h>

int main() {
    int numberOfProcesses = 0, timeQuantum = 0, totalWT = 0, totalTAT = 0;
    int ganttArray[500][2];
    for (int i=0; i < 500; i++) {
        ganttArray[i][0] = -1;
        ganttArray[i][1] = 0;
    }

    printf("Please enter the number of processes: \n");
    scanf("%d", &numberOfProcesses);
    printf("Please enter the time quantum: \n");
    scanf("%d", &timeQuantum);
    
    int processArray[numberOfProcesses][5];

    for (int i=0; i < numberOfProcesses; i++) {
        printf("Please enter burst time for P%d: ", i);
        scanf("%d", &processArray[i][0]);                                           //Burst Time
        processArray[i][1] = processArray[i][0];                                    //Remaining Burst Time
        processArray[i][2] = 0;                                                     //Completaton Time
    }
    printf("\n");

    int i = 0, gant = 1;

    while (1) {
        if (i == numberOfProcesses) i = 0;

        int breaker = 1;
        for (int k=0; k < numberOfProcesses; k++) {
            if (processArray[k][1] != 0) breaker = 0;
        }

        if (breaker == 1) break;


        if (processArray[i][1] <= timeQuantum && processArray[i][1] != 0) {
            
            ganttArray[gant][0] = i;
            ganttArray[gant][1] = ganttArray[gant-1][1] + processArray[i][1];
            processArray[i][1] = 0;

            processArray[i][2] = ganttArray[gant][1];                                 //Completation Time
            processArray[i][3] = processArray[i][2];                                  //Trunaround Time
            processArray[i][4] = processArray[i][3] - processArray[i][0];             //Wating Time
            gant++;
        }
        if (processArray[i][1] > timeQuantum) {

            processArray[i][1] = processArray[i][1] - timeQuantum;
            ganttArray[gant][0] = i;
            ganttArray[gant][1] = ganttArray[gant-1][1] + timeQuantum;
            gant++;
        }

        i++;
    }

    printf("Gantt Chart: ");
    for(int i = 1; i < 500; i++) {
        if (ganttArray[i][0] == -1) break;
        printf("P%d ", ganttArray[i][0]);   
    }
    printf("\n\n");
    printf("Proc    AT    BT    CT    WT    TAT\n");
    
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("%d       0     %d    %d    %d    %d\n", i, processArray[i][0], processArray[i][2], processArray[i][4], processArray[i][3]);
    }

    for (int i=0; i < numberOfProcesses; i++) {
        totalWT += processArray[i][4];
        totalTAT += processArray[i][3];
    }

    printf("\n\nAverage wating time: %f\nAverage turnaround time: %f\n\n\n", totalWT/(double)(numberOfProcesses), totalTAT/(double)(numberOfProcesses));
    

    return 0;
}