#include "book.h"
#include "transaction.h"
#include <stdio.h>
#include <string.h>

void book_init(Book *book, int id, const char *title, const char *author) {
    if (book == NULL) {
        printf("Error: Invalid book pointer.\n");
        return;
    }
    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';
    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
    book->is_deleted = false;
}

void book_print_info(const Book *book) {
    if (book == NULL) {
        printf("Error: Invalid book pointer.\n");
        return;
    }
    printf("Book ID: %d\n", book->id);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Status: %s\n", book->is_deleted ? "Deleted" : "Active");
}

// Hàm xóa mềm sách. Trả về 1 nếu thành công, 0 nếu thất bại.
int book_delete(Book *book, const Transaction *transactions, int transaction_count) {
    if (book == NULL) {
        printf("Error: Invalid book pointer.\n");
        return 0;
    }
    // Kiểm tra xem sách có đang trong active transaction nào không
    for (int i = 0; i < transaction_count; i++) {
        // So sánh địa chỉ con trỏ để kiểm tra chính xác
        if (transactions[i].book == book && transactions[i].is_active) {
            printf("Error: Cannot delete book '%s' (ID: %d) because it is currently borrowed.\n", book->title, book->id);
            return 0;
        }
    }
    book->is_deleted = true;
    printf("Book '%s' (ID: %d) marked as deleted.\n", book->title, book->id);
    return 1;
}

// Hàm mới: Chỉnh sửa thông tin sách
void book_edit(Book *book, const char *new_title, const char *new_author) {
    if (book == NULL) {
        printf("Error: Invalid book pointer.\n");
        return;
    }
    if (new_title != NULL) {
        strncpy(book->title, new_title, MAX_TITLE_LENGTH - 1);
        book->title[MAX_TITLE_LENGTH - 1] = '\0';
    }
    if (new_author != NULL) {
        strncpy(book->author, new_author, MAX_AUTHOR_LENGTH - 1);
        book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
    }
    printf("Book '%s' (ID: %d) edited successfully.\n", book->title, book->id);
}