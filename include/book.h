#ifndef BOOK_H
#define BOOK_H
#define MAX_BOOK 100
struct Book{
    int id;
    char title[100];
    char author[50];
    int is_available;
    char issuedto[50];
    char StudentID[20];
    char issuedate[20];
    char returndate[20];
};

#endif