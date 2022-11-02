#include <stdio.h>

int main() {

    char word[100];
    fgets(word, sizeof(word), stdin);
    int bChecker = 1;
    int len = strlen(word);
    int mid = len/2 - 1;
    int k = len - 2;

    for (int i = 0; i < len-1; i++) {
        if ((int)(word[i]) > 64 && (int)(word[i]) < 91) {
            word[i] = (int)(word[i]) + 32;
        }
    }

    for (int i = 0; i < mid; i++) {
        if (word[i] == word[k]) {
            k--;
            continue;
        } else {
            bChecker = 0;
            break;
        }
    }

    if (bChecker == 1) {
        printf("Palindrome");
    } else {
        printf("Not Palindrome");
    }

    return 0;
}