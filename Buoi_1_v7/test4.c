// #include <stdio.h>
// #include <stdlib.h>
// #include "book.h"
// #include "user.h"
// #include "transaction.h"
// #include "definitions.h" 

// int main() {
//     // Khởi tạo dữ liệu ban đầu
//     Book books[10];
//     for (int i = 0; i < 10; i++) {
//         char title[20];
//         snprintf(title, sizeof(title), "Book %d", i + 1);
//         book_init(&books[i], i + 1, title, "Author");
//     }

//     User users[3];
//     user_init(&users[0], 1, "User 1");
//     user_init(&users[1], 2, "User 2");
//     user_init(&users[2], 3, "User 3"); // Người dùng này sẽ không có giao dịch

//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;
//     transaction_init(transactions, &transaction_count);

//     printf("===== STAGE 4: INTEGRATION TESTING (SOFT DELETE + HISTORY) =====\n\n");

//     // 1. SETUP: Tạo các giao dịch ban đầu
//     // User 1 mượn Book 1 và Book 2.
//     // User 2 mượn Book 3.
//     printf("=== SETUP: CREATING INITIAL TRANSACTIONS ===\n");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
//     transaction_borrow(transactions, &transaction_count, &books[1], &users[0]);
//     transaction_borrow(transactions, &transaction_count, &books[2], &users[1]);
//     printf("\n");
    
//     // 2. Kiểm tra lịch sử giao dịch ban đầu của User 1
//     printf("=== INFO: INITIAL TRANSACTION HISTORY FOR USER 1 ===\n");
//     transaction_print_user_history(transactions, transaction_count, &users[0]);
    
//     // 3. Xóa mềm các đối tượng đã có lịch sử giao dịch
//     printf("=== TESTING SOFT DELETE ON OBJECTS WITH TRANSACTION HISTORY ===\n");

//     // Scenario 1: Xóa một cuốn sách đã được trả
//     printf("[TEST 1] User 1 returns Book 1, then we attempt to delete it.\n");
//     transaction_return(transactions, &transaction_count, &books[0], &users[0]);
//     book_delete(&books[0], transactions, transaction_count);
//     printf("\n");

//     // Scenario 2: Xóa một người dùng đã có lịch sử nhưng không có giao dịch đang hoạt động
//     printf("[TEST 2] User 2 returns Book 3, then we attempt to delete them.\n");
//     transaction_return(transactions, &transaction_count, &books[2], &users[1]);
//     user_delete(&users[1], transactions, transaction_count);
//     printf("\n");
    
//     // 4. Kiểm tra tích hợp xóa mềm và in lịch sử
//     printf("=== TESTING INTEGRATION OF SOFT DELETE AND HISTORY PRINTING ===\n");
    
//     // Test 3: In lịch sử của User 1 (có sách đã bị xóa)
//     printf("[TEST 3] Printing transaction history for User 1.\n");
//     printf("Expected: One returned transaction with [DELETED] note, one active transaction.\n");
//     transaction_print_user_history(transactions, transaction_count, &users[0]);

//     // Test 4: In lịch sử của User 2 (đã bị xóa)
//     printf("[TEST 4] Printing transaction history for User 2 (who is now deleted).\n");
//     printf("Expected: The history still appears, showing one returned transaction.\n");
//     transaction_print_user_history(transactions, transaction_count, &users[1]);
    
//     // 5. Kiểm tra ảnh hưởng của xóa mềm lên các hàm khác
//     printf("=== TESTING SOFT DELETE EFFECTS ON OTHER FUNCTIONS ===\n");
    
//     // Test 5: In danh sách giao dịch đang hoạt động
//     printf("[TEST 5] Printing active transactions list.\n");
//     printf("Expected: Only the active transaction of Book 2 by User 1 should be listed.\n");
//     transaction_print_active(transactions, transaction_count);
    
//     // Test 6: Thử mượn một cuốn sách đã bị xóa
//     printf("[TEST 6] User 1 attempts to borrow Book 1 again (now deleted).\n");
//     printf("Expected: Transaction should fail.\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[0], &users[0]) == 0) {
//         printf("Result: SUCCESS (System prevented borrowing a deleted book).\n\n");
//     } else {
//         printf("Result: FAILED (User was able to borrow a deleted book).\n\n");
//     }

//     // Test 7: Thử mượn sách bởi một người dùng đã bị xóa
//     printf("[TEST 7] User 2 (now deleted) attempts to borrow a new book.\n");
//     printf("Expected: Transaction should fail.\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[9], &users[1]) == 0) {
//         printf("Result: SUCCESS (System prevented a deleted user from borrowing).\n\n");
//     } else {
//         printf("Result: FAILED (Deleted user was able to borrow a book).\n\n");
//     }
    
//     printf("===== END OF INTEGRATION TEST =====\n");
//     printf("\nPress any key to exit...");
//     getchar();

//     return 0;
// }