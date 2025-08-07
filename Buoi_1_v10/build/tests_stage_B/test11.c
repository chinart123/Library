#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/flags.h"
#include "../include/bitflags_viewer.h"
#include "../include/definitions.h"
#include "../include/user.h"

/*
 * TEST11_COMBINED: Unified test to demonstrate potential bugs
 * when decoding flag values with the wrong decoder.
 * 
 * Shows:
 * - Correct vs. incorrect decoding for USER flags.
 * - Correct vs. incorrect decoding for TRANSACTION flags.
 */

int main() {
    printf("=== TEST11_COMBINED: POTENTIAL FLAG DECODING BUGS ===\n\n");

    // --------------------------
    // USER TEST
    // --------------------------
    uint8_t user_flags = 0;
    set_flag(&user_flags, USER_FLAG_DELETED);

    printf("User flags (correct decoder):\n");
    print_flags_as_binary(user_flags);
    decode_user_flags(user_flags);

    printf("\nUser flags (wrong decoder - Book):\n");
    decode_book_flags(user_flags);

    printf("\nUser flags (wrong decoder - Transaction):\n");
    decode_transaction_flags(user_flags);

    // --------------------------
    // TRANSACTION TEST
    // --------------------------
    uint8_t transaction_flags = 0;
    set_flag(&transaction_flags, TRANSACTION_FLAG_ACTIVE);

    printf("\nTransaction flags (correct decoder):\n");
    print_flags_as_binary(transaction_flags);
    decode_transaction_flags(transaction_flags);

    printf("\nTransaction flags (wrong decoder - Book):\n");
    decode_book_flags(transaction_flags);

    printf("\nTransaction flags (wrong decoder - User):\n");
    decode_user_flags(transaction_flags);

    getchar();
    return 0;
}
