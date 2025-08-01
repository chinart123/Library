#ifndef USER_H
#define USER_H

#include "definitions.h"

// Định nghĩa struct User
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    bool is_deleted;
} User;

// Khai báo forward cho struct Transaction để tránh lỗi cyclic include
typedef struct Transaction Transaction;

// Khai báo các hàm liên quan đến người dùng
void user_init(User *user, int id, const char *name);
void user_edit(User *user, const char *new_name);
// Khai báo hàm với con trỏ thay cho mảng
void user_delete(User *user, const Transaction *transactions, int transaction_count);
//SUPPORT test10.c
void user_restore(User *user);
void user_print_info(const User *user);

#endif