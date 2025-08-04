#include "user.h"
#include "transaction.h"
#include <stdio.h>
#include <string.h>

void user_init(User *user, int id, const char *name) {
    if (user == NULL) {
        printf("Error: Invalid user pointer.\n");
        return;
    }
    user->id = id;
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0';
    user->is_deleted = false;
}

void user_print_info(const User *user) {
    if (user == NULL) {
        printf("Error: Invalid user pointer.\n");
        return;
    }
    printf("User ID: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Status: %s\n", user->is_deleted ? "Deleted" : "Active");
}

// Hàm xóa mềm người dùng. Trả về 1 nếu thành công, 0 nếu thất bại.
int user_delete(User *user, const Transaction *transactions, int transaction_count) {
    if (user == NULL) {
        printf("Error: Invalid user pointer.\n");
        return 0;
    }
    // Kiểm tra xem người dùng có đang mượn sách nào không
    for (int i = 0; i < transaction_count; i++) {
        // So sánh địa chỉ con trỏ để kiểm tra chính xác
        if (transactions[i].user == user && transactions[i].is_active) {
            printf("Error: Cannot delete user '%s' (ID: %d) because they currently have borrowed books.\n", user->name, user->id);
            return 0;
        }
    }
    user->is_deleted = true;
    printf("User '%s' (ID: %d) marked as deleted.\n", user->name, user->id);
    return 1;
}


// Hàm mới: Chỉnh sửa thông tin người dùng
void user_edit(User *user, const char *new_name) {
    if (user == NULL) {
        printf("Error: Invalid user pointer.\n");
        return;
    }
    if (new_name != NULL) {
        strncpy(user->name, new_name, MAX_NAME_LENGTH - 1);
        user->name[MAX_NAME_LENGTH - 1] = '\0';
    }
    printf("User '%s' (ID: %d) edited successfully.\n", user->name, user->id);
}