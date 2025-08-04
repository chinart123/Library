#include "user.h"
#include <stdio.h>
#include <string.h>

// Add a new user to the system
void add_user(User users[], int *count, int id, const char *name, int borrowed_count) {
    if (*count >= MAX_USERS) {
        printf("User storage full!\n");
        return;
    }
    
    users[*count].id = id;
    strncpy(users[*count].name, name, 99);
    users[*count].borrowed_count = borrowed_count;
    users[*count].status = (borrowed_count <= 2); // Available if <=2 books
    
    (*count)++;
    printf("User added successfully!\n");
}

// Print all users with status
void print_all_users(User users[], int count) {
    printf("\n=== ALL USERS ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", users[i].id);
        printf("Name: %s\n", users[i].name);
        printf("Borrowed books: %d\n", users[i].borrowed_count);
        printf("Status: %s\n\n", users[i].status ? "Available" : "Can't borrow");
    }
}

// Search and print users by name
void print_users_by_name(User users[], int count, const char *name) {
    printf("\n=== SEARCH RESULTS ===\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(users[i].name, name) != NULL) {
            printf("ID: %d\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Borrowed books: %d\n", users[i].borrowed_count);
            printf("Status: %s\n\n", users[i].status ? "Available" : "Can't borrow");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No users found with name: %s\n", name);
    }
}