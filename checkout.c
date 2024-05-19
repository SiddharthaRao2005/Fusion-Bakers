#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementing concept of linked list for making bills, and storing them in a text file along
    generating another one in terminal for use case.*/

struct bill{
    char itemname[20];
    unsigned int itemquantity;
    unsigned int itemprice;
    struct bill* node;
};

void WriteToFile(struct bill* head, const char* custname){
    FILE* fp = fopen(custname,"w");
    struct bill* temp = head;
    while (temp != NULL){
        fprintf(fp, "%s %u %u",temp->itemname,temp->itemquantity,(temp->itemprice*temp->itemquantity));
    }
    fclose(fp);
}

void checkout()
{
    printf("------------Generating customer bill--------------\n");
    struct bill* head = NULL;
    struct bill* tail = NULL;
    struct bill* temp;
    int ch = 0;
    char custname[50];
    while (ch != 1)
    {
        struct bill* new = (struct bill*)malloc(sizeof(struct bill));
        printf("Enter item name: ");
        scanf("%[^\n]%*c",new->itemname);
        printf("Enter item quantity and price: ");
        scanf("%u %u", new->itemquantity, new->itemprice);
        new->node = NULL;
        if (head == NULL){
            head = new;
            tail = new;
        }
        else{
            tail->node = new;
            tail = new;
        }
        printf("Do you want to add another item ? (0->yes/1->no): ");
        scanf("%d",&ch);
    }
    printf("----------Customer Bill Generated Below------------\n");
    temp = head;
    printf("Item name | Item Quantity | Item Original Price | Item Cost\n");
    while (temp != NULL){
        printf("%s | %u | %u | %u \n",temp->itemname,temp->itemquantity,temp->itemprice,(temp->itemprice*temp->itemquantity));
        temp = temp->node;
    }
    printf("-----End-----\n");
    int ch2;
    printf("Do you wish to go with the given bill ? (0->yes/1->no) : ");
    if (ch2 == 0){
        printf("Enter customer name: ");
        scanf("%s",custname);
        snprintf(custname,sizeof(custname),"%s.txt",custname);
        WriteToFile(head,custname);
        printf("Customer copy saved as text file. Please access it for future references.\n");
        exit(0);
    }
    if (ch2 == 1){
        printf("Restarting bill generation.......\n");
        while (temp != NULL){
            struct bill* gone = temp->node;
            free(temp);
            temp = gone;
        }
        checkout();
    }
}