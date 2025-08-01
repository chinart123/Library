#ifndef BOOK_H
#define BOOK_H

#include "definitions.h"

// Định nghĩa struct Book
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    bool is_deleted;
} Book;

// Khai báo forward cho struct Transaction để tránh lỗi cyclic include
typedef struct Transaction Transaction;

// Khai báo các hàm liên quan đến sách
void book_init(Book *book, int id, const char *title, const char *author);
void book_edit(Book *book, const char *new_title, const char *new_author);
// Khai báo hàm với con trỏ thay cho mảng
void book_delete(Book *book, const Transaction *transactions, int transaction_count);
//SUPPORT Test10.c
void book_restore(Book *book);
void book_print_info(const Book *book);

#endif