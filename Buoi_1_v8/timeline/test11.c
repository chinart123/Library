// #include <stdio.h>
// #include <stdlib.h>
// #include "../book.h"
// #include "../user.h"
// #include "../transaction.h"
// #include "../timeline/timeline.h"
// #include "../definitions.h"

// int main() {
//     // Khởi tạo dữ liệu ban đầu
//     Book books[3];
//     User users[3];
//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;

//     // Khởi tạo timeline
//     timeline_init();

//     // =======================================================
//     // STAGE 11: TESTING FILTERING AND SEARCHING TIMELINE
//     // =======================================================
//     printf("\n========================================================================\n");
//     printf("STAGE 11: TESTING FILTERING AND SEARCHING TIMELINE\n");
//     printf("Expected: Filtered timeline events should be displayed correctly.\n");
//     printf("========================================================================\n");

//     // --- Tạo các sự kiện để kiểm tra ---
//     // User1 mượn Book1
//     book_init(&books[0], 1, "Book1", "Author1");
//     user_init(&users[0], 1, "User1");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
//     // User2 mượn Book2
//     book_init(&books[1], 2, "Book2", "Author2");
//     user_init(&users[1], 2, "User2");
//     transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
//     // User1 trả Book1
//     transaction_return(transactions, &transaction_count, &books[0], &users[0]);
//     // User3 mượn Book1
//     book_init(&books[2], 3, "Book3", "Author3");
//     user_init(&users[2], 3, "User3");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[2]);
//     // User2 trả Book2 TRƯỚC KHI BỊ XÓA
//     transaction_return(transactions, &transaction_count, &books[1], &users[1]); // DÒNG ĐƯỢC THÊM
//     // Chỉnh sửa tiêu đề của Book2
//     book_edit(&books[1], "Book2_New", NULL);
//     // Xóa mềm User2
//     user_delete(&users[1], transactions, transaction_count);

//     // --- Test Case 11.1: Lọc theo loại sự kiện ---
//     printf("\n--- Test Case 11.1: Filtering by event type (EVENT_BORROW) ---\n");
//     printf("Expected: Only borrow events should be displayed.\n");
//     timeline_print_events_by_type(EVENT_BORROW);
    
//     // --- Test Case 11.2: Lọc theo ID sách ---
//     printf("\n--- Test Case 11.2: Filtering by book ID (Book ID 1) ---\n");
//     printf("Expected: Events for Book ID 1 (borrow, return, borrow) should be displayed.\n");
//     timeline_print_events_by_book(1);

//     // --- Test Case 11.3: Lọc theo ID người dùng ---
//     printf("\n--- Test Case 11.3: Filtering by user ID (User ID 1) ---\n");
//     printf("Expected: Events for User ID 1 (borrow, return) should be displayed.\n");
//     timeline_print_events_by_user(1);
    
//     // --- Test Case 11.4: In toàn bộ timeline ---
//     printf("\n--- Test Case 11.4: Printing all timeline events ---\n");
//     printf("Expected: All events from the test should be displayed.\n");
//     timeline_print_all_events();

//     printf("\n========================================================================\n");
//     printf("END OF STAGE 11\n");
//     printf("========================================================================\n");

//     getchar();
//     return 0;
// }