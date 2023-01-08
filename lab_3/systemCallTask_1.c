#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *argInput = argv[1];
    char *inputFileName[30];
    strcpy(inputFileName, argInput);
    strcat(inputFileName, ".txt");

    FILE *inputFile;

    inputFile = fopen(inputFileName, "w");

    char writeData[200];
    char termination[] = "-1";

    while(fgets(writeData, 200, stdin)) {
        int res = strcmp(writeData, termination);
        
        if (res != 10) {
            fprintf(inputFile, "%s", writeData);
        } else {
            break;
        }
    }

    return 0;
}