#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bill {
    char itemname[20];
    unsigned int itemquantity;
    unsigned int itemprice;
    struct bill* node;
};

void WriteToFile(struct bill* head, const char* custname) {
    FILE* fp = fopen(custname, "w");
    struct bill* temp = head;
    fprintf(fp,"item name | item quantity | item price | final price\n");
    while (temp != NULL) {
        fprintf(fp, "%s %u %u\n", temp->itemname, temp->itemquantity, (temp->itemprice * temp->itemquantity));
        temp = temp->node;
    }
    fclose(fp);
}

void checkout() {
    printf("------------Generating customer bill--------------\n");
    struct bill* head = NULL;
    struct bill* tail = NULL;
    struct bill* temp;
    int ch = 0;
    char custname[50];
    do {
        struct bill* new_item = (struct bill*)malloc(sizeof(struct bill));
        printf("Enter item name: ");
        scanf("%s", new_item->itemname);
        printf("Enter item quantity and price: ");
        scanf("%u %u", &new_item->itemquantity, &new_item->itemprice);
        new_item->node = NULL;
        if (head == NULL) {
            head = new_item;
            tail = new_item;
        }
        else {
            tail->node = new_item;
            tail = new_item;
        }
        printf("Do you want to add another item? (0->yes/1->no): ");
        scanf("%d", &ch);
    } while (ch != 1);

    printf("----------Customer Bill Generated Below------------\n");
    temp = head;
    printf("Item name | Item Quantity | Item Original Price | Item Cost\n");
    while (temp != NULL) {
        printf("%s | %u | %u | %u \n", temp->itemname, temp->itemquantity, temp->itemprice, (temp->itemprice * temp->itemquantity));
        temp = temp->node;
    }
    printf("-----End-----\n");

    int ch2;
    printf("Do you wish to go with the given bill? (0->yes/1->no): ");
    scanf("%d", &ch2);

    if (ch2 == 0) {
        printf("Enter customer name: ");
        scanf("%s", custname);
        snprintf(custname, sizeof(custname), "%s.txt", custname);
        WriteToFile(head, custname);
        printf("Customer copy saved as text file. Please access it for future references.\n");
        // Free allocated memory
        while (head != NULL) {
            struct bill* temp = head;
            head = head->node;
            free(temp);
        }
    }
    else if (ch2 == 1) {
        printf("Restarting bill generation.......\n");
        // Free allocated memory
        while (head != NULL) {
            struct bill* temp = head;
            head = head->node;
            free(temp);
        }
        checkout();
    }
}

