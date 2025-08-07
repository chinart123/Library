#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "timeline/timeline.h"
#include "definitions.h"

int main() {
    // Initialize core data arrays
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    int book_count = 0;
    int user_count = 0;
    
    // Initialize timeline
    timeline_init();

    printf("\n========================================================================\n");
    printf("STAGE 14: COMPREHENSIVE INTEGRATION TEST (WITH DELETE FUNCTIONS)\n");
    printf("Expected: The system should correctly handle all operations, including soft deletes.\n");
    printf("========================================================================\n");

    // ====================================================================
    // AREA 1: BORROWING LIMIT TEST
    // ====================================================================
    printf("\n--- AREA 1: TESTING BORROWING LIMITS (MAX_BOOKS_PER_USER = 3) ---\n");

    // [SETUP] Create 4 books and 2 users for the test
    book_init(&books[book_count++], 1, "Book 1", "Author 1");
    book_init(&books[book_count++], 2, "Book 2", "Author 2");
    book_init(&books[book_count++], 3, "Book 3", "Author 3");
    book_init(&books[book_count++], 4, "Book 4", "Author 4");
    user_init(&users[user_count++], 1, "User 1");
    user_init(&users[user_count++], 2, "User 2"); // New user for later tests
    
    // User 1 borrows 3 books
    printf("\n[TEST 1.1] User 1 borrows Book 1, Book 2, and Book 3.\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[1], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[2], &users[0]);
    
    // User 1 attempts to borrow a 4th book (should fail)
    printf("\n[TEST 1.2] User 1 attempts to borrow Book 4.\n");
    printf("Expected: Transaction should fail and a 'borrow failed' event is recorded.\n");
    transaction_borrow(transactions, &transaction_count, &books[3], &users[0]);
    
    // In thông tin để xác nhận trạng thái sau khi mượn
    printf("\n[TEST 1.3] Printing user and transaction info after borrow attempts.\n");
    printf("Expected: User 1 has 3 active transactions, the last one failed.\n");
    user_print_info(&users[0]);
    transaction_print_active(transactions, transaction_count);
    
    // In toàn bộ timeline của Area 1
    printf("\n--- AREA 1: TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // AREA 2: EDIT TEST
    // ====================================================================
    printf("\n--- AREA 2: TESTING EDIT OPERATIONS FOR USER & BOOK ---\n");
    
    // User 1 returns a book to prepare for a successful edit test
    printf("\n[PREPARATION] User 1 returns Book 1 to free up a slot.\n");
    transaction_return(transactions, &transaction_count, &books[0], &users[0]);

    // Test Case 2.1: Editing User 1's name
    printf("\n[TEST 2.1] Editing User 1's name.\n");
    printf("Expected: User 1's name is updated.\n");
    user_print_info(&users[0]);
    user_edit(&users[0], "User 1 - Edited");
    user_print_info(&users[0]);

    // Test Case 2.2: Editing Book 1's title and author
    printf("\n[TEST 2.2] Editing Book 1's title and author.\n");
    printf("Expected: Book 1's info is updated.\n");
    book_print_info(&books[0]);
    book_edit(&books[0], "Book 1 - Edited", "Author 1 - Edited");
    book_print_info(&books[0]);
    
    // In toàn bộ timeline của Area 2
    printf("\n--- AREA 2: TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // AREA 3: DELETE TEST
    // ====================================================================
    printf("\n--- AREA 3: TESTING SOFT DELETE OPERATIONS FOR USER & BOOK ---\n");
    
    // Test Case 3.1: Soft-delete a book that is NOT borrowed
    printf("\n[TEST 3.1] Attempting to soft-delete Book 4 (not borrowed).\n");
    printf("Expected: Book 4 should be successfully deleted.\n");
    book_delete(&books[3], transactions, transaction_count);
    book_print_info(&books[3]);
    
    // Test Case 3.2: Soft-delete a user that has NO active transactions
    printf("\n[TEST 3.2] Attempting to soft-delete User 2 (no transactions).\n");
    printf("Expected: User 2 should be successfully deleted.\n");
    user_delete(&users[1], transactions, transaction_count);
    user_print_info(&users[1]);

    // Test Case 3.3: Attempt to soft-delete a book that IS borrowed
    printf("\n[TEST 3.3] Attempting to soft-delete Book 2 (currently borrowed by User 1).\n");
    printf("Expected: Delete should fail.\n");
    book_delete(&books[1], transactions, transaction_count);
    book_print_info(&books[1]);

    // In toàn bộ timeline của Area 3
    printf("\n--- AREA 3: TIMELINE SUMMARY ---\n");
    timeline_print_all_events();

    // ====================================================================
    // AREA 4: TIMELINE AND FILTERING
    // ====================================================================
    printf("\n--- AREA 4: TESTING TIMELINE AND FILTERING FUNCTIONS ---\n");

    // [TEST 4.1] Filtering by event type (EVENT_BORROW)
    printf("\n[TEST 4.1] Filtering for 'borrow' events.\n");
    printf("Expected: Only borrow events should be displayed.\n");
    timeline_print_events_by_type(EVENT_BORROW);
    
    // [TEST 4.2] Filtering by book ID (Book 4)
    printf("\n[TEST 4.2] Filtering for events related to Book ID 4.\n");
    printf("Expected: Only create and delete events for Book 4 should be displayed.\n");
    timeline_print_events_by_book(4);

    // [TEST 4.3] Filtering by user ID (User 2)
    printf("\n[TEST 4.3] Filtering for events related to User ID 2.\n");
    printf("Expected: Only create and delete events for User 2 should be displayed.\n");
    timeline_print_events_by_user(2);

    // In toàn bộ timeline từ đầu đến cuối
    printf("\n--- FINAL TEST: PRINTING THE FULL TIMELINE FROM START TO END ---\n");
    timeline_print_all_events();

    printf("\n========================================================================\n");
    printf("END OF COMPREHENSIVE INTEGRATION TEST (STAGE 14)\n");
    printf("========================================================================\n");

    getchar();
    return 0;
}