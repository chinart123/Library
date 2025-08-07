#ifndef BITFLAGS_VIEWER_H
#define BITFLAGS_VIEWER_H

#include <stdint.h>

/*
 * ================================================
 * STAGE B - BƯỚC 1: CHUẨN HOÁ FLAGS (bitmask/bitfield)
 * ================================================
 * Giai đoạn này sẽ áp dụng bitmask cho các đối tượng như:
 * - Book, User, Transaction
 * - Dễ dàng bật/tắt/kiểm tra trạng thái qua các cờ (flag)
 * 
 * File này là bước chuẩn bị cho việc quan sát các cờ đó.
 */

// Bước 1: In nhị phân để quan sát flag rõ hơn
void print_flags_as_binary(uint8_t flags);

// In nhị phân 8-bit (dễ đọc, có khoảng trắng)
void print_binary8(uint8_t value);

// In nhị phân 16-bit (nếu cần mở rộng sau này)
void print_binary16(uint16_t value);

/*
 * ================================================
 * STAGE B - BƯỚC 2: TÁCH GIẢI MÃ FLAGS THEO LOẠI ĐỐI TƯỢNG
 * ================================================
 * Tránh nhầm lẫn khi decode tất cả loại flag trên cùng 1 giá trị
 */

void decode_book_flags(uint8_t flags);
void decode_user_flags(uint8_t flags);
void decode_transaction_flags(uint8_t flags);

#endif // BITFLAGS_VIEWER_H
