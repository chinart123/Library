#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>
#include "definitions.h"
// Forward declaration to avoid circular dependency
struct Transaction;

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    bool is_deleted;
} Book;

void book_init(Book *book, int id, const char *title, const char *author);
void book_print_info(const Book *book);
// Changed from [] to * to fix compilation error
int book_delete(Book *book, const struct Transaction *transactions, int transaction_count);

#endif