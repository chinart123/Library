// timeline.c
#include "timeline.h"
#include <stdio.h>

static Event timeline_events[MAX_TIMELINE_EVENTS];
static int event_count = 0;

void timeline_init(void) {
    event_count = 0;
}

void timeline_add_event(EventType type, int book_id, int user_id) {
    if (event_count >= MAX_TIMELINE_EVENTS) {
        printf("Warning: Timeline is full. Cannot add more events.\n");
        return;
    }
    timeline_events[event_count].type = type;
    timeline_events[event_count].book_id = book_id;
    timeline_events[event_count].user_id = user_id;
    event_count++;
}

const char* event_type_to_string(EventType type) {
    switch (type) {
        case EVENT_BORROW: return "BORROW";
        case EVENT_RETURN: return "RETURN";
        case EVENT_BOOK_DELETE: return "BOOK_DELETE";
        case EVENT_USER_DELETE: return "USER_DELETE";
        case EVENT_BOOK_EDIT_TITLE: return "BOOK_EDIT_TITLE";
        case EVENT_BOOK_EDIT_AUTHOR: return "BOOK_EDIT_AUTHOR";
        case EVENT_USER_EDIT_NAME: return "USER_EDIT_NAME";
        case EVENT_BOOK_CREATE: return "BOOK_CREATE";
        case EVENT_USER_CREATE: return "USER_CREATE";
        case EVENT_BOOK_RESTORE: return "BOOK_RESTORE";
        case EVENT_USER_RESTORE: return "USER_RESTORE";
        case EVENT_BORROW_FAILED_LIMIT: return "BORROW_FAILED_LIMIT";
        default: return "UNKNOWN_EVENT";
    }
}

void timeline_print_all_events(void) {
    printf("\n=============================== SYSTEM TIMELINE ===============================\n");
    for (int i = 0; i < event_count; i++) {
        printf("Event %d: Type: %s, Book ID: %d, User ID: %d\n",
               i + 1, event_type_to_string(timeline_events[i].type),
               timeline_events[i].book_id, timeline_events[i].user_id);
    }
    printf("===============================================================================\n");
}