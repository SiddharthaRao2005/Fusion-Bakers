#include <stdio.h>

int chechout(){
    char items[10][10];
    int itemprice[10][10];
    int itemquant[10][10];
    int serialno=1;
    int* q = itemquant;
    int* p = itemprice;

    for (int i = 0; i<10; i++){
        printf("Enter item name: ");
        scanf("%s",items[i]);
        printf("Enter item quantity: ");
        scanf("%d",*q);
        q++;
        printf("Enter item price: ");
        scanf("%d",*p);
        p++;
    }
    printf("                  Here is the list of items added:                  \n");
    printf("--------------------------------------------------------------------\n");
    printf("        | Item No.|       Name       | Quantity | Price |          \n");
    for (int j = 0; j<10; j++){
        
        printf("        |    %d    |       %s       |    %d    |  %.3f   |         \n",serialno+j,items[j],q,(*q)*(*p));
        q++;
        p++;
    }
}

void main(){
    chechout();  //Only run for debugging and test purposes !!!
}