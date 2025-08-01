// #include <stdio.h>
// #include <stdlib.h>
// #include "book.h"
// #include "user.h"
// #include "transaction.h"
// #include "timeline/timeline.h"
// #include "definitions.h"

// int main() {
//     // Initialize core data arrays
//     Book books[MAX_BOOKS];
//     User users[MAX_USERS];
//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;
//     int book_count = 0;
//     int user_count = 0;
    
//     // Initialize timeline
//     timeline_init();

//     printf("\n========================================================================\n");
//     printf("STAGE 12: COMPREHENSIVE INTEGRATION TEST\n");
//     printf("Expected: All core functionalities (init, borrow, return, delete, edit, timeline) should work together seamlessly.\n");
//     printf("========================================================================\n");

//     // ====================================================================
//     // AREA 1: BASIC FUNCTIONALITIES & SOFT DELETE (from test4.c)
//     // ====================================================================
//     printf("\n--- AREA 1: TESTING INIT, BORROW, RETURN, AND SOFT DELETE ---\n");

//     // SETUP: Create a rich transaction history for testing
//     // [SETUP from test4.c]
//     book_init(&books[book_count++], 1, "Book A", "Author A"); // Book to be returned then deleted
//     book_init(&books[book_count++], 2, "Book B", "Author B"); // Book to remain active
//     user_init(&users[user_count++], 1, "User Alpha"); // User to return book then be deleted
//     user_init(&users[user_count++], 2, "User Beta"); // User with an active transaction
    
//     // Create initial transactions
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[0]); // User Alpha borrows Book A
//     transaction_borrow(transactions, &transaction_count, &books[1], &users[1]); // User Beta borrows Book B

//     // [TEST 1.1] Printing active transactions list
//     // [from test4.c]
//     printf("\n[TEST 1.1] Printing active transactions list.\n");
//     printf("Expected: Two active transactions should be listed.\n");
//     transaction_print_active(transactions, transaction_count);

//     // [TEST 1.2] Soft-deleting Book A after it's returned
//     // [from test4.c]
//     printf("\n[TEST 1.2] User Alpha returns Book A, then we attempt to soft-delete it.\n");
//     printf("Expected: Book A should be successfully deleted.\n");
//     transaction_return(transactions, &transaction_count, &books[0], &users[0]);
//     book_delete(&books[0], transactions, transaction_count);

//     // [TEST 1.3] Soft-deleting User Alpha after they returned the book
//     // [from test4.c]
//     printf("\n[TEST 1.3] Now, we attempt to soft-delete User Alpha.\n");
//     printf("Expected: User Alpha should be successfully deleted.\n");
//     user_delete(&users[0], transactions, transaction_count);
    
//     // [TEST 1.4] Attempting to borrow a deleted book
//     // [from test4.c]
//     printf("\n[TEST 1.4] User Beta attempts to borrow Book A (which is deleted).\n");
//     printf("Expected: The transaction should fail.\n");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[1]);

//     // ====================================================================
//     // AREA 2: EDIT FUNCTIONALITIES (from test7.c)
//     // ====================================================================
//     printf("\n--- AREA 2: TESTING EDIT FUNCTIONALITY FOR BOOKS AND USERS ---\n");

//     // [TEST 2.1] Editing Book B which has an active transaction
//     // [from test7.c]
//     printf("\n[TEST 2.1] Editing Book B's title (currently in an active transaction).\n");
//     printf("Expected: Title is updated, and an edit event is recorded.\n");
//     book_edit(&books[1], "Book B (New Title)", NULL);
//     book_print_info(&books[1]);

//     // [TEST 2.2] Editing User Beta who has an active transaction
//     // [from test7.c]
//     printf("\n[TEST 2.2] Editing User Beta's name (currently has an active transaction).\n");
//     printf("Expected: Name is updated, and an edit event is recorded.\n");
//     user_edit(&users[1], "User Beta (New Name)");
//     user_print_info(&users[1]);

//     // [TEST 2.3] Editing a soft-deleted user
//     // [from test7.c]
//     printf("\n[TEST 2.3] Attempting to edit a soft-deleted user (User Alpha).\n");
//     printf("Expected: The name should be updated, but the status remains 'Deleted'.\n");
//     user_edit(&users[0], "User Alpha (Deleted & Edited)");
//     user_print_info(&users[0]);

//     // ====================================================================
//     // AREA 3: TIMELINE AND FILTERING (from test11.c)
//     // ====================================================================
//     printf("\n--- AREA 3: TESTING TIMELINE AND FILTERING FUNCTIONS ---\n");

//     // [TEST 3.1] Filtering by event type (EVENT_BORROW)
//     // [from test11.c]
//     printf("\n[TEST 3.1] Filtering for 'borrow' events.\n");
//     printf("Expected: Only borrow events should be displayed.\n");
//     timeline_print_events_by_type(EVENT_BORROW);
    
//     // [TEST 3.2] Filtering by book ID (Book 1)
//     // [from test11.c]
//     printf("\n[TEST 3.2] Filtering for events related to Book ID 1.\n");
//     printf("Expected: All events for Book 1 (create, borrow, return, delete, restore) should be displayed.\n");
//     timeline_print_events_by_book(1);

//     // [TEST 3.3] Filtering by user ID (User 2)
//     // [from test11.c]
//     printf("\n[TEST 3.3] Filtering for events related to User ID 2.\n");
//     printf("Expected: All events for User 2 (create, borrow, edit) should be displayed.\n");
//     timeline_print_events_by_user(2);

//     // ====================================================================
//     // FINAL TEST: PRINT THE ENTIRE TIMELINE
//     // ====================================================================
//     printf("\n--- FINAL TEST: PRINTING THE FULL TIMELINE FROM START TO END ---\n");
//     timeline_print_all_events();

//     printf("\n========================================================================\n");
//     printf("END OF COMPREHENSIVE INTEGRATION TEST\n");
//     printf("========================================================================\n");

//     getchar();
//     return 0;
// }