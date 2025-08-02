#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 
#include "timeline.h"
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

    // Initialize timeline
    timeline_init();

    printf("\n========================================================\n");
    printf("STAGE 8: TESTING TIMELINE FUNCTIONALITY\n");
    printf("========================================================\n");

    // Test Case 8.1: User1 borrows Book1
    printf("\n--- Test 8.1: User1 borrows Book1 ---\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);

    // Test Case 8.2: User2 borrows and returns Book2
    printf("\n--- Test 8.2: User2 borrows and returns Book2 ---\n");
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
    transaction_return(transactions, &transaction_count, &books[1], &users[1]);

    // Test Case 8.3: Soft-delete Book3 and User3
    printf("\n--- Test 8.3: Soft-delete Book3 and User3 ---\n");
    book_delete(&books[2], transactions, transaction_count);
    user_delete(&users[2], transactions, transaction_count);

    // Print all timeline events
    printf("\n--- Final: Printing timeline events ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF STAGE 8\n");
    printf("========================================================\n");

    getchar();
    return 0;
}