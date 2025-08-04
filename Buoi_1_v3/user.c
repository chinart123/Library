#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void add_user(User users[], int *count, int id, const char *name, int Book_borrowed) {
    // Kiểm tra tính hợp lệ của số sách mượn
    if (Book_borrowed < 0) {
        printf("Error: Book_borrowed cannot be negative. Setting to 0.\n");
        Book_borrowed = 0;
    }
    
    // Tự động kiểm tra trạng thái người dùng
    bool can_borrow = (Book_borrowed <= 2);
    
    users[*count].id = id;
    strncpy(users[*count].name, name, 99);
    users[*count].name[99] = '\0';
    users[*count].Book_borrowed = Book_borrowed;
    users[*count].User_status = can_borrow;
    
    (*count)++;
    
    // Thông báo trạng thái tự động
    if (can_borrow) {
        printf("User '%s' added successfully. Status: Available (can borrow books).\n", name);
    } else {
        printf("User '%s' added successfully. Status: Can't borrow (already has %d books).\n", name, Book_borrowed);
    }
}

void print_all_users(User users[], int count) {
    printf("\n=== ALL USERS (%d) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", users[i].id);
        printf("Name: %s\n", users[i].name);
        printf("Books borrowed: %d\n", users[i].Book_borrowed);
        if (users[i].User_status) {
            printf("Status: Available (can borrow books)\n\n");
        } else {
            printf("Status: Can't borrow (already has %d books)\n\n", users[i].Book_borrowed);
        }
    }
}

void print_users_by_name(User users[], int count, const char *name) {
    printf("\n=== USERS WITH NAME CONTAINING \"%s\" ===\n", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(users[i].name, name) != NULL) {
            found++;
            printf("ID: %d\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Books borrowed: %d\n", users[i].Book_borrowed);
            if (users[i].User_status) {
                printf("Status: Available (can borrow books)\n\n");
            } else {
                printf("Status: Can't borrow (already has %d books)\n\n", users[i].Book_borrowed);
            }
        }
    }
    if (!found) {
        printf("No users found with name containing: %s\n", name);
    }
}