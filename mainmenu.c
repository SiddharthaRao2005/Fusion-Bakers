#include <stdio.h>
#include <stdlib.h>
#include "checkout.h"
#include "stocks.h"

int main()
{
    printf("-----------------Welcome to Fusion Bakers------------------\n");
    printf("----------Please enter your choice of operation------------\n");
    printf("1. Generate bill\n");
    printf("2. Check store stock\n");
    printf("3. Exit\n");
    int ch;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        checkout();
        // printf("Checkout\n");
        break;
    case 2:
        stocksmgmt();
        // printf("Stocks\n");
        break;
    case 3:
        exit(0);
    default:
        printf("Choice not found.\n");
        exit(1);
    }
    return 0;
}