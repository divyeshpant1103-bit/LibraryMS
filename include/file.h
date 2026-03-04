#ifndef FILE_H
#define FILE_H
#include "book.h"

void savebooks(struct Book library[],int count);
void loadbooks(struct Book library[],int *count);
 
#endif