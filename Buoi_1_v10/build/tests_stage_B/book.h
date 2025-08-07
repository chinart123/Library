// include/book.h
#ifndef BOOK_H
#define BOOK_H

#include "definitions.h"
#include "flags.h"

struct Book {
    int id;                           // Mã sách
    char title[MAX_TITLE_LENGTH];    // Tên sách
    char author[MAX_AUTHOR_LENGTH];  // Tác giả
    uint8_t flags;  // Dùng bitflags thay cho is_deleted
};

#endif // BOOK_H
