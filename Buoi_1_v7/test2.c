// #include <stdio.h>
// #include <stdlib.h>
// #include "book.h"
// #include "user.h"
// #include "transaction.h"
// #include "definitions.h"

// int main() {
//     // Khởi tạo dữ liệu
//     Book books[10];
//     for (int i = 0; i < 10; i++) {
//         char title[20];
//         snprintf(title, sizeof(title), "Book %d", i + 1);
//         book_init(&books[i], i + 1, title, "Author");
//     }

//     User users[3];
//     user_init(&users[0], 1, "User 1");
//     user_init(&users[1], 2, "User 2");
//     user_init(&users[2], 3, "User 3");

//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;
//     transaction_init(transactions, &transaction_count);

//     printf("===== STAGE 2: TESTING SOFT DELETE FUNCTIONALITY =====\n\n");

//     // 1. Setup: Create some transactions for testing
//     printf("=== SETUP: CREATING INITIAL TRANSACTIONS ===\n");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[0]); // User 1 borrows Book 1
//     transaction_borrow(transactions, &transaction_count, &books[1], &users[1]); // User 2 borrows Book 2
//     printf("\n");
    
//     // Print initial status
//     printf("=== INITIAL STATUS ===\n");
//     book_print_info(&books[0]);
//     book_print_info(&books[1]);
//     user_print_info(&users[0]);
//     user_print_info(&users[1]);
//     user_print_info(&users[2]);
//     printf("\n");

//     // 2. Test delete failure (when there are active transactions)
//     printf("=== TESTING DELETE FAILURES ===\n");
//     printf("[TEST 1] Attempt to delete Book 1 (currently borrowed).\n");
//     if (book_delete(&books[0], transactions, transaction_count) == 0) {
//         printf("Result: SUCCESS (System correctly prevented deletion).\n\n");
//     } else {
//         printf("Result: FAILED (Deletion was not prevented).\n\n");
//     }

//     printf("[TEST 2] Attempt to delete User 1 (has borrowed books).\n");
//     if (user_delete(&users[0], transactions, transaction_count) == 0) {
//         printf("Result: SUCCESS (System correctly prevented deletion).\n\n");
//     } else {
//         printf("Result: FAILED (Deletion was not prevented).\n\n");
//     }

//     // 3. Test delete success
//     printf("=== TESTING DELETE SUCCESS ===\n");
//     printf("[TEST 3] Delete Book 3 (not borrowed).\n");
//     if (book_delete(&books[2], transactions, transaction_count) == 1) {
//         printf("Result: SUCCESS (Book was marked as deleted).\n");
//         book_print_info(&books[2]);
//         printf("\n");
//     } else {
//         printf("Result: FAILED (Deletion did not work as expected).\n\n");
//     }
    
//     printf("[TEST 4] Delete User 3 (no borrowed books).\n");
//     if (user_delete(&users[2], transactions, transaction_count) == 1) {
//         printf("Result: SUCCESS (User was marked as deleted).\n");
//         user_print_info(&users[2]);
//         printf("\n");
//     } else {
//         printf("Result: FAILED (Deletion did not work as expected).\n\n");
//     }
    
//     // 4. Test effects of soft delete on other functions
//     printf("=== TESTING SOFT DELETE EFFECTS ===\n");
//     printf("[TEST 5] User 1 tries to borrow Book 3 (now deleted).\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[2], &users[0]) == 0) {
//         printf("Result: SUCCESS (System correctly prevented transaction).\n\n");
//     } else {
//         printf("Result: FAILED (User was able to borrow a deleted book).\n\n");
//     }
    
//     printf("[TEST 6] User 3 (now deleted) tries to borrow Book 4.\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[3], &users[2]) == 0) {
//         printf("Result: SUCCESS (System correctly prevented transaction).\n\n");
//     } else {
//         printf("Result: FAILED (Deleted user was able to borrow a book).\n\n");
//     }

//     printf("\nPress any key to exit...");
//     getchar();

//     return 0;
// }