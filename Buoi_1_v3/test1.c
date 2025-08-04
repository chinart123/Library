#include <stdio.h>
#include "library.h"
#include "user.h"

// Hàm mượn sách với kiểm tra điều kiện tự động
void borrow_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
    Book *book = NULL;
    User *user = NULL;
    
    // Tìm sách theo ID
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == book_id) {
            book = &books[i];
            break;
        }
    }
    
    // Tìm người dùng theo ID
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            user = &users[i];
            break;
        }
    }
    
    // Kiểm tra điều kiện
    if (!book || !user) {
        printf("Error: Invalid book ID or user ID.\n");
        return;
    }
    
    if (!book->Book_Status) {
        printf("Borrow failed: Book '%s' is not available.\n", book->title);
        return;
    }
    
    if (!user->User_status) {
        printf("Borrow failed: User '%s' cannot borrow more books (already has %d books).\n", 
               user->name, user->Book_borrowed);
        return;
    }
    
    // Thực hiện mượn sách
    book->Book_Status = false;
    book->borrower_id = user->id;
    user->Book_borrowed++;
    user->User_status = (user->Book_borrowed <= 2);
    
    printf("Book '%s' borrowed by user '%s'.\n", book->title, user->name);
}

// Hàm trả sách với kiểm tra điều kiện tự động
void return_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
    Book *book = NULL;
    User *user = NULL;
    
    // Tìm sách theo ID
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == book_id) {
            book = &books[i];
            break;
        }
    }
    
    // Tìm người dùng theo ID
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            user = &users[i];
            break;
        }
    }
    
    // Kiểm tra điều kiện
    if (!book || !user) {
        printf("Error: Invalid book ID or user ID.\n");
        return;
    }
    
    if (book->Book_Status) {
        printf("Return failed: Book '%s' is not borrowed.\n", book->title);
        return;
    }
    
    if (book->borrower_id != user->id) {
        printf("Return failed: Book '%s' was borrowed by another user (ID %d).\n", 
               book->title, book->borrower_id);
        return;
    }
    
    // Thực hiện trả sách
    book->Book_Status = true;
    book->borrower_id = -1;
    user->Book_borrowed--;
    user->User_status = (user->Book_borrowed <= 2);
    
    printf("Book '%s' returned by user '%s'.\n", book->title, user->name);
}

