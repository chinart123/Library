#include "library.h"
#include <stdio.h>
#include <string.h>

void add_book(Book books[], int *count, int id, const char *title, const char *author) {
    books[*count].id = id;
    strncpy(books[*count].title, title, 99);
    strncpy(books[*count].author, author, 99);
    books[*count].Book_Status = true; // Initially available
    books[*count].borrower_id = -1;   // No borrower initially
    (*count)++;
}

void print_all_books(Book books[], int count) {
    printf("\n=== ALL BOOKS ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Status: %s\n", books[i].Book_Status ? "Available" : "Borrowed");
        
        if (!books[i].Book_Status) {
            printf("Borrowed by user ID: %d\n", books[i].borrower_id);
        }
        printf("\n");
    }
}

void print_books_by_title(Book books[], int count, const char *title) {
    printf("\n=== BOOKS WITH TITLE CONTAINING \"%s\" ===\n", title);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Status: %s\n\n", books[i].Book_Status ? "Available" : "Borrowed");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found.\n");
    }
}