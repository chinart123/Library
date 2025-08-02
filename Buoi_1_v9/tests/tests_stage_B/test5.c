#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 

int main() {
    // Initialize data
    Book books[2];
    book_init(&books[0], 1, "Book1", "Author1");
    book_init(&books[1], 2, "Book2", "Author2");

    User users[2];
    user_init(&users[0], 1, "User1");
    user_init(&users[1], 2, "User2");

    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    transaction_init(transactions, &transaction_count);

    printf("===== STAGE 5: TESTING EDIT FUNCTIONALITY =====\n\n");

    // 1. Setup: User1 borrows Book1
    printf("=== SETUP: INITIAL TRANSACTIONS ===\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    printf("\n");

    // Print initial info
    printf("=== INITIAL INFO ===\n");
    book_print_info(&books[0]);
    user_print_info(&users[0]);
    printf("\n");

    // 2. Test editing book
    printf("=== TEST 1: EDITING BOOK INFO ===\n");
    printf("Editing Book1's title and author.\n");
    EventType event_type;
    book_edit(&books[0], "Book1 (Revised)", "NewAuthor1", &event_type);
    printf("\n");

    // Print updated book info
    printf("=== INFO AFTER BOOK EDIT ===\n");
    book_print_info(&books[0]);
    printf("\n");

    // 3. Test editing user
    printf("=== TEST 2: EDITING USER INFO ===\n");
    printf("Editing User1's name.\n");
    user_edit(&users[0], "User1_Updated");
    printf("\n");

    // Print updated user info
    printf("=== INFO AFTER USER EDIT ===\n");
    user_print_info(&users[0]);
    printf("\n");

    // 4. Verify transactions after edits
    printf("=== TEST 3: CHECKING TRANSACTIONS AFTER EDITING ===\n");
    transaction_print_active(transactions, transaction_count);

    // 5. Test editing returned book
    printf("=== TEST 4: EDITING A RETURNED BOOK ===\n");
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
    transaction_return(transactions, &transaction_count, &books[1], &users[1]);
    book_edit(&books[1], "Book2_NewTitle", NULL, &event_type);
    printf("\n");
    
    // Print transaction history
    printf("=== INFO AFTER EDITING RETURNED BOOK ===\n");
    transaction_print_user_history(transactions, transaction_count, &users[1]);
    
    printf("\nPress any key to exit...");
    getchar();

    return 0;
}