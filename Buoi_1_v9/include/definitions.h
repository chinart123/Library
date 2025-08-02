#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdbool.h>

// Define constants
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_NAME_LENGTH 100
#define MAX_TRANSACTIONS 100
#define MAX_BOOKS_PER_USER 3
#define MAX_TIMELINE_EVENTS 200
#define MAX_BOOKS 100
#define MAX_USERS 100

// Forward declarations
typedef struct Book Book;
typedef struct User User;
typedef struct Transaction Transaction;

// Event types
typedef int EventType;
#define EVENT_BORROW 1
#define EVENT_RETURN 2
#define EVENT_BORROW_FAILED_LIMIT 12
#define EVENT_BOOK_DELETE 3
#define EVENT_BOOK_CREATE 8
#define EVENT_BOOK_EDIT_TITLE 5
#define EVENT_BOOK_EDIT_AUTHOR 6
#define EVENT_BOOK_RESTORE 10
#define EVENT_USER_DELETE 4
#define EVENT_USER_CREATE 9
#define EVENT_USER_EDIT_NAME 7
#define EVENT_USER_RESTORE 11

// Function results
typedef enum {
    RESULT_SUCCESS,
    RESULT_FAILED_INVALID_INPUT,
    RESULT_FAILED_NOT_FOUND,
    RESULT_FAILED_ACTIVE_TRANSACTION
} FunctionResult;

#endif // DEFINITIONS_H