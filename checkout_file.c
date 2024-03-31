#include <stdio.h>

enum item_prices {Eggs=70,Bread=50,Milk=25,Honey=100,Butter=50,Jam=50,Flour=60,Sugar=60,Yeast=50,Berries=200}
// const char items[10] = {"Eggs","Bread","Milk","Honey","Butter","Jam","Flour","Sugar","Yeast","Berries"};
int quantity[10];

void checkout(){
    enum item_prices items[] = {Eggs,Bread,Milk,Honey,Butter,Jam,Flour,Sugar,Yeast,Berries};
    for (int i = 0; i<10; i++){
        printf("Enter item ID: ");
        scanf("%d",item_holder[i]);
        printf("Enter quantity: ");
        scanf("%d",quantity[i]);
    }
    printf("             Here is the list of items added         \n");
    printf("-------------------------------------------------------\n");
    printf(" | Item ID |    Items    | Quantity | Price | Total |  \n");
    for (int j = 0; j<10; j++){
        printf(" |   %d    |     %s     |    %d    |  %d  |  %d  | \n",j+1,items[j],quantity[j],items[j]*quantity[j]);
    }
       
}