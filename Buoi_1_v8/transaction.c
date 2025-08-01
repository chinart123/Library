#include "transaction.h"
#include <stdio.h>
#include "book.h"
#include "user.h"
#include "timeline/timeline.h"

void transaction_init(Transaction transactions[], int *count) {
    *count = 0;
}

int transaction_borrow(Transaction transactions[], int *count, Book *book, User *user) {
    if (book == NULL || user == NULL || book->is_deleted || user->is_deleted) {
        printf("Error: Invalid book or user pointer, or book/user is deleted.\n");
        return 0;
    }
    if (*count >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return 0;
    }
    for (int i = 0; i < *count; i++) {
        if (transactions[i].book->id == book->id && transactions[i].is_active) {
            printf("Error: Book ID %d is already borrowed.\n", book->id);
            return 0;
        }
    }
    int borrowed_count = 0;
    for (int i = 0; i < *count; i++) {
        if (transactions[i].user->id == user->id && transactions[i].is_active) {
            borrowed_count++;
        }
    }
    if (borrowed_count >= MAX_BOOKS_PER_USER) {
        printf("Error: User '%s' has reached borrowing limit (%d books).\n", user->name, MAX_BOOKS_PER_USER);
        timeline_add_event(EVENT_BORROW_FAILED_LIMIT, book->id, user->id); // THÊM DÒNG NÀY support for test13.c
        return 0;
    }
    transactions[*count].id = *count + 1;
    transactions[*count].book = book;
    transactions[*count].user = user;
    transactions[*count].is_active = true;
    (*count)++;
    printf("Transaction successful: User '%s' borrowed '%s'\n", user->name, book->title);
    timeline_add_event(EVENT_BORROW, book->id, user->id);
    return 1;
}

int transaction_return(Transaction transactions[], int *count, Book *book, User *user) {
    if (book == NULL || user == NULL || book->is_deleted || user->is_deleted) {
        printf("Error: Invalid book or user pointer, or book/user is deleted.\n");
        return 0;
    }
    for (int i = 0; i < *count; i++) {
        if (transactions[i].book->id == book->id && transactions[i].user->id == user->id && transactions[i].is_active) {
            transactions[i].is_active = false;
            printf("Transaction successful: User '%s' returned '%s'\n", user->name, book->title);
            timeline_add_event(EVENT_RETURN, book->id, user->id);
            return 1;
        }
    }
    printf("Error: No active transaction found for this book and user.\n");
    return 0;
}

void transaction_print_active(const Transaction transactions[], int count) {
    printf("\n============================== ACTIVE TRANSACTIONS ==============================\n");
    for (int i = 0; i < count; i++) {
        if (transactions[i].is_active && !transactions[i].book->is_deleted && !transactions[i].user->is_deleted) {
            printf("Transaction ID: %d\n", transactions[i].id);
            printf("Book: %s (ID: %d)\n", transactions[i].book->title, transactions[i].book->id);
            printf("User: %s (ID: %d)\n\n", transactions[i].user->name, transactions[i].user->id);
        }
    }
}

void transaction_print_user_history(const Transaction transactions[], int count, const User *user) {
    printf("\n=== TRANSACTION HISTORY FOR USER %s (ID: %d) ===\n", user->name, user->id);
    for (int i = 0; i < count; i++) {
        if (transactions[i].user->id == user->id) {
            printf("Transaction ID: %d\n", transactions[i].id);
            if (transactions[i].book->is_deleted) {
                printf("Book: %s (ID: %d) [DELETED]\n", transactions[i].book->title, transactions[i].book->id);
            } else {
                printf("Book: %s (ID: %d)\n", transactions[i].book->title, transactions[i].book->id);
            }
            printf("Status: %s\n\n", transactions[i].is_active ? "Active" : "Returned");
        }
    }
}