int main() {
    Book books[20];
    User users[10];
    int book_count = 0;
    int user_count = 0;
    
    // Tạo 10 quyển sách
    for (int i = 1; i <= 10; i++) {
        char title[20], author[20];
        sprintf(title, "Sách %d", i);
        sprintf(author, "Tác giả %d", i);
        add_book(books, &book_count, i, title, author);
    }
    
    // Tạo 5 người dùng
    add_user(users, &user_count, 1, "Người dùng 1", 0);
    add_user(users, &user_count, 2, "Người dùng 2", 1);
    add_user(users, &user_count, 3, "Người dùng 3", 2);
    add_user(users, &user_count, 4, "Người dùng 4", 3);
    add_user(users, &user_count, 5, "Người dùng 5", 0);
    
    // In trạng thái ban đầu
    printf("===== TRẠNG THÁI BAN ĐẦU =====\n");
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    // Kiểm thử mượn sách
    printf("\n===== KIỂM THỬ MƯỢN SÁCH =====\n");
    
    // 1. Mượn thành công
    printf("\n[TEST 1] Người dùng 1 mượn Sách 1 (Thành công):\n");
    borrow_book(books, book_count, users, user_count, 1, 1);
    
    // 2. Mượn sách đã được mượn
    printf("\n[TEST 2] Người dùng 1 mượn Sách 1 lần nữa (Thất bại):\n");
    borrow_book(books, book_count, users, user_count, 1, 1);
    
    // 3. Mượn thành công khác
    printf("\n[TEST 3] Người dùng 2 mượn Sách 2 (Thành công):\n");
    borrow_book(books, book_count, users, user_count, 2, 2);
    
    // 4. Người dùng đạt giới hạn
    printf("\n[TEST 4] Người dùng 3 mượn Sách 3 (Thất bại - đạt giới hạn):\n");
    borrow_book(books, book_count, users, user_count, 3, 3);
    
    // 5. Người dùng không thể mượn thêm
    printf("\n[TEST 5] Người dùng 4 mượn Sách 4 (Thất bại - không thể mượn):\n");
    borrow_book(books, book_count, users, user_count, 4, 4);
    
    // 6. Sách không tồn tại
    printf("\n[TEST 6] Người dùng 5 mượn Sách 100 (Thất bại - sách không tồn tại):\n");
    borrow_book(books, book_count, users, user_count, 100, 5);
    
    // 7. Người dùng không tồn tại
    printf("\n[TEST 7] Người dùng 100 mượn Sách 5 (Thất bại - người dùng không tồn tại):\n");
    borrow_book(books, book_count, users, user_count, 5, 100);
    
    // 8. Mượn sách đã được mượn bởi người khác
    printf("\n[TEST 8] Người dùng 3 mượn Sách 1 (Thất bại - sách đã được mượn):\n");
    borrow_book(books, book_count, users, user_count, 1, 3);
    
    // Kiểm thử trả sách
    printf("\n===== KIỂM THỬ TRẢ SÁCH =====\n");
    
    // 1. Trả sách thành công
    printf("\n[TEST 9] Người dùng 1 trả Sách 1 (Thành công):\n");
    return_book(books, book_count, users, user_count, 1, 1);
    
    // 2. Trả sách đã được trả
    printf("\n[TEST 10] Người dùng 1 trả Sách 1 lần nữa (Thất bại):\n");
    return_book(books, book_count, users, user_count, 1, 1);
    
    // 3. Trả sách không được mượn bởi người này
    printf("\n[TEST 11] Người dùng 1 trả Sách 2 (Thất bại - người khác mượn):\n");
    return_book(books, book_count, users, user_count, 2, 1);
    
    // 4. Trả sách không được mượn
    printf("\n[TEST 12] Người dùng 5 trả Sách 3 (Thất bại - sách không được mượn):\n");
    return_book(books, book_count, users, user_count, 3, 5);
    
    // 5. Sách không tồn tại
    printf("\n[TEST 13] Người dùng 4 trả Sách 100 (Thất bại - sách không tồn tại):\n");
    return_book(books, book_count, users, user_count, 100, 4);
    
    // 6. Người dùng không tồn tại
    printf("\n[TEST 14] Người dùng 100 trả Sách 5 (Thất bại - người dùng không tồn tại):\n");
    return_book(books, book_count, users, user_count, 5, 100);
    
    // 7. Trả sách thành công khác
    printf("\n[TEST 15] Người dùng 2 trả Sách 2 (Thành công):\n");
    return_book(books, book_count, users, user_count, 2, 2);
    
    // Kiểm thử đặc biệt
    printf("\n===== KIỂM THỬ ĐẶC BIỆT =====\n");
    
    // 1. Mượn sách sau khi trả
    printf("\n[TEST 16] Người dùng 3 mượn Sách 1 sau khi trả (Thành công):\n");
    borrow_book(books, book_count, users, user_count, 1, 3);
    
    // 2. Kiểm tra giới hạn sau khi mượn
    printf("\n[TEST 17] Người dùng 3 mượn Sách 5 (Thất bại - đạt giới hạn):\n");
    borrow_book(books, book_count, users, user_count, 5, 3);
    
    // 3. Trả sách và mượn sách mới
    printf("\n[TEST 18] Người dùng 3 trả Sách 1 (Thành công):\n");
    return_book(books, book_count, users, user_count, 1, 3);
    
    printf("\n[TEST 19] Người dùng 3 mượn Sách 5 sau khi trả (Thành công):\n");
    borrow_book(books, book_count, users, user_count, 5, 3);
    
    // 4. Cập nhật trạng thái tự động
    printf("\n[TEST 20] Người dùng 4 trả một sách ảo (giả định đã mượn):\n");
    // Trước tiên giả định người dùng 4 đã mượn sách 6
    books[5].Book_Status = false;
    books[5].borrower_id = 4;
    users[3].Book_borrowed = 3; // Giả định đang mượn 3 sách
    
    printf("Trước khi trả:\n");
    printf("Sách 6 status: %s\n", books[5].Book_Status ? "Available" : "Borrowed");
    printf("Người dùng 4 số sách: %d, Trạng thái: %s\n", 
           users[3].Book_borrowed, 
           users[3].User_status ? "Available" : "Can't borrow");
    
    return_book(books, book_count, users, user_count, 6, 4);
    
    printf("\nSau khi trả:\n");
    printf("Sách 6 status: %s\n", books[5].Book_Status ? "Available" : "Borrowed");
    printf("Người dùng 4 số sách: %d, Trạng thái: %s\n", 
           users[3].Book_borrowed, 
           users[3].User_status ? "Available" : "Can't borrow");
    
    // In trạng thái cuối cùng
    printf("\n===== TRẠNG THÁI CUỐI CÙNG =====\n");
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    return 0;
}


// #include <stdio.h>
// #include "library.h"
// #include "user.h"

// // Hàm mượn sách với kiểm tra điều kiện tự động
// void borrow_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
//     Book *book = NULL;
//     User *user = NULL;
    
//     // Tìm sách theo ID
//     for (int i = 0; i < book_count; i++) {
//         if (books[i].id == book_id) {
//             book = &books[i];
//             break;
//         }
//     }
    
