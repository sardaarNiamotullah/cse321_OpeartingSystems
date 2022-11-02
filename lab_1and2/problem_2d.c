#include <stdio.h>

int main() {

    char email[50];
    char refmail[10] = "@sheba.xyz";
    int bchecker = 1;

    fgets(email, sizeof(email), stdin);

    if (strlen(email) > 10) {
        int i = strlen(email) - 1;
        int z = i - 10;
        int k = strlen(refmail) -1;

        for ( ; i >= z; i--) {
            if (email[i] != refmail[k]) {
                bchecker = 0;
                break;
            }
            k--;
        }

        if (bchecker == 0) {
            printf("Email address is outdated.");
        }
        else {
            printf("Email address is okay.");
        }
    }
    else {
        printf("Email address is outdated.");
    }

    return 0;
}