#include <stdio.h>

//Main Menu File: Contains basic terminal UI layout for the program.
//All the functions are defined in other files.
//TLDR: To underline shit, use \e[4m at start of text and \e[0m at the end to stop the underline.

void main(){
    char ch;
    printf("--------------------------------------------------------------------\n");
    printf("                         \e[4mFusion Bakers\e[0m                     \n");
    printf("--------------------------------------------------------------------\n");
    printf("                    \e[4mEnter choice of operation\e[0m                       \n");
    printf("1. Checkout\n");
    printf("2. Inventory\n");
    printf("3. History\n");
    printf("4. Memberships\n");
    printf("5. Exit\n");
    printf("--------------------------------------------------------------------\n");
    printf("Your choice:");
    scanf("%d",&ch);
    while (ch!=5){
        if (ch==1){
            printf("Checkout\n");
            break;
        }
        else if(ch==2){
            printf("Inventory\n");
            break;
        }
        else if(ch==3){
            printf("History\n");
            break;
        }
        else if (ch==4){
            printf("Memberships\n");
            break;
        }
        else{
            printf("Enter the appropriate operation.\n");
            break;
        }
    }
}
