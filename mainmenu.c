#include <stdio.h>
#include <stdlib.h>
#include "checkout.h"

void main()
{
    printf("-----------------Welcome to Fusion Bakers------------------\n");
    printf("----------Please enter your choice of operation------------\n");
    printf("1. Generate bill\n");
    printf("2. New membership\n");
    printf("3. Check store stock\n");
    printf("4. Exit\n");
    int ch;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        checkout();
        // printf("Checkout\n");
        break;
    case 2:
        // membershp();
        printf("Membership\n");
        break;
    case 3:
        // stock();
        printf("Stocks\n");
        break;
    case 4:
        exit(0);
    default:
        printf("Choice not found.\n");
        exit(1);
    }
}