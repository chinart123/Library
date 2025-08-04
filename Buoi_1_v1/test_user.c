#include "user.h"
#include <stdio.h>

int main() {
    User users[MAX_USERS];
    int user_count = 0;
    
    // Test user functions
    add_user(users, &user_count, 101, "Alice Johnson", 1);
    add_user(users, &user_count, 102, "Bob Smith", 3);
    
    print_all_users(users, user_count);
    print_users_by_name(users, user_count, "Smith");
    
    return 0;
}