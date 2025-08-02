#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 

int main() {
    // Initialize data
    Book books[4];
    book_init(&books[0], 1, "Book1", "Author1");
    book_init(&books[1], 2, "Book2", "Author2");
    book_init(&books[2], 3, "Book3", "Author3");
    book_init(&books[3], 4, "Book4", "Author4");

    User users[4];
    user_init(&users[0], 1, "User1");
    user_init(&users[1], 2, "User2");
    user_init(&users[2], 3, "User3");
    user_init(&users[3], 4, "User4");

    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    EventType event_type;
    
    printf("===== STAGE 7: COMPREHENSIVE EDIT TESTING =====\n\n");

    // Setup transactions
    printf("=== SETUP: INITIAL TRANSACTIONS ===\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
    transaction_return(transactions, &transaction_count, &books[1], &users[1]);
    printf("\n");

    // Test 1: Active transactions
    printf("=== TEST 1: ACTIVE TRANSACTIONS ===\n");
    book_edit(&books[0], "Book1_NewTitle", NULL, &event_type);
    user_edit(&users[0], "User1_NewName");
    transaction_print_active(transactions, transaction_count);
    
    // Test 2: Transaction history
    printf("=== TEST 2: TRANSACTION HISTORY ===\n");
    book_edit(&books[1], "Book2_NewTitle", "Author2_New", &event_type);
    user_edit(&users[1], "User2_NewName");
    transaction_print_user_history(transactions, transaction_count, &users[1]);

    // Test 3: Soft-deleted objects
    printf("=== TEST 3: SOFT-DELETED OBJECTS ===\n");
    book_delete(&books[3], transactions, transaction_count);
    user_delete(&users[3], transactions, transaction_count);
    book_edit(&books[3], "Book4_Deleted", "Author4_New", &event_type);
    user_edit(&users[3], "User4_Deleted");
    book_print_info(&books[3]);
    user_print_info(&users[3]);
    printf("\n");

    // Test 4: Invalid inputs
    printf("=== TEST 4: INVALID INPUTS ===\n");
    book_edit(NULL, "Invalid", "Input", &event_type);
    user_edit(&users[0], NULL);
    printf("User1 name after NULL edit: %s\n", users[0].name);

    printf("\nPress any key to exit...");
    getchar();

    return 0;
}