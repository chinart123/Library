#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdbool.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    bool Book_Status; // true: Available, false: Borrowed
    int borrower_id;  // ID of user who borrowed the book
} Book;

void add_book(Book books[], int *count, int id, const char *title, const char *author);
void print_all_books(Book books[], int count);
void print_books_by_title(Book books[], int count, const char *title);

#endif