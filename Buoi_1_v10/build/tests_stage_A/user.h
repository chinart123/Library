// include/user.h
#ifndef USER_H
#define USER_H

#include "definitions.h"

struct User {
    int id;                         // Mã người dùng
    char name[MAX_NAME_LENGTH];    // Tên người dùng
    bool is_deleted;               // Đã bị xoá mềm hay chưa
};

#endif // USER_H
