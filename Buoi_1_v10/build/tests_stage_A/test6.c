// test6.c - Check memory layout of struct Library
// Purpose: Verify total memory used by arrays of Book, User, and Transaction

#include <stdio.h>
#include <stdlib.h>
#include "../../include/library.h"

int main() {
    printf("===== LIBRARY STRUCT =====\n");
    printf("Size of Book array       : %zu bytes\n", sizeof(((Library*)0)->books));
    printf("Size of User array       : %zu bytes\n", sizeof(((Library*)0)->users));
    printf("Size of Transaction array: %zu bytes\n", sizeof(((Library*)0)->transactions));
    printf("Total size of Library    : %zu bytes\n", sizeof(Library));

    getchar(); // Pause for external console
    return 0;
}
