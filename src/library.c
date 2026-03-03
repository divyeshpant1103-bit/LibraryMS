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
        printf("Available: %s\n",library[i].is_available ? "Yes" : "No");
        printf("-------------\n");
    }
}
void searchbook(struct Book library[],int count){
    if(count==0){
        printf("No books in library!\n");
        return;
    }
    char keyword[100];
    int found=0;
    while(getchar() != '\n' && getchar() != EOF);
    printf("Enter title to seatch: ");
    fgets(keyword,100,stdin);
    keyword[strcspn(keyword, "\n")]=0;

    printf("\n======= SEARCH RESULTS ======");
    for(int i=0;i<count;i++){
        if(strcmp(library[i].title,keyword)==0){
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Available: %s\n", library[i].is_available ? "Yes" : "No");
            printf("--------------------------\n");
            found = 1; 
        }
    }
    if(found){
        printf("No book found with that title!\n");
    }
}
void deletebook(struct Book library[],int *count){
    if(*count==0){
        printf("The library is empty!\n");
        return;
    }

    int id;
    int found =-1;

    printf("Enter the Id to be deleted: ");
    scanf("%d",&id);
    getchar();

    for(int i=0;i< *count;i++){
        if(library[i].id==id){
            found=i;
            break;
        }
    }
    if(found==-1){
        printf("NO book found with %d the ID \n",id);
        return ;
    }
    //shift all element left to fill the gap;
    for(int i=found;i< *count-1;i--){
        library[i]=library[i+1];
    }
    *count=*count-1;
    printf("Book is deleted successfully\n");
}
void issuebook(struct Book library[],int count){
    if(count==0){
        printf("No book in library!\n");
        return;
    }
    int id,found=-1;
    printf("Enter the book id issue: ");
    scanf("%d",&id);
    getchar();
    for(int i=0;i<count;i++){
        if(library[i].id==id){
            found=i;
            break;
        }
    }
    if(found== -1){
        printf("NO book found with the ID %d\n",id);
        return;
    }
    if(library[found].is_available==0){
        printf("Sorry ! This book is already issued: %s\n",
            library[found].issuedto);
        printf("Expected return date: %s\n",library[found].returndate);
        return ;
        }
        //BOOK is available collect details
        printf("Enter the student Name: ");
        fgets(library[found].issuedto,100,stdin);
        library[found].issuedto[strcspn(library[found].issuedto,"\n")]=0;

        printf("Enter the student ID: ");
        fgets(library[found].StudentID,20,stdin);
        library[found].StudentID[strcspn(library[found].StudentID,"\n")]=0;

        printf("Enter the issue Date[DD-MM-YYYY]: ");
        fgets(library[found].issuedate,20,stdin);
        library[found].issuedate[strcspn(library[found].issuedate,"\n")]=0;

        printf("Enter the Return date[DD-MM-YYYY]: ");
        fgets(library[found].returndate,20,stdin);
        library[found].returndate[strcspn(library[found].returndate,"\n")]=0;

        //mark as issue
        library[found].is_available=0;

        printf("\n✅ Issued successfully \n");
        printf("Book :%s \n",library[found].title);
        printf("TO :%s\n",library[found].issuedto);
        printf("ID :%s\n",library[found].StudentID);
        printf("Date :%s\n",library[found].issuedate);
        printf("Return :%s\n",library[found].returndate);     
} 
void returnbook(struct Book library[],int count){
    if(count==0){
        printf("NO book in library\n");
        return;
    }
    int id,found=-1;
    printf("Enter the Book ID");
    scanf("%d",&id);
    getchar();
    
    //find book
    for(int i=0;i<count;i++){
        if(library[i].id==id){
            found=i;
            break;
        }
    }
    if(found== -1){
        printf("NO book found with Id %d \n",id);
        return;
    }
    if(library[found].is_available==1){
        printf("Book is already in library");
        return;
    }
    // Show return details
    printf("\nReturning book: %s\n", library[found].title);
    printf("Issued to     : %s\n", library[found].issuedto);
    printf("Student ID    : %s\n", library[found].StudentID);
    printf("Issue Date    : %s\n", library[found].issuedate);
    printf("Return Date   : %s\n", library[found].returndate);

    //Clear all issued Detail
    library[found].is_available=1;
    library[found].issuedto[0]='\0';
    library[found].StudentID[0]='\0';
    library[found].issuedate[0]='\0';
    library[found].returndate[0]='\0';
    
    printf("\n Book is returned successfully!\n");
}