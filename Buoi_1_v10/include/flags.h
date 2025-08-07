#ifndef FLAGS_H
#define FLAGS_H

#include <stdint.h>

/*
 * ======================================
 * FLAGS THEO TỪNG ĐỐI TƯỢNG (8-bit)
 * ======================================
 * - Mỗi nhóm flag sử dụng các bit khác nhau
 * - Tránh trùng lặp khi in/debug
 */

// ==== BOOK FLAGS (bits 0-3) ====
#define BOOK_FLAG_DELETED     0x01  // 00000001
#define BOOK_FLAG_ACTIVE      0x02  // 00000010
#define BOOK_FLAG_BORROWED    0x04  // 00000100
#define BOOK_FLAG_ARCHIVED    0x08  // 00001000

// ==== USER FLAGS (bits 4-5) ====
#define USER_FLAG_DELETED     0x10  // 00010000
#define USER_FLAG_ACTIVE      0x20  // 00100000


// ==== TRANSACTION FLAGS (bits 6-7) ====
#define TRANSACTION_FLAG_ACTIVE   0x80  // 10000000
#define TRANSACTION_FLAG_FAILED   0x40  // 01000000

// ===== HÀM FLAG CHUNG CHO MỌI ĐỐI TƯỢNG =====
static inline int has_flag(uint8_t flags, uint8_t flag) {
    return (flags & flag) != 0;
}

static inline void set_flag(uint8_t* flags, uint8_t flag) {
    *flags |= flag;
}

static inline void clear_flag(uint8_t* flags, uint8_t flag) {
    *flags &= ~flag;
}

static inline void toggle_flag(uint8_t* flags, uint8_t flag) {
    *flags ^= flag;
}

#endif // FLAGS_H
