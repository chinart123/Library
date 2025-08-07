#include <stdio.h>
#include <string.h>  // for memset
#include <stdlib.h>

#include "../include/flags.h"
#include "../include/bitflags_viewer.h"
#include "../include/definitions.h"
#include "../include/user.h"

int main() {
    printf("=== TEST10: POTENTIAL FLAG BUG ===\n\n");

    User user;
    memset(&user, 0, sizeof(User));
    user.id = 999;
    set_flag(&user.flags, USER_FLAG_DELETED);

    // Correct usage
    printf("User flags (correct decoder):\n");
    print_flags_as_binary(user.flags);
    decode_user_flags(user.flags);

    // Intentional misuse: decoding with the wrong group
    printf("\nUser flags (wrong decoder - Book):\n");
    decode_book_flags(user.flags);  // should print nothing or incorrect results

    getchar();
    return 0;
}
