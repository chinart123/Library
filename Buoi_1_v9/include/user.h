#ifndef USER_H
#define USER_H

#include <stdbool.h>
#include "definitions.h"

typedef struct User {
    int id;
    char name[MAX_NAME_LENGTH];
    bool is_deleted;
} User;

// Use forward declaration for Transaction
typedef struct Transaction Transaction;

// Function declarations
void user_init(User *user, int id, const char *name);
FunctionResult user_edit(User *user, const char *new_name);
FunctionResult user_delete(User *user, const Transaction *transactions, int count);
FunctionResult user_restore(User *user);
void user_print_info(const User *user);
bool user_has_borrowed_books(const User *user, const Transaction *transactions, int count);

#endif // USER_H