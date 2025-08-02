#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "user.h"
#include "transaction.h"
#include "definitions.h"

int main() {
    // Khởi tạo dữ liệu ban đầu
    Book books[10];
    for (int i = 0; i < 10; i++) {
        char title[20];
        snprintf(title, sizeof(title), "Book %d", i + 1);
        book_init(&books[i], i + 1, title, "Author");
    }

    User users[3];
    user_init(&users[0], 1, "User 1");
    user_init(&users[1], 2, "User 2");
    user_init(&users[2], 3, "User 3"); // User 3 will have no transactions

    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count = 0;
    transaction_init(transactions, &transaction_count);

    printf("===== STAGE 3: TESTING TRANSACTION HISTORY FUNCTIONALITY =====\n\n");

    // === SETUP: CREATE TRANSACTIONS FOR DIFFERENT SCENARIOS ===
    
    // Scenario 1: User 1 has a mix of returned and active transactions
    printf("=== SETUP: USER 1 TRANSACTIONS ===\n");
    printf("User 1 borrows and returns Book 1:\n");
    transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
    transaction_return(transactions, &transaction_count, &books[0], &users[0]);
    
    printf("\nUser 1 borrows Book 2 (active):\n");
    transaction_borrow(transactions, &transaction_count, &books[1], &users[0]);
    
    printf("\nUser 1 borrows Book 3 (active):\n");
    transaction_borrow(transactions, &transaction_count, &books[2], &users[0]);

    // Scenario 2: User 2 has only active transactions
    printf("\n=== SETUP: USER 2 TRANSACTIONS ===\n");
    printf("User 2 borrows Book 4 and Book 5 (active):\n");
    transaction_borrow(transactions, &transaction_count, &books[3], &users[1]);
    transaction_borrow(transactions, &transaction_count, &books[4], &users[1]);
    
    printf("\n");

    // === TEST CASES FOR HISTORY PRINTING ===

    // Test 1: History for User 1 (mixed transactions)
    printf("=== TEST 1: PRINTING HISTORY FOR USER 1 (MIXED TRANSACTIONS) ===\n");
    printf("Expected output: 3 transactions, one returned and two active.\n");
    transaction_print_user_history(transactions, transaction_count, &users[0]);

    // Test 2: History for User 2 (active transactions only)
    printf("=== TEST 2: PRINTING HISTORY FOR USER 2 (ACTIVE TRANSACTIONS ONLY) ===\n");
    printf("Expected output: 2 active transactions.\n");
    transaction_print_user_history(transactions, transaction_count, &users[1]);

    // Test 3: History for User 3 (no transactions)
    printf("=== TEST 3: PRINTING HISTORY FOR USER 3 (NO TRANSACTIONS) ===\n");
    printf("Expected output: A header, but no transactions listed.\n");
    transaction_print_user_history(transactions, transaction_count, &users[2]);

    printf("\nPress any key to exit...");
    getchar();

    return 0;
}