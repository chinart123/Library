#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <stdbool.h>
#include "definitions.h"

// Include full definitions after forward declarations
#include "book.h"
#include "user.h"

typedef struct Transaction {
    int id;
    Book *book;
    User *user;
    bool is_active;
} Transaction;

// Function declarations
void transaction_init(Transaction *transactions, int *count);
FunctionResult transaction_borrow(Transaction *transactions, int *count, Book *book, User *user);
FunctionResult transaction_return(Transaction *transactions, int *count, Book *book, User *user);
void transaction_print_active(const Transaction *transactions, int count);
void transaction_print_user_history(const Transaction *transactions, int count, const User *user);

#endif // TRANSACTION_H