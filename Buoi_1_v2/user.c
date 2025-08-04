#include "user.h"
#include <stdio.h>
#include <string.h>

void add_user(User users[], int *count, int id, const char *name, int Book_borrowed) {
    users[*count].id = id;
    strncpy(users[*count].name, name, 99);
    users[*count].Book_borrowed = Book_borrowed;
    users[*count].User_status = (Book_borrowed <= 2);
    (*count)++;
}

void print_all_users(User users[], int count) {
    printf("\n=== ALL USERS ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", users[i].id);
        printf("Name: %s\n", users[i].name);
        printf("Books borrowed: %d\n", users[i].Book_borrowed);
        printf("Status: %s\n\n", users[i].User_status ? "Available" : "Can't borrow");
    }
}

void print_users_by_name(User users[], int count, const char *name) {
    printf("\n=== USERS WITH NAME CONTAINING \"%s\" ===\n", name);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(users[i].name, name) != NULL) {
            printf("ID: %d\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Books borrowed: %d\n", users[i].Book_borrowed);
            printf("Status: %s\n\n", users[i].User_status ? "Available" : "Can't borrow");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No users found.\n");
    }
}