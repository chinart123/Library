#ifndef USER_H
#define USER_H

#include <stdbool.h>

typedef struct {
    int id;
    char name[100];
    int Book_borrowed;
    bool User_status;
} User;

void add_user(User users[], int *count, int id, const char *name, int Book_borrowed);
void print_all_users(User users[], int count);
void print_users_by_name(User users[], int count, const char *name);

#endif