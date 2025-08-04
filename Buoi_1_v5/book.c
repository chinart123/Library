#include "book.h"
#include <stdio.h>
#include <string.h>

void book_init(Book *book, int id, const char *title, const char *author) {
    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    book->is_deleted = false; // Initialize to not deleted
}

void book_print_info(const Book *book) {
    printf("Book ID: %d\n", book->id);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Status: %s\n", book->is_deleted ? "Deleted" : "Active"); // Print status
}