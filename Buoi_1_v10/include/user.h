// include/user.h
#ifndef USER_H
#define USER_H

#include "definitions.h"
#include "flags.h"

struct User {
    int id;                         // Mã người dùng
    char name[MAX_NAME_LENGTH];    // Tên người dùng
    uint8_t flags;                  // Dùng bitflags thay cho is_deleted
};


#endif // USER_H
