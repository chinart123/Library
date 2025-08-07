#include "../include/book.h"
#include "../include/timeline.h"
#include "../include/flags.h"
#include <stdio.h>
#include <string.h>

void book_init(Book* book, int id, const char* title, const char* author) {
    if (!book || !title || !author) return;

    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';

    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';

    book->flags = 0;
    set_flag(&book->flags, BOOK_FLAG_ACTIVE);  // Bật trạng thái ACTIVE

    timeline_add_event(EVENT_BOOK_CREATE, id, 0);
}

void book_print_info(const Book* book) {
    if (!book) return;

    printf("Book ID: %d | Title: %s | Author: %s | Status: %s\n",
           book->id,
           book->title,
           book->author,
           has_flag(book->flags, BOOK_FLAG_DELETED) ? "[DELETED]" : "Active");
}
