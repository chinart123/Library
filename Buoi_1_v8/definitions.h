#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdbool.h>

// Định nghĩa các hằng số về kích thước dữ liệu
#define MAX_TITLE_LENGTH 100        // Độ dài tối đa của tiêu đề sách
#define MAX_AUTHOR_LENGTH 100       // Độ dài tối đa của tên tác giả
#define MAX_NAME_LENGTH 100         // Độ dài tối đa của tên người dùng
#define MAX_TRANSACTIONS 100        // Số giao dịch tối đa
#define MAX_BOOKS_PER_USER 3        // Số sách tối đa một người dùng có thể mượn
#define MAX_TIMELINE_EVENTS 200     // Số sự kiện timeline tối đa

// SUPPORT FOR test10.c
#define MAX_BOOKS 100 // Thêm dòng này để định nghĩa MAX_BOOKS
#define MAX_USERS 100 // Thêm dòng này để định nghĩa MAX_USERS

// Định nghĩa các loại sự kiện bằng hằng số để sử dụng trong timeline

// SUPPORT FOR test8.c
#define EVENT_BORROW 1              // Sự kiện mượn sách
#define EVENT_RETURN 2              // Sự kiện trả sách
#define EVENT_BOOK_DELETE 3         // Sự kiện xóa mềm sách
#define EVENT_USER_DELETE 4         // Sự kiện xóa mềm người dùng

// SUPPORT FOR test9.c
#define EVENT_BOOK_EDIT_TITLE 5     // Sự kiện chỉnh sửa tiêu đề sách
#define EVENT_BOOK_EDIT_AUTHOR 6    // Sự kiện chỉnh sửa tác giả sách
#define EVENT_USER_EDIT_NAME 7      // Sự kiện chỉnh sửa tên người dùng

// SUPPORT FOR test10.c
#define EVENT_BOOK_CREATE 8         // Sự kiện tạo mới sách
#define EVENT_USER_CREATE 9         // Sự kiện tạo mới người dùng
#define EVENT_BOOK_RESTORE 10       // Sự kiện phục hồi sách
#define EVENT_USER_RESTORE 11       // Sự kiện phục hồi người dùng
// SUPPORT FOR test13.c
#define EVENT_BORROW_FAILED_LIMIT 12 // Sự kiện mượn sách thất bại do vượt quá giới hạn

#endif