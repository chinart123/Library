// include/book.h
#ifndef BOOK_H
#define BOOK_H

#include "definitions.h"

struct Book {
    int id;                           // Mã sách
    char title[MAX_TITLE_LENGTH];    // Tên sách
    char author[MAX_AUTHOR_LENGTH];  // Tác giả
    bool is_deleted;                 // Đã bị xoá mềm chưa
};

#endif // BOOK_H
