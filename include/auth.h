#ifndef AUTH_H
#define AUTH_H

struct User{
    char username[50];
    char password[50];
};

int login();
void saveusers();
void loaduser();
 #endif