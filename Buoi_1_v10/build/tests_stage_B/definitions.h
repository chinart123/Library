#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdbool.h>

// ======================
// 📦 CẤU HÌNH DỰ ÁN
// ======================
#define MAX_TITLE_LENGTH 100      // Độ dài tối đa của tên sách
#define MAX_AUTHOR_LENGTH 100     // Độ dài tối đa của tên tác giả
#define MAX_NAME_LENGTH 100       // Độ dài tối đa của tên người dùng

#define MAX_BOOKS 20              // Số sách tối đa
#define MAX_USERS 10              // Số người dùng tối đa
#define MAX_TRANSACTIONS 20       // Số giao dịch tối đa
#define MAX_BOOKS_PER_USER 3      // Số sách tối đa mỗi người có thể mượn
#define MAX_TIMELINE_EVENTS 200   // Số sự kiện tối đa lưu trữ

// ======================
// 📌 ĐỊNH NGHĨA KIỂU DỮ LIỆU
// ======================

// Forward declarations cho các struct sử dụng con trỏ chéo
typedef struct Book Book;
typedef struct User User;
typedef struct Transaction Transaction;

// Kiểu định danh cho sự kiện
typedef int EventType;

// ======================
// 📜 DANH SÁCH CÁC SỰ KIỆN
// ======================
#define EVENT_BORROW                 1   // (Chưa dùng)
#define EVENT_RETURN                 2   // (Tương lai sẽ dùng)
#define EVENT_BOOK_CREATE           8   // Đã tạo sách
#define EVENT_USER_CREATE           9   // Đã tạo người dùng
#define EVENT_TRANSACTION_CREATE   13   // Tạo giao dịch mượn sách

// ======================
// 🧪 ENUM: KẾT QUẢ TRẢ VỀ
// ======================
typedef enum {
    RESULT_SUCCESS,
    RESULT_FAILED_INVALID_INPUT,
    RESULT_FAILED_NOT_FOUND,
    RESULT_FAILED_ACTIVE_TRANSACTION
} FunctionResult;

#endif // DEFINITIONS_H
