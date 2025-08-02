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
    User users[3];
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    EventType event_type;

    // Initialize timeline
    timeline_init();

    printf("\n========================================================\n");
    printf("STAGE 11: TESTING TIMELINE FILTERING\n");
    printf("========================================================\n");

    // Create events
    book_init(&books[0], 1, "Book1", "Author1");
    user_init(&users[0], 1, "User1");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);

    book_init(&books[1], 2, "Book2", "Author2");
    user_init(&users[1], 2, "User2");
    transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);

    transaction_return(transactions, &transaction_count, &books[0], &users[0]);

    book_init(&books[2], 3, "Book3", "Author3");
    user_init(&users[2], 3, "User3");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[2]);

    transaction_return(transactions, &transaction_count, &books[1], &users[1]);
    
    book_edit(&books[1], "Book2_NewTitle", NULL, &event_type);
    
    user_delete(&users[1], transactions, transaction_count);

    // Print all timeline events
    printf("\n--- All Timeline Events ---\n");
    timeline_print_all_events();

    printf("\n========================================================\n");
    printf("END OF STAGE 11\n");
    printf("========================================================\n");

    getchar();
    return 0;
}