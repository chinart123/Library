// src/book.c

#include "../include/book.h"           // brings in Book, FunctionResult, definitions
#include <stdio.h>
#include <string.h>
#include "../include/transaction.h"    // real Transaction type
#include "../include/timeline.h"       // timeline_add_event()


void book_init(Book *book, int id, const char *title, const char *author) {
    if (!book || !title || !author) {
        printf("Error: Invalid book, title, or author pointer.\n");
        return;
    }
    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';
    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
    book->is_deleted = false;
    timeline_add_event(EVENT_BOOK_CREATE, id, 0);
}

FunctionResult book_edit(Book *book, const char *new_title, const char *new_author, EventType *event_type_ptr) {
    if (!book) return RESULT_FAILED_INVALID_INPUT;

    if (new_title && strcmp(book->title, new_title) != 0) {
        strncpy(book->title, new_title, MAX_TITLE_LENGTH - 1);
        book->title[MAX_TITLE_LENGTH - 1] = '\0';
        timeline_add_event(EVENT_BOOK_EDIT_TITLE, book->id, 0);
    }
    if (new_author && strcmp(book->author, new_author) != 0) {
        strncpy(book->author, new_author, MAX_AUTHOR_LENGTH - 1);
        book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
        timeline_add_event(EVENT_BOOK_EDIT_AUTHOR, book->id, 0);
    }
    return RESULT_SUCCESS;
}

FunctionResult book_delete(Book *book, const Transaction transactions[], int count) {
    if (!book) {
        printf("Error: Invalid book pointer.\n");
        return RESULT_FAILED_INVALID_INPUT;
    }
    if (book_is_borrowed(book, transactions, count)) {
        printf("Error: Book '%s' (ID: %d) cannot be deleted, it is currently borrowed.\n",
               book->title, book->id);
        return RESULT_FAILED_ACTIVE_TRANSACTION;
    }
    book->is_deleted = true;
    timeline_add_event(EVENT_BOOK_DELETE, book->id, 0);
    return RESULT_SUCCESS;
}

FunctionResult book_restore(Book *book) {
    if (!book) {
        printf("Error: Invalid book pointer.\n");
        return RESULT_FAILED_INVALID_INPUT;
    }
    book->is_deleted = false;
    timeline_add_event(EVENT_BOOK_RESTORE, book->id, 0);
    return RESULT_SUCCESS;
}

void book_print_info(const Book *book) {
    if (!book) {
        printf("Error: Invalid book pointer.\n");
        return;
    }
    printf("Book ID: %d, Title: %s, Author: %s, Status: %s\n",
           book->id, book->title, book->author,
           book->is_deleted ? "[DELETED]" : "Active");
}

bool book_is_borrowed(const Book *book, const Transaction transactions[], int count) {
    if (!book) return false;
    for (int i = 0; i < count; i++) {
        if (transactions[i].book->id == book->id && transactions[i].is_active)
            return true;
    }
    return false;
}
