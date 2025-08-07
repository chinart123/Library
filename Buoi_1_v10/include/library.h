#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h"
#include "timeline.h"



typedef struct {
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    Transaction transactions[MAX_TRANSACTIONS];
    int book_count;
    int user_count;
    int transaction_count;
} Library;

#endif // LIBRARY_H
