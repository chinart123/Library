#include "library.h"
#include <stdio.h>
#include <string.h>

void add_book(Book books[], int *count, int id, const char *title, const char *author) {
    books[*count].id = id;
    strncpy(books[*count].title, title, 99);
    books[*count].title[99] = '\0';
    strncpy(books[*count].author, author, 99);
    books[*count].author[99] = '\0';
    books[*count].Book_Status = true;
    books[*count].borrower_id = -1;
    (*count)++;
    printf("Book '%s' added successfully.\n", title);
}

void print_all_books(Book books[], int count) {
    printf("\n=== ALL BOOKS (%d) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        if (books[i].Book_Status) {
            printf("Status: Available\n");
        } else {
            printf("Status: Borrowed (by user ID %d)\n", books[i].borrower_id);
        }
        printf("\n");
    }
}

void print_books_by_title(Book books[], int count, const char *title) {
    printf("\n=== BOOKS WITH TITLE CONTAINING \"%s\" ===\n", title);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            found++;
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            if (books[i].Book_Status) {
                printf("Status: Available\n\n");
            } else {
                printf("Status: Borrowed (by user ID %d)\n\n", books[i].borrower_id);
            }
        }
    }
    if (!found) {
        printf("No books found with title containing: %s\n", title);
    }
}