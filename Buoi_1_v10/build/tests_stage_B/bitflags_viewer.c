#include <stdio.h>
#include "../include/bitflags_viewer.h"
#include "../include/flags.h"  // Sử dụng để giải mã theo flag định nghĩa sẵn

// ===============================================
// STAGE B - BƯỚC 1: IN NHỊ PHÂN FLAGS
// ===============================================

void print_binary8(uint8_t value) {
    for (int i = 7; i >= 0; --i) {
        printf("%d", (value >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

void print_binary16(uint16_t value) {
    for (int i = 15; i >= 0; --i) {
        printf("%d", (value >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

void print_flags_as_binary(uint8_t flags) {
    printf("Binary: ");
    print_binary8(flags);
}

// ===============================================
// STAGE B - BƯỚC 2: GIẢI MÃ FLAGS RIÊNG CHO TỪNG ĐỐI TƯỢNG
// ===============================================

void decode_book_flags(uint8_t flags) {
    printf("Decoded Book Flags:\n");
    int count = 0;
    if (flags & BOOK_FLAG_DELETED)  { printf("- BOOK_FLAG_DELETED\n"); count++; }
    if (flags & BOOK_FLAG_ACTIVE)   { printf("- BOOK_FLAG_ACTIVE\n"); count++; }
    if (flags & BOOK_FLAG_BORROWED) { printf("- BOOK_FLAG_BORROWED\n"); count++; }
    if (flags & BOOK_FLAG_ARCHIVED) { printf("- BOOK_FLAG_ARCHIVED\n"); count++; }
    if (count == 0) printf("(No valid Book flags found)\n");
}

void decode_user_flags(uint8_t flags) {
    printf("Decoded User Flags:\n");
    int count = 0;
    if (flags & USER_FLAG_DELETED)  { printf("- USER_FLAG_DELETED\n"); count++; }
    if (flags & USER_FLAG_ACTIVE)   { printf("- USER_FLAG_ACTIVE\n"); count++; }
#ifdef USER_FLAG_ADMIN
    if (flags & USER_FLAG_ADMIN)    { printf("- USER_FLAG_ADMIN\n"); count++; }
#endif
    if (count == 0) printf("(No valid User flags found)\n");
}

void decode_transaction_flags(uint8_t flags) {
    printf("Decoded Transaction Flags:\n");
    int count = 0;
    if (flags & TRANSACTION_FLAG_ACTIVE) { printf("- TRANSACTION_FLAG_ACTIVE\n"); count++; }
    if (flags & TRANSACTION_FLAG_FAILED) { printf("- TRANSACTION_FLAG_FAILED\n"); count++; }
    if (count == 0) printf("(No valid Transaction flags found)\n");
}
