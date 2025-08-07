// test4.c - Check memory layout of struct Transaction
// Purpose: Verify size and pointer alignment in Transaction struct

#include <stdio.h>
#include <stdlib.h>
#include "../../include/transaction.h"

int main() {
    printf("===== TRANSACTION STRUCT =====\n");
    printf("Size of int (id)           : %zu bytes\n", sizeof(int));
    printf("Size of pointer to Book    : %zu bytes\n", sizeof(Book*));
    printf("Size of pointer to User    : %zu bytes\n", sizeof(User*));
    printf("Size of bool (is_active)   : %zu bytes\n", sizeof(((Transaction*)0)->is_active));
    printf("Total size of Transaction  : %zu bytes\n", sizeof(Transaction));

    getchar(); // Pause for external console
    return 0;
}
