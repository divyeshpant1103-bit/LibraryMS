#include <stdio.h>
#include "../include/library.h"
int main(){
    struct Book library[MAX_BOOK];
    int count=0;
    int choice;

    while(1){
        printf("\n====== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Book\n");
        printf("3. Search a Book\n");
        printf("4. Delete a Book\n");
        printf("5. EXit\n");
        printf("===========================================\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        if(choice==1){
            addBook(library,&count);
        }else if(choice==2){
            displaybooks(library,count);
        }else if(choice==3){
            searchbook(library,count);
        }else if(choice==4){
            deletebook(library,&count);
        }else if(choice==5){
            printf("Goodbye!\n");
            break;
        }else{
            printf("Invalid choice! Try again\n");
        }
    }
    return 0;
}