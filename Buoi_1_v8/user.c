#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "transaction.h"
#include "timeline/timeline.h"

void user_init(User *user, int id, const char *name) {
    if (user == NULL) {
        printf("Error: User pointer is NULL.\n");
        return;
    }
    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';
    user->is_deleted = false;
    printf("User created: ID %d, Name: %s\n", user->id, user->name);
    timeline_add_event(EVENT_USER_CREATE, -1, user->id);//support test10.c
}

void user_edit(User *user, const char *new_name) {
    if (user == NULL) {
        printf("Error: User pointer is NULL.\n");
        return;
    }
    printf("Editing user ID %d...\n", user->id);
    if (new_name != NULL && strcmp(new_name, "") != 0 && strcmp(user->name, new_name) != 0) {
        strncpy(user->name, new_name, MAX_NAME_LENGTH - 1);
        user->name[MAX_NAME_LENGTH - 1] = '\0';
        timeline_add_event(EVENT_USER_EDIT_NAME, -1, user->id); // THÊM DÒNG NÀY
    }
    printf("User ID %d updated.\n", user->id);
}

// Định nghĩa hàm đã được sửa để khớp với khai báo trong user.h
void user_delete(User *user, const Transaction *transactions, int transaction_count) {
    if (user == NULL) {
        printf("Error: User pointer is NULL.\n");
        return;
    }
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].user->id == user->id && transactions[i].is_active) {
            printf("Error: Cannot delete user ID %d. They have an active borrowed book.\n", user->id);
            return;
        }
    }
    user->is_deleted = true;
    timeline_add_event(EVENT_USER_DELETE, -1, user->id);
    printf("User ID %d has been soft-deleted.\n", user->id);
}

void user_print_info(const User *user) {
    if (user == NULL) {
        printf("User info: NULL\n");
        return;
    }
    printf("--- User Info ---\n");
    printf("ID: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Status: %s\n", user->is_deleted ? "Deleted" : "Active");
}


// support test10.c
void user_restore(User *user) {
    if (user == NULL) {
        printf("Error: User pointer is NULL.\n");
        return;
    }
    if (!user->is_deleted) {
        printf("User ID %d is not deleted. No need to restore.\n", user->id);
        return;
    }
    user->is_deleted = false;
    timeline_add_event(EVENT_USER_RESTORE, -1, user->id);
    printf("User ID %d has been restored.\n", user->id);
}