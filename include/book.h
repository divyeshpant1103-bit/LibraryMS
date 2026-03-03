#ifndef BOOK_H
#define BOOK_H
#define MAX_BOOK 100
struct Book{
    int id;
    char title[100];
    char author[50];
    int is_available;
};

#endif