#include <stdio.h>
#include "../include/book.h"
int main(){
    struct Book b1;
    b1.id=1;
    b1.is_available=1;
    
    printf("Book ID: %d\n",b1.id);
    printf("Availablr: %d \n",b1.is_available);
}