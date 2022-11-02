#include <stdio.h>

int main() {
    int validPassword = 0;

    while (validPassword == 0) {
        char password[60];
        fgets(password, sizeof(password), stdin);
        int digit = 0, lowercase = 0, uppercase = 0, special = 0;
        int toPrint = 0;

        for (int i = 0; i < strlen(password); i++) {

            if ((int)(password[i]) > 47 && (int)(password[i]) < 58) { digit = 1;}
            else if ((int)(password[i]) > 96 && (int)(password[i]) < 123) { lowercase = 1;}
            else if ((int)(password[i]) > 64 && (int)(password[i]) < 91) { uppercase = 1;}
            else if ((int)(password[i]) == 95 || (int)(password[i]) == 35 || (int)(password[i]) == 36 || (int)(password[i]) == 64) { special = 1;}
        }

        if (digit == 1 && lowercase == 1 && uppercase == 1 && special == 1) {
            printf("OK");
            break;
        } else {
            if (digit == 0) { toPrint++;}
            if (lowercase == 0) { toPrint++;}
            if (uppercase == 0) { toPrint++;}
            if (special == 0) { toPrint++;}

            for (int i = 0; i < toPrint; i++) {
                if (digit == 0) {
                    i++;
                    if (toPrint == i) { break;}
                    digit = 1;
                    printf("Digit missing, ");
                }
                if (lowercase == 0) {
                    i++;
                    if (toPrint == i) { break;}
                    lowercase = 1;
                    printf("Lowercase character missing, ");
                }
                if (uppercase == 0) {
                    i++;
                    if (toPrint == i) { break;}
                    uppercase = 1;
                    printf("Uppercase character missing, ");
                }
                if (special == 0) {
                    i++;
                    if (toPrint == i) { break;}
                    special = 1;
                    printf("Special character missing, ");
                }
            }

            if (digit == 0) { printf("Digit missing.\n");}
            if (lowercase == 0) { printf("Lowercase character missing.\n");}
            if (uppercase == 0) { printf("Uppercase character missing.\n");}
            if (special == 0) { printf("Special character missing.\n");}
        }
    }

    return 0;
}