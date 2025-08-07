// test2.c - Check memory layout of struct User
// Purpose: Verify size and alignment of User struct for memory and padding analysis

#include <stdio.h>
#include <stdlib.h>
#include "../../include/user.h"

int main() {
    printf("===== USER STRUCT =====\n");
    printf("Size of int (id)      : %zu bytes\n", sizeof(int));
    printf("Size of name[]        : %zu bytes\n", sizeof(((User*)0)->name));
    printf("Size of bool (deleted): %zu bytes\n", sizeof(((User*)0)->is_deleted));
    printf("Total size of User    : %zu bytes\n", sizeof(User));

    getchar(); // Pause for external console
    return 0;
}
