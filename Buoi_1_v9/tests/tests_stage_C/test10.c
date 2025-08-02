#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h" 
#include "timeline.h"
int main() {
    // Initialize data
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;

    // Initialize timeline
    timeline_init();

    printf("\n========================================================\n");
    printf("STAGE 10: TESTING CREATE/RESTORE EVENTS\n");
    printf("========================================================\n");

    // Test Case 10.1: Create Book1 and User1
    printf("\n--- Test 10.1: Create Book1 and User1 ---\n");
    book_init(&books[0], 1, "Book1", "Author1");
    user_init(&users[0], 1, "User1");

    // Test Case 10.2: Soft-delete Book1 and User1
    printf("\n--- Test 10.2: Soft-delete Book1 and User1 ---\n");
    book_delete(&books[0], transactions, transaction_count);
    user_delete(&users[0], transactions, transaction_count);

    // Test Case 10.3: Restore Book1 and User1
    printf("\n--- Test 10.3: Restore Book1 and User1 ---\n");
    book_restore(&books[0]);
    user_restore(&users[0]);

    // Print all timeline events
    printf("\n--- Final: Printing timeline events ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF STAGE 10\n");
    printf("========================================================\n");

    getchar();
    return 0;
}