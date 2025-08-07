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
    printf("STAGE 13: BORROW LIMIT & EDIT TEST\n");
    printf("========================================================\n");

    // ====================================================================
    // AREA 1: BORROWING LIMIT TEST
    // ====================================================================
    printf("\n--- AREA 1: BORROWING LIMITS (MAX 3 PER USER) ---\n");

    // Setup
    book_init(&books[book_count++], 1, "Book1", "Author1");
    book_init(&books[book_count++], 2, "Book2", "Author2");
    book_init(&books[book_count++], 3, "Book3", "Author3");
    book_init(&books[book_count++], 4, "Book4", "Author4");
    user_init(&users[user_count++], 1, "User1");
    
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
    // FINAL TEST: PRINT TIMELINE
    // ====================================================================
    printf("\n--- FINAL TIMELINE ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF TEST 13\n");
    printf("========================================================\n");

    getchar();
    return 0;
}