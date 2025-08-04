#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h> // For bool type
#include "definitions.h" // Include common definitions

typedef struct {
    int id;                    // Unique book identifier
    char title[MAX_TITLE_LENGTH];  // Book title
    char author[MAX_AUTHOR_LENGTH]; // Book author
    bool is_deleted;           // True if the book is marked as deleted
} Book;

// Function to initialize a book
void book_init(Book *book, int id, const char *title, const char *author);

// Function to print book information
void book_print_info(const Book *book);

#endif