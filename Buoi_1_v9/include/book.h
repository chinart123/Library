#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>
#include "definitions.h"

typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    bool is_deleted;
} Book;

// Use forward declaration for Transaction
typedef struct Transaction Transaction;

// Function declarations
void book_init(Book *book, int id, const char *title, const char *author);
FunctionResult book_edit(Book *book, const char *new_title, const char *new_author, EventType *event_type_ptr);
FunctionResult book_delete(Book *book, const Transaction *transactions, int count);
FunctionResult book_restore(Book *book);
void book_print_info(const Book *book);
bool book_is_borrowed(const Book *book, const Transaction *transactions, int count);

#endif // BOOK_H