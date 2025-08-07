// test5.c - Check memory layout of struct Event (Timeline)
// Purpose: Verify size and layout of Event used for timeline logging

#include <stdio.h>
#include <stdlib.h>
#include "../../include/timeline.h"

int main() {
    printf("===== EVENT STRUCT (TIMELINE) =====\n");
    printf("Size of type (int)     : %zu bytes\n", sizeof(int));
    printf("Size of book_id (int)  : %zu bytes\n", sizeof(int));
    printf("Size of user_id (int)  : %zu bytes\n", sizeof(int));
    printf("Total size of Event    : %zu bytes\n", sizeof(Event));

    getchar(); // Pause for external console
    return 0;
}
