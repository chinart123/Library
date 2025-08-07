#include "../include/transaction.h"
#include "../include/book.h"
#include "../include/user.h"
#include "../include/timeline.h"
#include "../include/flags.h"
#include <stdio.h>

void transaction_init(Transaction* t, int id, Book* book, User* user) {
    if (!t || !book || !user) return;

    t->id = id;
    t->book = book;
    t->user = user;
    t->flags = 0;
    set_flag(&t->flags, TRANSACTION_FLAG_ACTIVE);  // Đánh dấu giao dịch đang hoạt động

    timeline_add_event(EVENT_TRANSACTION_CREATE, book->id, user->id);
}

void transaction_print_info(const Transaction* t) {
    if (!t || !t->book || !t->user) return;

    printf("Transaction ID: %d | Book: %s | User: %s | Status: %s\n",
           t->id,
           t->book->title,
           t->user->name,
           has_flag(t->flags, TRANSACTION_FLAG_ACTIVE) ? "Active" : "Returned");
}
