#include "../include/transaction.h"
#include "../include/book.h"
#include "../include/user.h"
#include "../include/timeline.h"
#include <stdio.h>

// Khởi tạo giao dịch: liên kết book + user, đặt trạng thái là đang mượn
void transaction_init(Transaction* t, int id, Book* book, User* user) {
    if (!t || !book || !user) return;

    t->id = id;
    t->book = book;
    t->user = user;
    t->is_active = true;

    // Ghi lại sự kiện tạo giao dịch (khác với sự kiện mượn)
    timeline_add_event(EVENT_TRANSACTION_CREATE, book->id, user->id);
}

// In thông tin giao dịch
void transaction_print_info(const Transaction* t) {
    if (!t || !t->book || !t->user) return;

    printf("Transaction ID: %d | Book: %s | User: %s | Status: %s\n",
           t->id,
           t->book->title,
           t->user->name,
           t->is_active ? "Active" : "Returned");
}
