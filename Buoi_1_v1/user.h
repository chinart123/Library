#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define MAX_USERS 50

typedef struct {
    int id;
    char name[100];
    int borrowed_count;
    bool status; // true: Available, false: Can't borrow
} User;

// Function declarations
void add_user(User users[], int *count, int id, const char *name, int borrowed_count);
void print_all_users(User users[], int count);
void print_users_by_name(User users[], int count, const char *name);

#endif