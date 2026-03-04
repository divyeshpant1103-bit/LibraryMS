#include <stdio.h>
#include <string.h>
#include "../include/auth.h"

//default admin credentials
struct User admin ={"admin","admin123"};

int login() {
    char username[50];
    char password[50];
    int attempts = 0;

    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("          LOGIN TO CONTINUE\n");
    printf("======================================\n");

    while(attempts < 3) {
        // Clear both arrays before each attempt
        memset(username, 0, sizeof(username));
        memset(password, 0, sizeof(password));

        printf("\nAttempt %d of 3\n", attempts + 1);
        printf("Username: ");
        fgets(username, 50, stdin);
        username[strcspn(username, "\n")] = 0;

        printf("Password: ");
        fgets(password, 50, stdin);
        password[strcspn(password, "\n")] = 0;

        if(strcmp(username, admin.username) == 0 &&
           strcmp(password, admin.password) == 0) {
            printf("\nLogin Successful! Welcome %s!\n", username);
            return 1;
        } else {
            attempts++;
            if(attempts < 3) {
                printf("Wrong credentials! %d attempt(s) remaining.\n",
                       3 - attempts);
            }
        }
    }

    printf("\nToo many failed attempts! System locked!\n");
    printf("Please contact your administrator.\n");
    return 0;
}