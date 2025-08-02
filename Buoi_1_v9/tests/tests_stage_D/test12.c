#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 
#include "timeline.h"  // Added missing include

int main() {
    // Initialize core data arrays
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    int book_count = 0;
    int user_count = 0;
    EventType event_type;  // Added for book_edit
    
    // Initialize timeline
    timeline_init();

    printf("\n========================================================\n");
    printf("STAGE 12: COMPREHENSIVE INTEGRATION TEST\n");
    printf("========================================================\n");

    // ====================================================================
    // AREA 1: BASIC FUNCTIONALITIES & SOFT DELETE
    // ====================================================================
    printf("\n--- AREA 1: INIT, BORROW, RETURN, SOFT DELETE ---\n");

    // Setup
    book_init(&books[book_count++], 1, "Book1", "Author1");
    book_init(&books[book_count++], 2, "Book2", "Author2");
    user_init(&users[user_count++], 1, "User1");
    user_init(&users[user_count++], 2, "User2");
    
    // Create transactions
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);

    // Test 1.1: Active transactions
    printf("\n[TEST 1.1] Active transactions:\n");
    transaction_print_active(transactions, transaction_count);

    // Test 1.2: Return and delete Book1
    printf("\n[TEST 1.2] Return and delete Book1\n");
    transaction_return(transactions, &transaction_count, &books[0], &users[0]);
    book_delete(&books[0], transactions, transaction_count);

    // Test 1.3: Delete User1
    printf("\n[TEST 1.3] Delete User1\n");
    user_delete(&users[0], transactions, transaction_count);

    // Test 1.4: Borrow deleted book
    printf("\n[TEST 1.4] Borrow deleted book (should fail)\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[1]);

    // ====================================================================
    // AREA 2: EDIT FUNCTIONALITIES
    // ====================================================================
    printf("\n--- AREA 2: EDIT FUNCTIONALITY ---\n");

    // Test 2.1: Edit Book2
    printf("\n[TEST 2.1] Edit Book2\n");
    book_edit(&books[1], "Book2_NewTitle", NULL, &event_type);
    book_print_info(&books[1]);

    // Test 2.2: Edit User2
    printf("\n[TEST 2.2] Edit User2\n");
    user_edit(&users[1], "User2_Updated");
    user_print_info(&users[1]);

    // Test 2.3: Edit deleted user
    printf("\n[TEST 2.3] Edit deleted user\n");
    user_edit(&users[0], "User1_Updated");
    user_print_info(&users[0]);

    // ====================================================================
    // FINAL TEST: PRINT TIMELINE
    // ====================================================================
    printf("\n--- FINAL: TIMELINE EVENTS ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF TEST 12\n");
    printf("========================================================\n");

    getchar();
    return 0;
}