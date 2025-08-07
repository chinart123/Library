// test7.c
// 📌 Mô phỏng tạo Transaction KHÔNG dùng malloc (an toàn cho STM32)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definitions.h"
#include "transaction.h"
#include "user.h"
#include "book.h"
#include "library.h"
#include "timeline.h"

// Hàm tạo transaction không dùng malloc (sử dụng struct tĩnh trong Library)
void create_transaction(Library* lib, int trans_id, int book_index, int user_index) {
    if (lib->transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached.\n");
        return;
    }

    Transaction* t = &lib->transactions[lib->transaction_count++];
    t->id = trans_id;
    t->book = &lib->books[book_index];
    t->user = &lib->users[user_index];
    t->is_active = true;

    // Ghi sự kiện
    timeline_add_event(EVENT_TRANSACTION_CREATE, t->book->id, t->user->id);
}

int main() {
    Library library = {0};
    timeline_init();  // Đừng quên reset timeline

    // Giả lập book và user có sẵn
    library.books[0].id = 101;
    library.users[0].id = 202;

    create_transaction(&library, 1, 0, 0);

    printf("Transaction ID: %d\n", library.transactions[0].id);
    printf("Book ID: %d\n", library.transactions[0].book->id);
    printf("User ID: %d\n", library.transactions[0].user->id);
    printf("Is Active: %d\n", library.transactions[0].is_active);

    timeline_print_all_events();

    getchar(); // Giữ external console
    return 0;
}
