// src/user.c

#include "../include/user.h"           // brings in User, FunctionResult, definitions
#include <stdio.h>
#include <string.h>
#include "../include/transaction.h"    // real Transaction type
#include "../include/timeline.h"       // timeline_add_event()

void user_init(User *user, int id, const char *name) {
    if (!user || !name) {
        printf("Error: Invalid user or name pointer.\n");
        return;
    }
    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';
    user->is_deleted = false;
    timeline_add_event(EVENT_USER_CREATE, 0, id);
}

FunctionResult user_edit(User *user, const char *new_name) {
    if (!user || !new_name) return RESULT_FAILED_INVALID_INPUT;
    strncpy(user->name, new_name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';
    timeline_add_event(EVENT_USER_EDIT_NAME, 0, user->id);
    return RESULT_SUCCESS;
}

FunctionResult user_delete(User *user, const Transaction transactions[], int count) {
    if (!user) {
        printf("Error: Invalid user pointer.\n");
        return RESULT_FAILED_INVALID_INPUT;
    }
    if (user_has_borrowed_books(user, transactions, count)) {
        printf("Error: User '%s' (ID: %d) has borrowed books.\n",
               user->name, user->id);
        return RESULT_FAILED_ACTIVE_TRANSACTION;
    }
    user->is_deleted = true;
    timeline_add_event(EVENT_USER_DELETE, 0, user->id);
    return RESULT_SUCCESS;
}

FunctionResult user_restore(User *user) {
    if (!user) return RESULT_FAILED_INVALID_INPUT;
    user->is_deleted = false;
    timeline_add_event(EVENT_USER_RESTORE, 0, user->id);
    return RESULT_SUCCESS;
}

void user_print_info(const User *user) {
    if (!user) {
        printf("Error: Invalid user pointer.\n");
        return;
    }
    printf("User ID: %d, Name: %s, Status: %s\n",
           user->id, user->name,
           user->is_deleted ? "[DELETED]" : "Active");
}

bool user_has_borrowed_books(const User *user, const Transaction transactions[], int count) {
    if (!user) return false;
    for (int i = 0; i < count; i++) {
        if (transactions[i].user->id == user->id && transactions[i].is_active)
            return true;
    }
    return false;
}
