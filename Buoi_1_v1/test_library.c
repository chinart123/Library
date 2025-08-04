#include "library.h"
#include <stdio.h>

int main() {
    Book books[MAX_BOOKS];
    int book_count = 0;
    
    // Test book functions
    add_book(books, &book_count, 1, "The C Programming Language", "K&R");
    add_book(books, &book_count, 2, "Clean Code", "Robert C. Martin");
    
    books[0].status = false; // Mark first book as borrowed
    
    print_all_books(books, book_count);
    print_books_by_title(books, book_count, "C Programming");
    
    return 0;
}