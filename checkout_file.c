#include <stdio.h>

enum item_prices {Eggs=70,Bread=50,Milk=25,Honey=100,Butter=50,Jam=50,Flour=60,Sugar=60,Yeast=50,Berries=200}
const char items[10] = {"Eggs","Bread","Milk","Honey","Butter","Jam","Flour","Sugar","Yeast","Berries"};
int item_holder[10];
int quantity[10];

void checkout(){
    for (int i = 0; i<10; i++){
        printf("Enter item ID: ");
        scanf("%d",item_holder[i]);
        printf("Enter quantity: ");
        scanf("%d",quantity[i]);
    }
       
}