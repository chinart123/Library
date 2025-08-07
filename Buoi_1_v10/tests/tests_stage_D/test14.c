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
    printf("STAGE 14: SOFT DELETE TEST\n");
    printf("========================================================\n");

    // ====================================================================
    // AREA 1: BORROWING LIMIT TEST
    // ====================================================================
    printf("\n--- AREA 1: BORROWING LIMITS ---\n");

    // Setup
    book_init(&books[book_count++], 1, "Book1", "Author1");
    book_init(&books[book_count++], 2, "Book2", "Author2");
    book_init(&books[book_count++], 3, "Book3", "Author3");
    book_init(&books[book_count++], 4, "Book4", "Author4");
    user_init(&users[user_count++], 1, "User1");
    user_init(&users[user_count++], 2, "User2");
    
    // Borrow books
    printf("\n[TEST 1.1] Borrow Book1, Book2, Book3\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[1], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[2], &users[0]);
    
    // Attempt to borrow fourth book
    printf("\n[TEST 1.2] Borrow Book4 (should fail)\n");
    transaction_borrow(transactions, &transaction_count, &books[3], &users[0]);
    
    // Print status
    printf("\n[TEST 1.3] Current status:\n");
    user_print_info(&users[0]);
    transaction_print_active(transactions, transaction_count);
    
    // Print timeline
    printf("\n--- TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // AREA 2: EDIT TEST
    // ====================================================================
    printf("\n--- AREA 2: EDIT OPERATIONS ---\n");
    
    // Return a book
    printf("\n[PREP] Return Book1\n");
    transaction_return(transactions, &transaction_count, &books[0], &users[0]);

    // Edit User1
    printf("\n[TEST 2.1] Edit User1\n");
    user_print_info(&users[0]);
    user_edit(&users[0], "User1_Updated");
    user_print_info(&users[0]);

    // Edit Book1
    printf("\n[TEST 2.2] Edit Book1\n");
    book_edit(&books[0], "Book1_Updated", "Author1_Updated", &event_type);
    book_print_info(&books[0]);
    
    // Print timeline
    printf("\n--- TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // AREA 3: SOFT DELETE TEST
    // ====================================================================
    printf("\n--- AREA 3: SOFT DELETE OPERATIONS ---\n");
    
    // Delete Book4 (not borrowed)
    printf("\n[TEST 3.1] Delete Book4\n");
    book_delete(&books[3], transactions, transaction_count);
    book_print_info(&books[3]);
    
    // Delete User2 (no transactions)
    printf("\n[TEST 3.2] Delete User2\n");
    user_delete(&users[1], transactions, transaction_count);
    user_print_info(&users[1]);

    // Attempt to delete borrowed book
    printf("\n[TEST 3.3] Delete Book2 (should fail)\n");
    book_delete(&books[1], transactions, transaction_count);
    book_print_info(&books[1]);

    // Print timeline
    printf("\n--- TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // FINAL TEST: PRINT TIMELINE
    // ====================================================================
    printf("\n--- FINAL TIMELINE ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF TEST 14\n");
    printf("========================================================\n");

    getchar();
    return 0;
}