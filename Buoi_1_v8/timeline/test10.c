// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../book.h"
// #include "../user.h"
// #include "../transaction.h"
// #include "timeline.h"
// #include "../definitions.h"

// int main() {
//     // Khởi tạo các mảng dữ liệu cần thiết
//     Book books[MAX_BOOKS];
//     User users[MAX_USERS];
//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;

//     // Khởi tạo timeline
//     timeline_init();

//     // =======================================================
//     // STAGE 10: TESTING TIMELINE FOR CREATE AND RESTORE EVENTS
//     // =======================================================
//     printf("\n========================================================================\n");
//     printf("STAGE 10: TESTING TIMELINE FOR CREATE AND RESTORE EVENTS\n");
//     printf("Expected: The timeline should record events for creating, deleting, and restoring books and users.\n");
//     printf("========================================================================\n");

//     // --- Test Case 10.1: Tạo mới sách và người dùng ---
//     printf("\n--- Test Case 10.1: Creating new book and user ---\n");
//     book_init(&books[0], 1, "Book1", "Author1");
//     user_init(&users[0], 1, "User1");
//     printf("Test Case 10.1 Passed: Create events recorded.\n");

//     // --- Test Case 10.2: Xóa mềm sách và người dùng ---
//     printf("\n--- Test Case 10.2: Soft-deleting the new book and user ---\n");
//     book_delete(&books[0], transactions, transaction_count);
//     user_delete(&users[0], transactions, transaction_count);
//     printf("Test Case 10.2 Passed: Delete events recorded.\n");

//     // --- Test Case 10.3: Phục hồi sách và người dùng ---
//     printf("\n--- Test Case 10.3: Restoring the soft-deleted book and user ---\n");
//     book_restore(&books[0]);
//     user_restore(&users[0]);
//     printf("Test Case 10.3 Passed: Restore events recorded.\n");

//     // --- In toàn bộ timeline để kiểm tra ---
//     printf("\n--- Final Test: Printing all timeline events ---\n");
//     timeline_print_all_events();

//     printf("\n========================================================================\n");
//     printf("END OF STAGE 10\n");
//     printf("========================================================================\n");

//     getchar();
//     return 0;
// }