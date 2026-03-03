#include <stdio.h>
#include <string.h>
#include "../include/library.h"
void addBook(struct Book library[],int *count ){
    int i=*count;
    int newid;
    printf("Enter the Book ID: ");
    scanf("%d",&newid);
    getchar();

    //Chech if ID already exist or not
    for(int j=0;j<*count;j++){
        if(library[j].id==newid){
            printf("❌ ERROR! Book with this ID %d already exist!\n",newid);
            return; //exit function without adding
        }
    }
    //ID is unique proceed with adding
    library[i].id=newid;

    printf("Enter the Book Title: ");
    fgets(library[i].title,100,stdin);
    library[i].title[strcspn(library[i].title, "\n")]=0;

    printf("Enter the Author Name: ");
    fgets(library[i].author,50,stdin);
    library[i].author[strcspn(library[i].author, "\n")]=0;


    library[i].is_available=1;
    *count=*count+1;

    printf("Book Added succefully!\n");
}
void displaybooks(struct Book library[],int count){
    if(count==0){
        printf("No book in library!\n");
        return ;
    }
    printf("\n===== ALL BOOKS =====\n");
    for(int i=0;i<count;i++){
        printf("ID: %d\n",library[i].id);
        printf("Title: %s\n",library[i].title);
        printf("Author: %s\n",library[i].author);
        printf("Available: %d\n",library[i].is_available ? "Yes" : "No");
        printf("-------------\n");
    }
}