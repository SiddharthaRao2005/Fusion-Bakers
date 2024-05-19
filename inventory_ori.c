/*
    This code implements a stack approach to inventory system, using linked list.
*/
#include <stdio.h>
#include <stdlib.h>

struct item_stock{
    char item_name[50];
    int item_stock;
    struct item_stock* link;
};

typedef struct item_stock items;

void inventory_mainmenu(){
    printf("Welcome to inventory management system\n");
    printf("Please select the task you want to perform: \n");
    printf("1.Add item along with stock.\n");
    printf("2.Display all items along with stock.\n");
    printf("3.Delete the item along with stock.\n");
    printf("4.Exit the program. \n");
}

void addItem(items** head);
void displayItems(items** head);
void deleteItem(items** head);

void main(){
    items* head;
    head = NULL;
    inventory_mainmenu();
    int ch;
    scanf("%d",&ch);
    switch (ch){
        case (1):
            addItem(&head);
            main();
        case (2):
            displayItems(&head);
            main();
        case (3):
            deleteItem(&head);
            main();
        case (4):
            exit(0);
        default:
            printf("Enter the appropriate task please.\n");
            main();
    }
}

void addItem(items** head){
    items* mover;
    items* collector;
    collector = (items*)malloc(sizeof(items));
    printf("Enter item name: ");
    scanf("%[^\n]%*c",&(mover->item_name));
    printf("Enter item stock: ");
    scanf("%d",&(mover->item_stock));
    collector->link = NULL;
    if (head == NULL){
        head = collector;
        mover = collector;
        printf("Item added.");
    }else{
        mover->link = collector;
        mover = mover->link;
        printf("Item added.");
    }

}

void displayItems(items** head){
    if (head == NULL){
        printf("No items added.\n");
        main();
    }
    items* displayer = head;
    while (displayer!=NULL){
        printf("Item name: %s\n",displayer->item_name);
        printf("Item stock: %d\n",displayer->item_stock);
        printf("======================================");
        displayer = displayer->link;
    }
}

void deleteItem(items** head){
    items* deleter = head->link->link;
    head->link = deleter;
    printf("First item added has been deleted.");
}
