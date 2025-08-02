#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 

int main() {
    // Initialize data
    Book books[3];
    book_init(&books[0], 1, "Book1", "Author1");
    book_init(&books[1], 2, "Book2", "Author2");
    book_init(&books[2], 3, "Book3", "Author3");

    User users[3];
    user_init(&users[0], 1, "User1");
    user_init(&users[1], 2, "User2");
    user_init(&users[2], 3, "User3");

    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    EventType event_type;

    printf("===== STAGE 6: EXTENSIVE EDIT FUNCTIONALITY TESTING =====\n\n");

    // Setup initial transactions
    printf("=== SETUP: CREATING INITIAL TRANSACTIONS ===\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
    transaction_return(transactions, &transaction_count, &books[1], &users[1]);
    printf("\n");

    // Test 1: Editing objects with active transactions
    printf("=== TEST 1: EDITING OBJECTS IN ACTIVE TRANSACTIONS ===\n");
    book_edit(&books[0], "Book1_Revised", NULL, &event_type);
    user_edit(&users[0], "User1_Updated");
    transaction_print_active(transactions, transaction_count);
    
    // Test 2: Editing objects with transaction history
    printf("=== TEST 2: EDITING OBJECTS WITH TRANSACTION HISTORY ===\n");
    book_edit(&books[1], "Book2_SpecialEdition", "Author2_Updated", &event_type);
    user_edit(&users[1], "User2_Updated");
    transaction_print_user_history(transactions, transaction_count, &users[1]);

    // Test 3: Editing soft-deleted objects
    printf("=== TEST 3: EDITING SOFT-DELETED OBJECTS ===\n");
    book_delete(&books[2], transactions, transaction_count);
    book_edit(&books[2], "Book3_Deleted", "Author3_Updated", &event_type);
    book_print_info(&books[2]);
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