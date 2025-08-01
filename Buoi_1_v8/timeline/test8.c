// #include <stdio.h>
// #include <stdlib.h>
// #include "../book.h"
// #include "../user.h"
// #include "../transaction.h"
// #include "timeline.h"
// #include "../definitions.h"

// int main() {
//     // Khởi tạo dữ liệu
//     Book books[3];
//     book_init(&books[0], 1, "Book1", "Author1");
//     book_init(&books[1], 2, "Book2", "Author2");
//     book_init(&books[2], 3, "Book3", "Author3");

//     User users[3];
//     user_init(&users[0], 1, "User1");
//     user_init(&users[1], 2, "User2");
//     user_init(&users[2], 3, "User3");

//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;

//     // Khởi tạo timeline
//     timeline_init();

//     // =======================================================
//     // STAGE 8: TESTING TIMELINE FUNCTIONALITY
//     // =======================================================
//     printf("\n========================================================================\n");
//     printf("STAGE 8: TESTING TIMELINE FUNCTIONALITY\n");
//     printf("Expected: A list of 4 events should be displayed with timestamps.\n");
//     printf("========================================================================\n");

//     // Giao dịch 1: User1 mượn sách Book1
//     printf("\n--- Test Case 8.1: User1 borrows a book ---\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[0], &users[0])) {
//         printf("Test Case 8.1 Passed: Borrow event recorded.\n");
//     } else {
//         printf("Test Case 8.1 Failed.\n");
//     }

//     // Giao dịch 2: User2 mượn và trả sách Book2
//     printf("\n--- Test Case 8.2: User2 borrows and returns a book ---\n");
//     if (transaction_borrow(transactions, &transaction_count, &books[1], &users[1])) {
//         if (transaction_return(transactions, &transaction_count, &books[1], &users[1])) {
//             printf("Test Case 8.2 Passed: Borrow and return events recorded.\n");
//         } else {
//             printf("Test Case 8.2 Failed: Return failed.\n");
//         }
//     } else {
//         printf("Test Case 8.2 Failed: Borrow failed.\n");
//     }

//     // Giao dịch 3: Xóa mềm một cuốn sách và một người dùng
//     printf("\n--- Test Case 8.3: Soft-deleting a book and a user ---\n");
//     book_delete(&books[2], transactions, transaction_count);
//     user_delete(&users[2], transactions, transaction_count);
//     printf("Test Case 8.3 Passed: Delete events recorded.\n");

//     // In toàn bộ timeline
//     printf("\n--- Test Case 8.4: Printing all timeline events ---\n");
//     timeline_print_all_events();

//     printf("\n========================================================================\n");
//     printf("END OF STAGE 8\n");
//     printf("========================================================================\n");

//     getchar();
//     return 0;
// }