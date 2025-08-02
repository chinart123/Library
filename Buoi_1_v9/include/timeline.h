#ifndef TIMELINE_H
#define TIMELINE_H

#include <stdbool.h>
#include "definitions.h"

typedef struct Event {
    EventType type;
    int book_id;
    int user_id;
} Event;

// Function declarations
void timeline_init(void);
void timeline_add_event(EventType type, int book_id, int user_id);
void timeline_print_all_events(void);
const char* event_type_to_string(EventType type);

#endif // TIMELINE_H