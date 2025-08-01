#include "book.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "transaction.h"
#include "timeline/timeline.h"

void book_init(Book *book, int id, const char *title, const char *author) {
    if (book == NULL) {
        printf("Error: Book pointer is NULL.\n");
        return;
    }
    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';
    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
    book->is_deleted = false;
    printf("Book created: ID %d, Title: %s\n", book->id, book->title);
    timeline_add_event(EVENT_BOOK_CREATE, book->id, -1);//SUPPORT FOR test10.c
}

void book_edit(Book *book, const char *new_title, const char *new_author) {
    if (book == NULL) {
        printf("Error: Book pointer is NULL.\n");
        return;
    }
    printf("Editing book ID %d...\n", book->id);
    
    // Kiểm tra và cập nhật tiêu đề
    if (new_title != NULL && strcmp(new_title, "") != 0 && strcmp(book->title, new_title) != 0) {
        strncpy(book->title, new_title, MAX_TITLE_LENGTH - 1);
        book->title[MAX_TITLE_LENGTH - 1] = '\0';
        timeline_add_event(EVENT_BOOK_EDIT_TITLE, book->id, -1); // THÊM DÒNG NÀY
    }
    
    // Kiểm tra và cập nhật tác giả
    if (new_author != NULL && strcmp(new_author, "") != 0 && strcmp(book->author, new_author) != 0) {
        strncpy(book->author, new_author, MAX_AUTHOR_LENGTH - 1);
        book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
        timeline_add_event(EVENT_BOOK_EDIT_AUTHOR, book->id, -1); // THÊM DÒNG NÀY
    }
    printf("Book ID %d updated.\n", book->id);
}

// Định nghĩa hàm đã được sửa để khớp với khai báo trong book.h
void book_delete(Book *book, const Transaction *transactions, int transaction_count) {
    if (book == NULL) {
        printf("Error: Book pointer is NULL.\n");
        return;
    }
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].book->id == book->id && transactions[i].is_active) {
            printf("Error: Cannot delete book ID %d. It is currently borrowed.\n", book->id);
            return;
        }
    }
    book->is_deleted = true;
    timeline_add_event(EVENT_BOOK_DELETE, book->id, -1);
    printf("Book ID %d has been soft-deleted.\n", book->id);
}

void book_print_info(const Book *book) {
    if (book == NULL) {
        printf("Book info: NULL\n");
        return;
    }
    printf("--- Book Info ---\n");
    printf("ID: %d\n", book->id);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Status: %s\n", book->is_deleted ? "Deleted" : "Active");
}


// SUPPORT Test10.c
void book_restore(Book *book) {
    if (book == NULL) {
        printf("Error: Book pointer is NULL.\n");
        return;
    }
    if (!book->is_deleted) {
        printf("Book ID %d is not deleted. No need to restore.\n", book->id);
        return;
    }
    book->is_deleted = false;
    timeline_add_event(EVENT_BOOK_RESTORE, book->id, -1);
    printf("Book ID %d has been restored.\n", book->id);
}