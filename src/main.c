#include <stdio.h>
#include <string.h>
#include "../include/library.h"
#include "../include/file.h"
#include "../include/auth.h"
int main(){
    if(!login()){
        return 0; //exit if login failed
    }
    struct Book library[MAX_BOOK];
    int count=0;
    int choice;
    
    memset(library,0,sizeof(library));
    loadbooks(library,&count);

    while(1){
        printf("\n====== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Book\n");
        printf("3. Search a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. EXit\n");
        printf("===========================================\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        getchar();
        if(choice==1){
            addBook(library,&count);
            savebooks(library,count);
        }else if(choice==2){
            displaybooks(library,count);
        }else if(choice==3){
            searchbook(library,count);
        }else if(choice==4){
            deletebook(library,&count);
            savebooks(library,count);
        }else if(choice==5){
            issuebook(library,count);
            savebooks(library,count);
        }else if(choice==6){
           returnbook(library,count);
           savebooks(library,count);
        }else if(choice==7){
            savebooks(library,count);
            printf("Goodbye!\n");
            break;
        }else{
            printf("Invalid choice! Try again\n");
        }
    }
    return 0;
}