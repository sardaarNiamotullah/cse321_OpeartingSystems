#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("problem_2b_input.txt", "r");
    outputFile = fopen("problem_2b_output.txt", "w");

    char line[200];
    char newLine[200];

    for(int i=0; i < sizeof(line); i++) {
        line[i] = 0;
        newLine[i] = 0;
    }

    while(fgets(line, 200, inputFile)) {
        int j = 0;
        for(int i=0; i < (sizeof(line)-4); i++) {
            if ((int)(line[i]) != 32) {
                newLine[j] = line[i];
                j++;
            } else {
                newLine[j] = line[i];
                j++;
                for (;i < (sizeof(line)-4); i++) {
                    if ((int)(line[i]) != 32) {
                        i--;
                        break;
                    }
                }
            }         
        }
        fprintf(outputFile, "%s", newLine);
    }
    return 0;
}