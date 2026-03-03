#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
void addBook(struct Book library[],int *count);
void displaybooks(struct Book library[],int count);
void searchbook(struct Book library[],int count);
void deletebook(struct Book library[],int *count);
void issuebook(struct Book library[],int count);
void returnbook(struct Book library[],int count);
#endif