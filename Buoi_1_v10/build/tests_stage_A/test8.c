// test8.c
// ⚠ Mô phỏng tạo Transaction DÙNG malloc (KHÔNG khuyến khích trên STM32)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definitions.h"
#include "transaction.h"
#include "user.h"
#include "book.h"
#include "timeline.h"

// Tạo transaction trên heap bằng malloc
Transaction* create_transaction_dynamic(int trans_id, Book* book, User* user) {
    Transaction* t = (Transaction*)malloc(sizeof(Transaction));
    if (!t) return NULL;

    t->id = trans_id;
    t->book = book;
    t->user = user;
    t->is_active = true;

    // Ghi sự kiện
    timeline_add_event(EVENT_TRANSACTION_CREATE, book->id, user->id);
    return t;
}

int main() {
    timeline_init();  // Reset timeline

    // Cấp phát động cho book và user
    Book* book = (Book*)malloc(sizeof(Book));
    User* user = (User*)malloc(sizeof(User));

    if (!book || !user) {
        printf("Failed to allocate memory for book or user.\n");
        return 1;
    }

    book->id = 301;
    user->id = 401;

    Transaction* t = create_transaction_dynamic(2, book, user);
    if (!t) {
        printf("Failed to allocate transaction.\n");
        return 1;
    }

    printf("Transaction ID: %d\n", t->id);
    printf("Book ID: %d\n", t->book->id);
    printf("User ID: %d\n", t->user->id);
    printf("Is Active: %d\n", t->is_active);

    timeline_print_all_events();

    // Giải phóng bộ nhớ
    free(book);
    free(user);
    free(t);

    getchar(); // Giữ external console
    return 0;
}
