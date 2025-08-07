// tests/tests_stage_A/test1.c

#include <stdio.h>
#include "../../include/library.h"
#include "../../include/definitions.h"
#include "../../include/book.h"
#include "../../include/user.h"
#include "../../include/transaction.h"
#include "../../include/timeline.h"
#include <stdlib.h>

/**
 * @brief In ra kích thước của từng struct và tổng bộ nhớ chiếm dụng bởi Library
 */
void library_print_stats(void) {
    size_t book_size = sizeof(Book);
    size_t user_size = sizeof(User);
    size_t transaction_size = sizeof(Transaction);
    size_t library_size = sizeof(Library);

    printf("===== STRUCT SIZE CHECK =====\n");
    printf("Size of Book       : %zu bytes\n", book_size);
    printf("Size of User       : %zu bytes\n", user_size);
    printf("Size of Transaction: %zu bytes\n", transaction_size);
    printf("Size of Library    : %zu bytes\n", library_size);
    printf("\n");

    printf("===== LIBRARY MEMORY USAGE =====\n");
    printf("Total memory for books       : %zu bytes (%zu KB)\n", book_size * MAX_BOOKS, book_size * MAX_BOOKS / 1024);
    printf("Total memory for users       : %zu bytes (%zu KB)\n", user_size * MAX_USERS, user_size * MAX_USERS / 1024);
    printf("Total memory for transactions: %zu bytes (%zu KB)\n", transaction_size * MAX_TRANSACTIONS, transaction_size * MAX_TRANSACTIONS / 1024);
    printf("Total Library struct size    : %zu bytes (%zu KB)\n", library_size, library_size / 1024);
}

/**
 * @brief Hàm main gọi test sizeof và in thống kê Library
 */
int main(void) {
    timeline_init();  // Chuẩn bị timeline để debug nếu cần
    library_print_stats();

    // Nếu bạn muốn log timeline test:
    timeline_add_event(EVENT_BOOK_CREATE, 1, 0);
    timeline_add_event(EVENT_USER_CREATE, 0, 1);

    timeline_print_all_events();

    getchar();
    return 0;
}
