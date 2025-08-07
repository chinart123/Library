#include "../include/book.h"
#include "../include/timeline.h"
#include <stdio.h>
#include <string.h>

// Khởi tạo sách mới
void book_init(Book* book, int id, const char* title, const char* author) {
    if (!book || !title || !author) return;

    book->id = id;

    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';

    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';

    book->is_deleted = false;

    // Ghi sự kiện tạo sách
    timeline_add_event(EVENT_BOOK_CREATE, id, 0);
}

// In thông tin sách
void book_print_info(const Book* book) {
    if (!book) return;

    printf("Book ID: %d | Title: %s | Author: %s | Status: %s\n",
           book->id,
           book->title,
           book->author,
           book->is_deleted ? "[DELETED]" : "Active");
}
