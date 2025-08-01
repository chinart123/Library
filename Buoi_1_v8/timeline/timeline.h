#ifndef TIMELINE_H
#define TIMELINE_H

#include <time.h>
#include "../definitions.h"
#include "../book.h"
#include "../user.h"

// Cấu trúc để lưu một sự kiện
typedef struct {
    time_t timestamp; // Thời gian xảy ra sự kiện
    int event_type;   // Loại sự kiện (dựa trên các hằng số ở definitions.h)
    int book_id;      // ID của sách liên quan
    int user_id;      // ID của người dùng liên quan
} TimelineEvent;

// Các hàm public của module timeline
void timeline_init();
void timeline_add_event(int event_type, int book_id, int user_id);
void timeline_print_all_events();

// SUPPORT FOR test11.c
void timeline_print_events_by_type(int event_type);
void timeline_print_events_by_book(int book_id);
void timeline_print_events_by_user(int user_id);
#endif