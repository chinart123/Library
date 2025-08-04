#include <stdio.h>
#include "library.h"
#include "user.h"

// Function to borrow a book
void borrow_book(Book *book, User *user) {
    if (book->Book_Status && user->User_status) {
        book->Book_Status = false;
        book->borrower_id = user->id;
        user->Book_borrowed++;
        user->User_status = (user->Book_borrowed <= 2);
        printf("Book '%s' borrowed by %s\n", book->title, user->name);
    } else {
        printf("Cannot borrow book. ");
        
        if (!book->Book_Status) {
            printf("Book is not available. ");
        }
        
        if (!user->User_status) {
            printf("User cannot borrow more books. ");
        }
        
        printf("\n");
    }
}

// Function to return a book
void return_book(Book *book, User *user) {
    if (!book->Book_Status && book->borrower_id == user->id) {
        book->Book_Status = true;
        book->borrower_id = -1;
        user->Book_borrowed--;
        user->User_status = (user->Book_borrowed <= 2);
        printf("Book '%s' returned by %s\n", book->title, user->name);
    } else {
        printf("Return failed. ");
        
        if (book->Book_Status) {
            printf("Book was not borrowed. ");
        } else if (book->borrower_id != user->id) {
            printf("This user didn't borrow this book. ");
        }
        
        printf("\n");
    }
}

int main() {
    // Create book and user arrays
    Book books[10];
    User users[10];
    int book_count = 0;
    int user_count = 0;
    
    // Add sample books
    add_book(books, &book_count, 1, "The C Programming Language", "K&R");
    add_book(books, &book_count, 2, "Clean Code", "Robert C. Martin");
    
    // Add sample users
    add_user(users, &user_count, 101, "Alice", 0);
    add_user(users, &user_count, 102, "Bob", 2);
    
    // Test 1: Alice borrows a book
    printf("\n=== TEST 1: Alice borrows a book ===\n");
    borrow_book(&books[0], &users[0]);
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    // Test 2: Bob tries to borrow a book (should fail)
    printf("\n=== TEST 2: Bob tries to borrow a book ===\n");
    borrow_book(&books[1], &users[1]);
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    // Test 3: Alice returns the book
    printf("\n=== TEST 3: Alice returns the book ===\n");
    return_book(&books[0], &users[0]);
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    // Test 4: Bob borrows after Alice returns
    printf("\n=== TEST 4: Bob borrows after status reset ===\n");
    borrow_book(&books[1], &users[1]); // Should still fail
    borrow_book(&books[0], &users[1]); // Should succeed
    print_all_books(books, book_count);
    print_all_users(users, user_count);
    
    return 0;
}