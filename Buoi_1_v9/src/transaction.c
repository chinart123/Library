// src/transaction.c

#include "../include/transaction.h"    // forward decls for Book/User, Transaction, FunctionResult
#include "../include/book.h"           // real Book
#include "../include/user.h"           // real User
#include "../include/timeline.h"       // timeline_add_event()
#include <stdio.h>

void transaction_init(Transaction transactions[], int *count) {
    *count = 0;
}

FunctionResult transaction_borrow(Transaction transactions[], int *count, Book *book, User *user) {
    if (!book || !user || book->is_deleted || user->is_deleted) {
        printf("Error: Invalid book or user, or already deleted.\n");
        timeline_add_event(EVENT_BORROW_FAILED_LIMIT,
                           book ? book->id : 0,
                           user ? user->id : 0);
        return RESULT_FAILED_INVALID_INPUT;
    }
    if (*count >= MAX_TRANSACTIONS) {
        printf("Error: Maximum transactions reached.\n");
        timeline_add_event(EVENT_BORROW_FAILED_LIMIT, book->id, user->id);
        return RESULT_FAILED_INVALID_INPUT;
    }
    if (book_is_borrowed(book, transactions, *count)) {
        printf("Error: Book ID %d is already borrowed.\n", book->id);
        timeline_add_event(EVENT_BORROW_FAILED_LIMIT, book->id, user->id);
        return RESULT_FAILED_ACTIVE_TRANSACTION;
    }

    int borrowed_count = 0;
    for (int i = 0; i < *count; i++) {
        if (transactions[i].user->id == user->id && transactions[i].is_active)
            borrowed_count++;
    }
    if (borrowed_count >= MAX_BOOKS_PER_USER) {
        printf("Error: User '%s' reached borrow limit (%d).\n",
               user->name, MAX_BOOKS_PER_USER);
        timeline_add_event(EVENT_BORROW_FAILED_LIMIT, book->id, user->id);
        return RESULT_FAILED_ACTIVE_TRANSACTION;
    }

    transactions[*count].id       = *count + 1;
    transactions[*count].book     = book;
    transactions[*count].user     = user;
    transactions[*count].is_active = true;
    (*count)++;
    timeline_add_event(EVENT_BORROW, book->id, user->id);
    return RESULT_SUCCESS;
}

FunctionResult transaction_return(Transaction transactions[], int *count, Book *book, User *user) {
    if (!book || !user) {
        printf("Error: Invalid book or user pointer.\n");
        return RESULT_FAILED_INVALID_INPUT;
    }
    for (int i = 0; i < *count; i++) {
        if (transactions[i].book->id == book->id
         && transactions[i].user->id == user->id
         && transactions[i].is_active) {
            transactions[i].is_active = false;
            printf("Success: Book '%s' returned by User '%s'.\n",
                   book->title, user->name);
            timeline_add_event(EVENT_RETURN, book->id, user->id);
            return RESULT_SUCCESS;
        }
    }
    printf("Error: No active transaction for this book/user.\n");
    return RESULT_FAILED_NOT_FOUND;
}

void transaction_print_active(const Transaction transactions[], int count) {
    printf("\n=== ACTIVE TRANSACTIONS ===\n");
    for (int i = 0; i < count; i++) {
        if (transactions[i].is_active
         && !transactions[i].book->is_deleted
         && !transactions[i].user->is_deleted) {
            printf("Transaction ID: %d\n", transactions[i].id);
            printf("  Book: %s (ID: %d)\n",
                   transactions[i].book->title,
                   transactions[i].book->id);
            printf("  User: %s (ID: %d)\n\n",
                   transactions[i].user->name,
                   transactions[i].user->id);
        }
    }
}

void transaction_print_user_history(const Transaction transactions[], int count, const User *user) {
    if (!user) {
        printf("Error: Invalid user pointer.\n");
        return;
    }
    printf("\n=== HISTORY FOR USER %s (ID: %d) ===\n", user->name, user->id);
    for (int i = 0; i < count; i++) {
        if (transactions[i].user && transactions[i].user->id == user->id) {
            printf("Transaction ID: %d\n", transactions[i].id);
            if (transactions[i].book) {
                printf("  Book: %s (ID: %d)%s\n",
                       transactions[i].book->title,
                       transactions[i].book->id,
                       transactions[i].book->is_deleted ? " [DELETED]" : "");
            }
            printf("  Status: %s\n\n",
                   transactions[i].is_active ? "Borrowed" : "Returned");
        }
    }
}
