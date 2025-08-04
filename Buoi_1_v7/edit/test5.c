// #include <stdio.h>
// #include <stdlib.h>
// #include "../book.h"
// #include "../user.h"
// #include "../transaction.h"
// #include "../definitions.h"

// int main() {
//     // Khởi tạo dữ liệu
//     Book books[2];
//     book_init(&books[0], 1, "The Great Gatsby", "F. Scott Fitzgerald");
//     book_init(&books[1], 2, "1984", "George Orwell");

//     User users[2];
//     user_init(&users[0], 1, "Alice");
//     user_init(&users[1], 2, "Bob");

//     Transaction transactions[MAX_TRANSACTIONS];
//     int transaction_count = 0;
//     transaction_init(transactions, &transaction_count);

//     printf("===== STAGE 5: TESTING EDIT FUNCTIONALITY =====\n\n");

//     // 1. Setup: User 1 borrows Book 1
//     printf("=== SETUP: INITIAL TRANSACTIONS ===\n");
//     transaction_borrow(transactions, &transaction_count, &books[0], &users[0]);
//     printf("\n");

//     // In thông tin ban đầu
//     printf("=== INITIAL INFO ===\n");
//     book_print_info(&books[0]);
//     user_print_info(&users[0]);
//     printf("\n");

//     // 2. Test chỉnh sửa sách
//     printf("=== TEST 1: EDITING BOOK INFO ===\n");
//     printf("Editing Book 1's title and author.\n");
//     book_edit(&books[0], "The Great Gatsby (Revised)", "New Author");
//     printf("\n");

//     // In lại thông tin sách để xác nhận thay đổi
//     printf("=== INFO AFTER BOOK EDIT ===\n");
//     book_print_info(&books[0]);
//     printf("\n");

//     // 3. Test chỉnh sửa người dùng
//     printf("=== TEST 2: EDITING USER INFO ===\n");
//     printf("Editing User 1's name.\n");
//     user_edit(&users[0], "Alicia");
//     printf("\n");

//     // In lại thông tin người dùng để xác nhận thay đổi
//     printf("=== INFO AFTER USER EDIT ===\n");
//     user_print_info(&users[0]);
//     printf("\n");

//     // 4. Test tích hợp: In giao dịch sau khi chỉnh sửa
//     printf("=== TEST 3: CHECKING TRANSACTIONS AFTER EDITING ===\n");
//     printf("Expected: The transaction below should show the new book title and user name.\n");
//     transaction_print_active(transactions, transaction_count);

//     // 5. Test chỉnh sửa thông tin của một đối tượng đã được trả
//     printf("=== TEST 4: EDITING A BOOK THAT IS NOW RETURNED ===\n");
//     transaction_borrow(transactions, &transaction_count, &books[1], &users[1]);
//     transaction_return(transactions, &transaction_count, &books[1], &users[1]);
//     book_edit(&books[1], "New Title for 1984", NULL);
//     printf("\n");
    
//     // In lịch sử giao dịch để xác nhận thay đổi
//     printf("=== INFO AFTER EDITING A RETURNED BOOK ===\n");
//     transaction_print_user_history(transactions, transaction_count, &users[1]);
    
//     printf("\nPress any key to exit...");
//     getchar();

//     return 0;
// }