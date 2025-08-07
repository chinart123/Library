#include "../include/timeline.h"
#include <stdio.h>

// Bộ nhớ lưu sự kiện
static Event timeline_events[MAX_TIMELINE_EVENTS];
static int event_count = 0;

// Khởi tạo timeline
void timeline_init(void) {
    event_count = 0;
}

// Thêm sự kiện vào timeline
void timeline_add_event(EventType type, int book_id, int user_id) {
    if (event_count >= MAX_TIMELINE_EVENTS) return;

    timeline_events[event_count].type = type;
    timeline_events[event_count].book_id = book_id;
    timeline_events[event_count].user_id = user_id;
    event_count++;
}

// Chuyển enum EventType thành chuỗi dễ đọc
const char* event_type_to_string(EventType type) {
    switch (type) {
        case EVENT_BORROW:              return "BORROW";
        case EVENT_RETURN:              return "RETURN";
        case EVENT_BOOK_CREATE:         return "BOOK_CREATE";
        case EVENT_USER_CREATE:         return "USER_CREATE";
        case EVENT_TRANSACTION_CREATE:  return "TRANSACTION_CREATE";
        default:                        return "UNKNOWN_EVENT";
    }
}

// In toàn bộ timeline
void timeline_print_all_events(void) {
    printf("\n===== TIMELINE EVENTS =====\n");
    for (int i = 0; i < event_count; ++i) {
        printf("Event %d: Type: %s | Book ID: %d | User ID: %d\n",
               i + 1,
               event_type_to_string(timeline_events[i].type),
               timeline_events[i].book_id,
               timeline_events[i].user_id);
    }
}
