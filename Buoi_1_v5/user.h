#ifndef USER_H
#define USER_H

#include <stdbool.h> // For bool type
#include "definitions.h" // Include common definitions

typedef struct {
    int id;                // Unique user identifier
    char name[MAX_NAME_LENGTH]; // User name
    bool is_deleted;        // True if the user is marked as deleted
} User;

// Function to initialize a user
void user_init(User *user, int id, const char *name);

// Function to print user information
void user_print_info(const User *user);

#endif