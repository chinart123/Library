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
    EventType event_type;

    // Initialize timeline
    timeline_init();

    printf("\n========================================================\n");
    printf("STAGE 9: TESTING EDIT EVENTS IN TIMELINE\n");
    printf("========================================================\n");

    // Test Case 9.1: Edit Book1 title
    printf("\n--- Test 9.1: Edit Book1 title ---\n");
    book_edit(&books[0], "Book1_NewTitle", NULL, &event_type);

    // Test Case 9.2: Edit Book2 author
    printf("\n--- Test 9.2: Edit Book2 author ---\n");
    book_edit(&books[1], NULL, "Author2_New", &event_type);

    // Test Case 9.3: Edit User1 name
    printf("\n--- Test 9.3: Edit User1 name ---\n");
    user_edit(&users[0], "User1_Updated");

    // Test Case 9.4: Combined events
    printf("\n--- Test 9.4: Combined events ---\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[1]);
    book_delete(&books[2], transactions, transaction_count);

    // Print all timeline events
    printf("\n--- Final: Printing timeline events ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF STAGE 9\n");
    printf("========================================================\n");

    getchar();
    return 0;
}