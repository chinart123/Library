#ifndef USER_H
#define USER_H

#include <stdbool.h>
#include "definitions.h"
// Forward declaration to avoid circular dependency
struct Transaction;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    bool is_deleted;
} User;

void user_init(User *user, int id, const char *name);
void user_print_info(const User *user);
// Changed from [] to * to fix compilation error
int user_delete(User *user, const struct Transaction *transactions, int transaction_count);

// Hàm mới: chỉnh sửa thông tin người dùng
void user_edit(User *user, const char *new_name);

#endif