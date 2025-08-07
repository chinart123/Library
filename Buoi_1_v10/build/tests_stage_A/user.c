#include "../include/user.h"
#include "../include/timeline.h"
#include <stdio.h>
#include <string.h>

// Khởi tạo user mới
void user_init(User* user, int id, const char* name) {
    if (!user || !name) return;

    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';
    user->is_deleted = false;

    // Ghi sự kiện tạo user
    timeline_add_event(EVENT_USER_CREATE, 0, id);
}

// In thông tin người dùng
void user_print_info(const User* user) {
    if (!user) return;

    printf("User ID: %d | Name: %s | Status: %s\n",
           user->id,
           user->name,
           user->is_deleted ? "[DELETED]" : "Active");
}
