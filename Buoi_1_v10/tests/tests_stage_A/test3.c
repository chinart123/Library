// test3.c - Check memory layout of struct Book
// Purpose: Verify size and alignment of Book struct for memory and padding analysis

#include <stdio.h>
#include <stdlib.h>
#include "../../include/book.h"

int main() {
    printf("===== BOOK STRUCT =====\n");
    printf("Size of int (id)         : %zu bytes\n", sizeof(int));
    printf("Size of title[]          : %zu bytes\n", sizeof(((Book*)0)->title));
    printf("Size of author[]         : %zu bytes\n", sizeof(((Book*)0)->author));
    printf("Size of bool (is_deleted): %zu bytes\n", sizeof(((Book*)0)->is_deleted));
    printf("Total size of Book       : %zu bytes\n", sizeof(Book));

    getchar(); // Pause for external console
    return 0;
}
