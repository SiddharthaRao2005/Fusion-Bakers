#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILENAME "stock.csv"

struct Item {
    char name[50];
    int quantity;
};

int itemCount = 0;

void readStock(struct Item stock[]) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Stock file doesn't exist. Creating a new file...\n");
        file = fopen(FILENAME, "w");
        if (file == NULL) {
            printf("Error creating file.\n");
            exit(1);
        }
        fclose(file);
        return;
    }

    while (fscanf(file, "%[^,],%d\n", stock[itemCount].name, &stock[itemCount].quantity) != EOF) {
        itemCount++;
    }

    fclose(file);
}

void saveStock(struct Item stock[]) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s,%d\n", stock[i].name, stock[i].quantity);
    }

    fclose(file);
}

int compareItems(const void *a, const void *b) {
    return strcmp(((struct Item *)a)->name, ((struct Item *)b)->name);
}

void sortStock(struct Item stock[]) {
    qsort(stock, itemCount, sizeof(struct Item), compareItems);
}

void addItem(struct Item stock[]) {
    char name[50];
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    strcpy(stock[itemCount].name, name);
    stock[itemCount].quantity = quantity;
    itemCount++;

    sortStock(stock);
    saveStock(stock);
    printf("Item added successfully.\n");
}

int binarySearch(struct Item stock[], char *name, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (strcmp(stock[mid].name, name) == 0)
            return mid;
        if (strcmp(stock[mid].name, name) > 0)
            return binarySearch(stock, name, left, mid - 1);
        return binarySearch(stock, name, mid + 1, right);
    }
    return -1;
}

void searchItem(struct Item stock[]) {
    char name[50];
    printf("Enter item name to search: ");
    scanf("%s", name);

    sortStock(stock);
    int result = binarySearch(stock, name, 0, itemCount - 1);

    if (result != -1) {
        printf("Item found: %s, Quantity: %d\n", stock[result].name, stock[result].quantity);
    } else {
        printf("Item not found.\n");
    }
}

void deleteItem(struct Item stock[]) {
    char name[50];
    printf("Enter item name to delete: ");
    scanf("%s", name);

    int result = binarySearch(stock, name, 0, itemCount - 1);

    if (result != -1) {
        for (int i = result; i < itemCount - 1; i++) {
            strcpy(stock[i].name, stock[i + 1].name);
            stock[i].quantity = stock[i + 1].quantity;
        }
        itemCount--;

        saveStock(stock);
        printf("Item deleted successfully.\n");
    } else {
        printf("Item not found.\n");
    }
}

void updateStock(struct Item stock[]) {
    char name[50];
    int quantity;

    printf("Enter item name to update: ");
    scanf("%s", name);

    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    int result = binarySearch(stock, name, 0, itemCount - 1);

    if (result != -1) {
        stock[result].quantity = quantity;
        saveStock(stock);
        printf("Stock updated successfully.\n");
    } else {
        printf("Item not found.\n");
    }
}

void printMenu() {
    printf("\n--- Grocery Store Stock Management ---\n");
    printf("1. Add Item\n");
    printf("2. Search Item\n");
    printf("3. Delete Item\n");
    printf("4. Update Stock\n");
    printf("5. Exit\n");
}

int stocksmgmt() {
    struct Item stock[MAX_ITEMS];
    readStock(stock);

    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(stock);
                break;
            case 2:
                searchItem(stock);
                break;
            case 3:
                deleteItem(stock);
                break;
            case 4:
                updateStock(stock);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
