// include/transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "definitions.h"
#include "flags.h"

struct Transaction {
    int id;             // Mã giao dịch
    Book* book;         // Con trỏ đến sách
    User* user;         // Con trỏ đến người mượn
    uint8_t flags;     // Dùng bitflags thay cho is_deleted
};


#endif // TRANSACTION_H
