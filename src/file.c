#include <stdio.h>
#include "../include/file.h"

void savebooks(struct Book library[], int count) {
    FILE *fp = fopen("data/books.dat", "wb");

    if(fp == NULL) {
        printf("Error! Could not save data!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(library, sizeof(struct Book), count, fp);

    fclose(fp);
    printf("Data saved successfully!\n");
}

void loadbooks(struct Book library[], int *count) {
    FILE *fp = fopen("data/books.dat", "rb");

    if(fp == NULL) {
        *count = 0;
        return;
    }

    fread(count, sizeof(int), 1, fp);
    fread(library, sizeof(struct Book), *count, fp);

    fclose(fp);
    printf("Data loaded! %d books found.\n", *count);
}