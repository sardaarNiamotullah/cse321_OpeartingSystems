#include <stdio.h>
int main() {

   int firstNumber;
   scanf("%d", &firstNumber);
   int secondNumber;
   scanf("%d", &secondNumber);
   char operator;
   getchar();
   scanf("%c", &operator);

   if (firstNumber == secondNumber) {
      printf("%d", firstNumber*secondNumber);
   } else if (firstNumber > secondNumber) {
      printf("%d", firstNumber - secondNumber);
   } else {
      printf("%d", firstNumber+secondNumber);
   }
   

   return 0;
}