//     // Tìm người dùng theo ID
//     for (int i = 0; i < user_count; i++) {
//         if (users[i].id == user_id) {
//             user = &users[i];
//             break;
//         }
//     }
    
//     // Kiểm tra điều kiện
//     if (!book || !user) {
//         printf("Error: Invalid book ID or user ID.\n");
//         return;
//     }
    
//     if (!book->Book_Status) {
//         printf("Borrow failed: Book '%s' is not available.\n", book->title);
//         return;
//     }
    
//     if (!user->User_status) {
//         printf("Borrow failed: User '%s' cannot borrow more books (already has %d books).\n", 
//                user->name, user->Book_borrowed);
//         return;
//     }
    
//     // Thực hiện mượn sách
//     book->Book_Status = false;
//     book->borrower_id = user->id;
//     user->Book_borrowed++;
//     user->User_status = (user->Book_borrowed <= 2);
    
//     printf("Book '%s' borrowed by user '%s'.\n", book->title, user->name);
// }

// // Hàm trả sách với kiểm tra điều kiện tự động
// void return_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
//     Book *book = NULL;
//     User *user = NULL;
    
//     // Tìm sách theo ID
//     for (int i = 0; i < book_count; i++) {
//         if (books[i].id == book_id) {
//             book = &books[i];
//             break;
//         }
//     }
    
//     // Tìm người dùng theo ID
//     for (int i = 0; i < user_count; i++) {
//         if (users[i].id == user_id) {
//             user = &users[i];
//             break;
//         }
//     }
    
//     // Kiểm tra điều kiện
//     if (!book || !user) {
//         printf("Error: Invalid book ID or user ID.\n");
//         return;
//     }
    
//     if (book->Book_Status) {
//         printf("Return failed: Book '%s' is not borrowed.\n", book->title);
//         return;
//     }
    
//     if (book->borrower_id != user->id) {
//         printf("Return failed: Book '%s' was borrowed by another user (ID %d).\n", 
//                book->title, book->borrower_id);
//         return;
//     }
    
//     // Thực hiện trả sách
//     book->Book_Status = true;
//     book->borrower_id = -1;
//     user->Book_borrowed--;
//     user->User_status = (user->Book_borrowed <= 2);
    
//     printf("Book '%s' returned by user '%s'.\n", book->title, user->name);
// }

// int main() {
//     Book books[10];
//     User users[10];
//     int book_count = 0;
//     int user_count = 0;
    
//     // Thêm sách với hàm add_book
//     add_book(books, &book_count, 1, "The C Programming Language", "Brian Kernighan & Dennis Ritchie");
//     add_book(books, &book_count, 2, "Clean Code", "Robert C. Martin");
//     add_book(books, &book_count, 3, "Design Patterns", "Erich Gamma");
    
//     // Thêm người dùng với hàm add_user (tự động kiểm tra trạng thái)
//     add_user(users, &user_count, 101, "Alice Johnson", 0);   // Có thể mượn
//     add_user(users, &user_count, 102, "Bob Smith", 2);       // Đạt giới hạn
//     add_user(users, &user_count, 103, "Charlie Brown", 3);   // Không thể mượn thêm
//     add_user(users, &user_count, 104, "Invalid User", -1);   // Số sách âm (tự động sửa)
    
//     // In trạng thái ban đầu
//     print_all_books(books, book_count);
//     print_all_users(users, user_count);
    
//     // Test mượn sách
//     printf("\n===== TEST BORROWING =====\n");
//     borrow_book(books, book_count, users, user_count, 1, 101);  // Thành công
//     borrow_book(books, book_count, users, user_count, 2, 102);  // Thất bại (user đạt giới hạn)
//     borrow_book(books, book_count, users, user_count, 3, 103);  // Thất bại (user không thể mượn)
//     borrow_book(books, book_count, users, user_count, 1, 105);  // Thất bại (user không tồn tại)
    
//     // In trạng thái sau khi mượn
//     print_all_books(books, book_count);
//     print_all_users(users, user_count);
    
//     // Test trả sách
//     printf("\n===== TEST RETURNING =====\n");
//     return_book(books, book_count, users, user_count, 1, 101);  // Thành công
//     return_book(books, book_count, users, user_count, 2, 102);  // Thất bại (sách không được mượn)
//     return_book(books, book_count, users, user_count, 1, 102);  // Thất bại (user không mượn sách này)
    
//     // In trạng thái sau khi trả
//     print_all_books(books, book_count);
//     print_all_users(users, user_count);
    
//     // Test tìm kiếm
//     printf("\n===== TEST SEARCHING =====\n");
//     print_books_by_title(books, book_count, "C");
//     print_users_by_name(users, user_count, "Smith");
    
//     return 0;
// }