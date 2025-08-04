#include "transaction.h"
#include <stdio.h>

void transaction_init(Transaction transactions[], int *count) {
    *count = 0;
}

int transaction_borrow(Transaction transactions[], int *count, Book *book, User *user) {
    // Kiểm tra book và user hợp lệ và không bị xóa
    if (book == NULL || user == NULL || book->is_deleted || user->is_deleted) {
        printf("Error: Invalid book or user, or book/user is deleted.\n");
        return 0;
    }

    // Kiểm tra sách đã được mượn chưa
    for (int i = 0; i < *count; i++) {
        if (transactions[i].book->id == book->id && transactions[i].is_active) {
            printf("Error: Book ID %d is already borrowed.\n", book->id);
            return 0;
        }
    }

    // Đếm số sách user đang mượn
    int borrowed_count = 0;
    for (int i = 0; i < *count; i++) {
        if (transactions[i].user->id == user->id && transactions[i].is_active) {
            borrowed_count++;
        }
    }

    // Kiểm tra giới hạn mượn sách
    if (borrowed_count >= MAX_BOOKS_PER_USER) {
        printf("Error: User '%s' has reached borrowing limit (%d books).\n", 
               user->name, MAX_BOOKS_PER_USER);
        return 0;
    }


    // Create new transaction
    transactions[*count].id = *count + 1;
    transactions[*count].book = book;
    transactions[*count].user = user;
    transactions[*count].is_active = true;
    
    (*count)++;
    printf("Transaction successful: User '%s' borrowed '%s'\n", user->name, book->title);
    return 1;
}

int transaction_return(Transaction transactions[], int *count, Book *book, User *user) {
    // Kiểm tra con trỏ hợp lệ và không bị xóa
    if (book == NULL || user == NULL || book->is_deleted || user->is_deleted) {
        printf("Error: Invalid book or user pointer, or book/user is deleted.\n");
        return 0;
    }
    
    for (int i = 0; i < *count; i++) {
        if (transactions[i].book->id == book->id && 
            transactions[i].user->id == user->id &&
            transactions[i].is_active) {
            
            transactions[i].is_active = false;
            printf("Transaction successful: User '%s' returned '%s'\n", user->name, book->title);
            return 1;
        }
    }
    
    printf("Error: No active transaction found for this book and user.\n");
    return 0;
}

void transaction_print_active(const Transaction transactions[], int count) {
    printf("\n=== ACTIVE TRANSACTIONS ===\n");
    for (int i = 0; i < count; i++) {
        // Only print if book and user are not deleted
        if (transactions[i].is_active && !transactions[i].book->is_deleted && !transactions[i].user->is_deleted) {
            printf("Transaction ID: %d\n", transactions[i].id);
            printf("Book: %s (ID: %d)\n", transactions[i].book->title, transactions[i].book->id);
            printf("User: %s (ID: %d)\n\n", transactions[i].user->name, transactions[i].user->id);
        }
    }
}

void transaction_print_user_history(const Transaction transactions[], int count, const User *user) {
    // Only print if user is not deleted
    if (user->is_deleted) {
        printf("\n=== TRANSACTION HISTORY FOR DELETED USER %s (ID: %d) ===\n", user->name, user->id);
        return;
    }
    printf("\n=== TRANSACTION HISTORY FOR USER %s (ID: %d) ===\n", user->name, user->id);
    for (int i = 0; i < count; i++) {
        if (transactions[i].user->id == user->id) {
            // Only print if the associated book is not deleted
            if (!transactions[i].book->is_deleted) {
                printf("Transaction ID: %d\n", transactions[i].id);
                printf("Book: %s (ID: %d)\n", transactions[i].book->title, transactions[i].book->id);
                printf("Status: %s\n\n", transactions[i].is_active ? "Active" : "Returned");
            } else {
                printf("Transaction ID: %d\n", transactions[i].id);
                printf("Book: %s (ID: %d) [DELETED]\n", transactions[i].book->title, transactions[i].book->id);
                printf("Status: %s\n\n", transactions[i].is_active ? "Active" : "Returned");
            }
        }
    }
}