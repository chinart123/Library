#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // cần cho memset()

#include "../include/flags.h"
#include "../include/bitflags_viewer.h"
#include "../include/definitions.h"
#include "../include/transaction.h"
#include "../include/user.h"
#include "../include/book.h"

int main() {
    printf("=== TEST9: BITFLAGS DEMO ===\n\n");

    // --- Khởi tạo Book ---
    Book book = {0};
    book.id = 1001;
    set_flag(&book.flags, BOOK_FLAG_ACTIVE);
    set_flag(&book.flags, BOOK_FLAG_BORROWED);

    // --- Khởi tạo User ---
    User user = {0};
    user.id = 2001;
    set_flag(&user.flags, USER_FLAG_ACTIVE);
    set_flag(&user.flags, USER_FLAG_DELETED);

    // --- Khởi tạo Transaction ---
    Transaction t = {0};
    t.id = 3001;
    set_flag(&t.flags, TRANSACTION_FLAG_ACTIVE);

    // --- Hiển thị thông tin ---
    printf("Book flags:\n");
    print_flags_as_binary(book.flags);
    decode_book_flags(book.flags);

    printf("\nUser flags:\n");
    printf("User flags raw = 0x%02X\n", user.flags);  // debug thêm nếu cần
    print_flags_as_binary(user.flags);
    decode_user_flags(user.flags);

    printf("\nTransaction flags:\n");
    print_flags_as_binary(t.flags);
    decode_transaction_flags(t.flags);

    // --- Kiểm tra trạng thái cụ thể ---
    printf("\nCheck Book Borrowed: %s\n",
           has_flag(book.flags, BOOK_FLAG_BORROWED) ? "YES" : "NO");
    printf("Check User Deleted: %s\n",
           has_flag(user.flags, USER_FLAG_DELETED) ? "YES" : "NO");
    printf("Check Transaction Active: %s\n",
           has_flag(t.flags, TRANSACTION_FLAG_ACTIVE) ? "YES" : "NO");

    // --- Tạm dừng nếu chạy trên Windows ---
    getchar();
    return 0;
}
