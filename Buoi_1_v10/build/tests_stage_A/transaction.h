// include/transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "definitions.h"

struct Transaction {
    int id;             // Mã giao dịch
    Book* book;         // Con trỏ đến sách
    User* user;         // Con trỏ đến người mượn
    bool is_active;     // true = đang mượn, false = đã trả
};

#endif // TRANSACTION_H
