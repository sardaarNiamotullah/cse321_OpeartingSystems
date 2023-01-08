#include <stdio.h>

struct paratha { int quantity, unitPrice;};
struct vegetable { int quantity, unitPrice;};
struct mineralWater { int quantity, unitPrice;};

int main() {

    struct paratha p;
    struct vegetable v;
    struct mineralWater w;
    int numberOfpeople;
    float pay;

    printf("Quantity of Paratha: ");
    scanf("%d", &p.quantity);
    printf("Unit Price: ");
    scanf("%d", &p.unitPrice);

    printf("Quantity of vegetable: ");
    scanf("%d", &v.quantity);
    printf("Unit Price: ");
    scanf("%d", &v.unitPrice);

    printf("Quantity of Mineral Water: ");
    scanf("%d", &w.quantity);
    printf("Unit Price: ");
    scanf("%d", &w.unitPrice);

    printf("Number of people: ");
    scanf("%d", &numberOfpeople);

    pay = (p.quantity*p.unitPrice + v.quantity*v.unitPrice + w.quantity*w.unitPrice)/(float)(numberOfpeople);

    printf("Individual people will pay: %.2f", pay);

    return 0;
}