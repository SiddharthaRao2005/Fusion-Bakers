#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_stock {
    char item_name[50];
    int item_stock;
    struct item_stock* link;
};

typedef struct item_stock items;

void inventory_mainmenu() {
    printf("Welcome to inventory management system\n");
    printf("Please select the task you want to perform: \n");
    printf("1. Add item along with stock.\n");
    printf("2. Display all items along with stock.\n");
    printf("3. Delete the item along with stock.\n");
    printf("4. Exit the program. \n");
}

void addItem(items** head);
void displayItems(items* head);
void deleteItem(items** head);

void inventory() {
    items* head = NULL;
    int ch;
    while (1) {
        inventory_mainmenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                addItem(&head);
                break;
            case 2:
                displayItems(head);
                break;
            case 3:
                deleteItem(&head);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter the appropriate task please.\n");
                break;
        }
    }
}

void addItem(items** head) {
    items* collector = (items*)malloc(sizeof(items));
    if (collector == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", collector->item_name);
    printf("Enter item stock: ");
    scanf("%d", &(collector->item_stock));
    collector->link = *head;
    *head = collector;
    printf("Item added.\n");
}

void displayItems(items* head) {
    if (head == NULL) {
        printf("No items added.\n");
        return;
    }
    items* displayer = head;
    while (displayer != NULL) {
        printf("Item name: %s\n", displayer->item_name);
        printf("Item stock: %d\n", displayer->item_stock);
        printf("======================================\n");
        displayer = displayer->link;
    }
}

void deleteItem(items** head) {
    if (*head == NULL) {
        printf("No items to delete.\n");
        return;
    }
    items* temp = *head;
    *head = (*head)->link;
    free(temp);
    printf("First item added has been deleted.\n");
}
