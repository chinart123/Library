#include "../include/user.h"
#include "../include/timeline.h"
#include "../include/flags.h"
#include <stdio.h>
#include <string.h>

void user_init(User* user, int id, const char* name) {
    if (!user || !name) return;

    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';

    user->flags = 0;
    set_flag(&user->flags, USER_FLAG_ACTIVE);  // Bật trạng thái ACTIVE

    timeline_add_event(EVENT_USER_CREATE, 0, id);
}

void user_print_info(const User* user) {
    if (!user) return;

    printf("User ID: %d | Name: %s | Status: %s\n",
           user->id,
           user->name,
           has_flag(user->flags, USER_FLAG_DELETED) ? "[DELETED]" : "Active");
}
