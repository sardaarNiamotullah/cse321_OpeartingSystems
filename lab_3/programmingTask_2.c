#include <stdio.h>


void perfectNumber(int start, int end) {

    for(int i = start; i < end; i++) {
        int num = 0;
        for(int j = 1; j < i; j++) {
            if(i % j == 0) {
                num += j;
            }
        }
        if (i == num) {
            printf("%d\n", i);
        }
    }

}


int main() {

    int start, end;

    scanf("%d", &start);
    scanf("%d", &end);

    perfectNumber(start, end);

    return 0;
}