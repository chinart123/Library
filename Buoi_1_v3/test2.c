#include <stdio.h>
#include "library.h"
#include "user.h"

// Function to borrow a book with automatic checks
void borrow_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
    Book *book = NULL;
    User *user = NULL;

    for (int i = 0; i < book_count; i++) {
        if (books[i].id == book_id) {
            book = &books[i];
            break;
        }
    }

    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            user = &users[i];
            break;
        }
    }

    if (!book || !user) {
        printf("Error: Invalid book ID or user ID.\n");
        return;
    }

    if (!book->Book_Status) {
        printf("Borrow failed: Book '%s' is not available.\n", book->title);
        return;
    }

    if (!user->User_status) {
        printf("Borrow failed: User '%s' cannot borrow more books (already has %d).\n", user->name, user->Book_borrowed);
        return;
    }

    book->Book_Status = 0;
    book->borrower_id = user->id;
    user->Book_borrowed++;
    user->User_status = (user->Book_borrowed <= 2);

    printf("Book '%s' borrowed by user '%s'.\n", book->title, user->name);
}

// Function to return a book with automatic checks
void return_book(Book books[], int book_count, User users[], int user_count, int book_id, int user_id) {
    Book *book = NULL;
    User *user = NULL;

    for (int i = 0; i < book_count; i++) {
        if (books[i].id == book_id) {
            book = &books[i];
            break;
        }
    }

    for (int i = 0; i < user_count; i++) {
        if (users[i].id == user_id) {
            user = &users[i];
            break;
        }
    }

    if (!book || !user) {
        printf("Error: Invalid book ID or user ID.\n");
        return;
    }

    if (book->Book_Status) {
        printf("Return failed: Book '%s' is not borrowed.\n", book->title);
        return;
    }

    if (book->borrower_id != user->id) {
        printf("Return failed: Book '%s' was borrowed by another user (ID %d).\n", book->title, book->borrower_id);
        return;
    }

    book->Book_Status = 1;
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

    for (int i = 1; i <= 10; i++) {
        char title[20], author[20];
        sprintf(title, "Book %d", i);
        sprintf(author, "Author %d", i);
        add_book(books, &book_count, i, title, author);
    }

    add_user(users, &user_count, 1, "User 1", 0);
    add_user(users, &user_count, 2, "User 2", 1);
    add_user(users, &user_count, 3, "User 3", 2);
    add_user(users, &user_count, 4, "User 4", 3);
    add_user(users, &user_count, 5, "User 5", 0);

    printf("===== INITIAL STATE =====\n");
    print_all_books(books, book_count);
    print_all_users(users, user_count);

    // ==== TEST BORROWING ====
    printf("\n===== TEST BORROWING =====\n");

    printf("\n[TEST 1] User 1 borrows Book 1 (Success):\n");
    borrow_book(books, book_count, users, user_count, 1, 1);

    printf("\n[TEST 2] User 1 borrows Book 1 again (Fail):\n");
    borrow_book(books, book_count, users, user_count, 1, 1);

    printf("\n[TEST 3] User 2 borrows Book 2 (Success):\n");
    borrow_book(books, book_count, users, user_count, 2, 2);

    printf("\n[TEST 4] User 3 borrows Book 3 (Fail - reached limit):\n");
    borrow_book(books, book_count, users, user_count, 3, 3);

    printf("\n[TEST 5] User 4 borrows Book 4 (Fail - cannot borrow more):\n");
    borrow_book(books, book_count, users, user_count, 4, 4);

    printf("\n[TEST 6] User 5 borrows Book 100 (Fail - book not exist):\n");
    borrow_book(books, book_count, users, user_count, 100, 5);

    printf("\n[TEST 7] User 100 borrows Book 5 (Fail - user not exist):\n");
    borrow_book(books, book_count, users, user_count, 5, 100);

    printf("\n[TEST 8] User 3 borrows Book 1 (Fail - already borrowed by another user):\n");
    borrow_book(books, book_count, users, user_count, 1, 3);

    // ==== TEST RETURNING ====
    printf("\n===== TEST RETURNING =====\n");

    printf("\n[TEST 9] User 1 returns Book 1 (Success):\n");
    return_book(books, book_count, users, user_count, 1, 1);

    printf("\n[TEST 10] User 1 returns Book 1 again (Fail - already returned):\n");
    return_book(books, book_count, users, user_count, 1, 1);

    printf("\n[TEST 11] User 1 returns Book 2 (Fail - borrowed by another):\n");
    return_book(books, book_count, users, user_count, 2, 1);

    printf("\n[TEST 12] User 5 returns Book 3 (Fail - not borrowed):\n");
    return_book(books, book_count, users, user_count, 3, 5);

    printf("\n[TEST 13] User 4 returns Book 100 (Fail - book not exist):\n");
    return_book(books, book_count, users, user_count, 100, 4);

    printf("\n[TEST 14] User 100 returns Book 5 (Fail - user not exist):\n");
    return_book(books, book_count, users, user_count, 5, 100);

    printf("\n[TEST 15] User 2 returns Book 2 (Success):\n");
    return_book(books, book_count, users, user_count, 2, 2);

    // ==== SPECIAL CASES ====
    printf("\n===== SPECIAL TESTS =====\n");

    printf("\n[TEST 16] User 3 borrows Book 1 after return (Success):\n");
    borrow_book(books, book_count, users, user_count, 1, 3);

    printf("\n[TEST 17] User 3 borrows Book 5 (Fail - reached limit):\n");
    borrow_book(books, book_count, users, user_count, 5, 3);

    printf("\n[TEST 18] User 3 returns Book 1 (Success):\n");
    return_book(books, book_count, users, user_count, 1, 3);

    printf("\n[TEST 19] User 3 borrows Book 5 after return (Success):\n");
    borrow_book(books, book_count, users, user_count, 5, 3);

    printf("\n[TEST 20] Auto update status after return (User 4 and Book 6):\n");
    books[5].Book_Status = 0;
    books[5].borrower_id = 4;
    users[3].Book_borrowed = 3;

    printf("Before return:\n");
    printf("Book 6 status: %s\n", books[5].Book_Status ? "Available" : "Borrowed");
    printf("User 4 borrowed count: %d, Status: %s\n", users[3].Book_borrowed, users[3].User_status ? "Can borrow" : "Cannot borrow");

    return_book(books, book_count, users, user_count, 6, 4);

    printf("After return:\n");
    printf("Book 6 status: %s\n", books[5].Book_Status ? "Available" : "Borrowed");
    printf("User 4 borrowed count: %d, Status: %s\n", users[3].Book_borrowed, users[3].User_status ? "Can borrow" : "Cannot borrow");

    // Final state
    printf("\n===== FINAL STATE =====\n");
    print_all_books(books, book_count);
    print_all_users(users, user_count);

    return 0;
}
