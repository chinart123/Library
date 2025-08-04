#include "library.h"
#include <stdio.h>
#include <string.h>

// Add a new book to the system
void add_book(Book books[], int *count, int id, const char *title, const char *author) {
    if (*count >= MAX_BOOKS) {
        printf("Book storage full!\n");
        return;
    }
    
    books[*count].id = id;
    strncpy(books[*count].title, title, 99);
    strncpy(books[*count].author, author, 99);
    books[*count].status = true; // Default status: Available
    
    (*count)++;
    printf("Book added successfully!\n");
}

// Print all books with status
void print_all_books(Book books[], int count) {
    printf("\n=== ALL BOOKS ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Status: %s\n\n", books[i].status ? "Available" : "Borrowed");
    }
}

// Search and print books by title
void print_books_by_title(Book books[], int count, const char *title) {
    printf("\n=== SEARCH RESULTS ===\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Status: %s\n\n", books[i].status ? "Available" : "Borrowed");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found with title: %s\n", title);
    }
}