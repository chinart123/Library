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
//     // STAGE 9: TESTING TIMELINE FOR EDIT EVENTS
//     // =======================================================
//     printf("\n========================================================================\n");
//     printf("STAGE 9: TESTING TIMELINE FOR EDIT EVENTS\n");
//     printf("Expected: The timeline should record events for editing books and users.\n");
//     printf("========================================================================\n");

//     // --- Test Case 9.1: Chỉnh sửa tiêu đề sách ---
//     printf("\n--- Test Case 9.1: Editing book title ---\n");
//     printf("Old title: %s\n", books[0].title);
//     book_edit(&books[0], "Book1_New_Title", NULL);
//     printf("New title: %s\n", books[0].title);

//     // --- Test Case 9.2: Chỉnh sửa tác giả sách ---
//     printf("\n--- Test Case 9.2: Editing book author ---\n");
//     printf("Old author: %s\n", books[1].author);
//     book_edit(&books[1], NULL, "Author2_New");
//     printf("New author: %s\n", books[1].author);

//     // --- Test Case 9.3: Chỉnh sửa tên người dùng ---
//     printf("\n--- Test Case 9.3: Editing user name ---\n");
//     printf("Old name: %s\n", users[0].name);
//     user_edit(&users[0], "User1_New_Name");
//     printf("New name: %s\n", users[0].name);

//     // --- Test Case 9.4: Kết hợp nhiều loại sự kiện ---
//     printf("\n--- Test Case 9.4: Combined events ---\n");
//     printf("Borrowing a book and deleting another.\n");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[1]);
//     book_delete(&books[2], transactions, transaction_count);

//     // --- In toàn bộ timeline để kiểm tra ---
//     printf("\n--- Final Test: Printing all timeline events ---\n");
//     timeline_print_all_events();

//     printf("\n========================================================================\n");
//     printf("END OF STAGE 9\n");
//     printf("========================================================================\n");

//     getchar();
//     return 0;
// }