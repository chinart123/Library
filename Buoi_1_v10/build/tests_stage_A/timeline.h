// include/timeline.h
#ifndef TIMELINE_H
#define TIMELINE_H

#include "definitions.h"

// Cấu trúc sự kiện
typedef struct {
    EventType type;
    int book_id;
    int user_id;
} Event;

// Khởi tạo hệ thống sự kiện
void timeline_init(void);

// Thêm một sự kiện vào timeline
void timeline_add_event(EventType type, int book_id, int user_id);

// In toàn bộ timeline
void timeline_print_all_events(void);

#endif // TIMELINE_H
