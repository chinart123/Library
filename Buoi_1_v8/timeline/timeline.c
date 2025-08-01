#include "timeline.h"
#include <stdio.h>
#include <string.h>

static TimelineEvent timeline_events[MAX_TIMELINE_EVENTS];
static int timeline_count = 0;

void timeline_init() {
    timeline_count = 0;
    printf("Timeline initialized.\n");
}

void timeline_add_event(int event_type, int book_id, int user_id) {
    if (timeline_count >= MAX_TIMELINE_EVENTS) {
        printf("Error: Timeline is full. Cannot add new event.\n");
        return;
    }

    TimelineEvent new_event;
    new_event.timestamp = time(NULL);
    new_event.event_type = event_type;
    new_event.book_id = book_id;
    new_event.user_id = user_id;

    timeline_events[timeline_count++] = new_event;
}

// SUPPORT FOR test11.c & test13.c
// Hàm phụ trợ để in một sự kiện cụ thể, tránh lặp code
static void print_single_event(const TimelineEvent *event) {
    char timestamp_str[50];
    struct tm *local_time = localtime(&event->timestamp);
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", local_time);

    printf("[%s] ", timestamp_str);
    switch (event->event_type) {
        case EVENT_BORROW:
            printf("User ID %d borrowed Book ID %d.\n", event->user_id, event->book_id);
            break;
        case EVENT_RETURN:
            printf("User ID %d returned Book ID %d.\n", event->user_id, event->book_id);
            break;
        case EVENT_BOOK_DELETE:
            printf("Book ID %d was soft-deleted.\n", event->book_id);
            break;
        case EVENT_USER_DELETE:
            printf("User ID %d was soft-deleted.\n", event->user_id);
            break;
        case EVENT_BOOK_EDIT_TITLE:
            printf("Title of Book ID %d was edited.\n", event->book_id);
            break;
        case EVENT_BOOK_EDIT_AUTHOR:
            printf("Author of Book ID %d was edited.\n", event->book_id);
            break;
        case EVENT_USER_EDIT_NAME:
            printf("Name of User ID %d was edited.\n", event->user_id);
            break;
        case EVENT_BOOK_CREATE:
            printf("Book ID %d was created.\n", event->book_id);
            break;
        case EVENT_USER_CREATE:
            printf("User ID %d was created.\n", event->user_id);
            break;
        case EVENT_BOOK_RESTORE:
            printf("Book ID %d was restored.\n", event->book_id);
            break;
        case EVENT_USER_RESTORE:
            printf("User ID %d was restored.\n", event->user_id);
            break;
        // SUPPORT FOR test13.c
        case EVENT_BORROW_FAILED_LIMIT:
            printf("User ID %d failed to borrow Book ID %d due to borrowing limit.\n", event->user_id, event->book_id);
            break;
        default:
            printf("Unknown event.\n");
            break;
    }
}

// Sửa lại hàm này để gọi hàm phụ trợ
void timeline_print_all_events() {
    printf("\n=================================== FULL TIMELINE ====================================\n");
    if (timeline_count == 0) {
        printf("No events to display.\n");
        return;
    }
    
    for (int i = 0; i < timeline_count; i++) {
        print_single_event(&timeline_events[i]);
    }
}

// SUPPORT FOR test11.c & test13.c
void timeline_print_events_by_type(int event_type) {
    printf("\n=================================== TIMELINE BY EVENT TYPE ====================================\n");
    if (timeline_count == 0) {
        printf("No events to display.\n");
        return;
    }
    
    int found_count = 0;
    for (int i = 0; i < timeline_count; i++) {
        if (timeline_events[i].event_type == event_type) {
            print_single_event(&timeline_events[i]);
            found_count++;
        }
    }
    if (found_count == 0) {
        printf("No events of type %d found.\n", event_type);
    }
}

// SUPPORT FOR test11.c & test13.c
void timeline_print_events_by_book(int book_id) {
    printf("\n=================================== TIMELINE FOR BOOK ID %d ====================================\n", book_id);
    if (timeline_count == 0) {
        printf("No events to display.\n");
        return;
    }
    
    int found_count = 0;
    for (int i = 0; i < timeline_count; i++) {
        if (timeline_events[i].book_id == book_id) {
            print_single_event(&timeline_events[i]);
            found_count++;
        }
    }
    if (found_count == 0) {
        printf("No events found for Book ID %d.\n", book_id);
    }
}

// SUPPORT FOR test11.c & test13.c
void timeline_print_events_by_user(int user_id) {
    printf("\n=================================== TIMELINE FOR USER ID %d ====================================\n", user_id);
    if (timeline_count == 0) {
        printf("No events to display.\n");
        return;
    }
    
    int found_count = 0;
    for (int i = 0; i < timeline_count; i++) {
        if (timeline_events[i].user_id == user_id) {
            print_single_event(&timeline_events[i]);
            found_count++;
        }
    }
    if (found_count == 0) {
        printf("No events found for User ID %d.\n", user_id);
    }
}


// #include "timeline.h"
// #include <stdio.h>

// static TimelineEvent timeline_events[MAX_TIMELINE_EVENTS];
// static int timeline_count = 0;

// void timeline_init() {
//     timeline_count = 0;
//     printf("Timeline initialized.\n");
// }

// void timeline_add_event(int event_type, int book_id, int user_id) {
//     if (timeline_count >= MAX_TIMELINE_EVENTS) {
//         printf("Error: Timeline is full. Cannot add new event.\n");
//         return;
//     }

//     TimelineEvent new_event;
//     new_event.timestamp = time(NULL);
//     new_event.event_type = event_type;
//     new_event.book_id = book_id;
//     new_event.user_id = user_id;

//     timeline_events[timeline_count++] = new_event;
// }

// // SUPPORT FOR test11.c
// // Hàm in một sự kiện cụ thể
// static void print_single_event(const TimelineEvent *event) {
//     char timestamp_str[50];
//     struct tm *local_time = localtime(&event->timestamp);
//     strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", local_time);

//     printf("[%s] ", timestamp_str);
//     switch (event->event_type) {
//         case EVENT_BORROW:
//             printf("User ID %d borrowed Book ID %d.\n", event->user_id, event->book_id);
//             break;
//         case EVENT_RETURN:
//             printf("User ID %d returned Book ID %d.\n", event->user_id, event->book_id);
//             break;
//         case EVENT_BOOK_DELETE:
//             printf("Book ID %d was soft-deleted.\n", event->book_id);
//             break;
//         case EVENT_USER_DELETE:
//             printf("User ID %d was soft-deleted.\n", event->user_id);
//             break;
//         case EVENT_BOOK_EDIT_TITLE:
//             printf("Title of Book ID %d was edited.\n", event->book_id);
//             break;
//         case EVENT_BOOK_EDIT_AUTHOR:
//             printf("Author of Book ID %d was edited.\n", event->book_id);
//             break;
//         case EVENT_USER_EDIT_NAME:
//             printf("Name of User ID %d was edited.\n", event->user_id);
//             break;
//         case EVENT_BOOK_CREATE:
//             printf("Book ID %d was created.\n", event->book_id);
//             break;
//         case EVENT_USER_CREATE:
//             printf("User ID %d was created.\n", event->user_id);
//             break;
//         case EVENT_BOOK_RESTORE:
//             printf("Book ID %d was restored.\n", event->book_id);
//             break;
//         case EVENT_USER_RESTORE:
//             printf("User ID %d was restored.\n", event->user_id);
//             break;
//         default:
//             printf("Unknown event.\n");
//             break;
//     }
// }
// // SUPPORT FOR test11.c
// void timeline_print_events_by_type(int event_type) {
//     printf("\n=================================== TIMELINE BY EVENT TYPE ====================================\n");
//     if (timeline_count == 0) {
//         printf("No events to display.\n");
//         return;
//     }
    
//     int found_count = 0;
//     for (int i = 0; i < timeline_count; i++) {
//         if (timeline_events[i].event_type == event_type) {
//             print_single_event(&timeline_events[i]);
//             found_count++;
//         }
//     }
//     if (found_count == 0) {
//         printf("No events of type %d found.\n", event_type);
//     }
// }

// // SUPPORT FOR test11.c
// void timeline_print_events_by_book(int book_id) {
//     printf("\n=================================== TIMELINE FOR BOOK ID %d ====================================\n", book_id);
//     if (timeline_count == 0) {
//         printf("No events to display.\n");
//         return;
//     }
    
//     int found_count = 0;
//     for (int i = 0; i < timeline_count; i++) {
//         if (timeline_events[i].book_id == book_id) {
//             print_single_event(&timeline_events[i]);
//             found_count++;
//         }
//     }
//     if (found_count == 0) {
//         printf("No events found for Book ID %d.\n", book_id);
//     }
// }

// // SUPPORT FOR test11.c
// void timeline_print_events_by_user(int user_id) {
//     printf("\n=================================== TIMELINE FOR USER ID %d ====================================\n", user_id);
//     if (timeline_count == 0) {
//         printf("No events to display.\n");
//         return;
//     }
    
//     int found_count = 0;
//     for (int i = 0; i < timeline_count; i++) {
//         if (timeline_events[i].user_id == user_id) {
//             print_single_event(&timeline_events[i]);
//             found_count++;
//         }
//     }
//     if (found_count == 0) {
//         printf("No events found for User ID %d.\n", user_id);
//     }
// }

// // SUPPORT FOR test11.c
// // Sửa lại hàm này để gọi hàm phụ trợ
// void timeline_print_all_events() {
//     printf("\n=================================== FULL TIMELINE ====================================\n");
//     if (timeline_count == 0) {
//         printf("No events to display.\n");
//         return;
//     }
    
//     for (int i = 0; i < timeline_count; i++) {
//         print_single_event(&timeline_events[i]);
//     }
// }


// // //test10.c
// // void timeline_print_all_events() {
// //     printf("\n=================================== TIMELINE ====================================\n");
// //     if (timeline_count == 0) {
// //         printf("No events to display.\n");
// //         return;
// //     }
    
// //     char timestamp_str[50];
// //     for (int i = 0; i < timeline_count; i++) {
// //         struct tm *local_time = localtime(&timeline_events[i].timestamp);
// //         strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", local_time);

// //         printf("[%s] ", timestamp_str);
// //         switch (timeline_events[i].event_type) {
// //             case EVENT_BORROW:
// //                 printf("User ID %d borrowed Book ID %d.\n", timeline_events[i].user_id, timeline_events[i].book_id);
// //                 break;
// //             case EVENT_RETURN:
// //                 printf("User ID %d returned Book ID %d.\n", timeline_events[i].user_id, timeline_events[i].book_id);
// //                 break;
// //             case EVENT_BOOK_DELETE:
// //                 printf("Book ID %d was soft-deleted.\n", timeline_events[i].book_id);
// //                 break;
// //             case EVENT_USER_DELETE:
// //                 printf("User ID %d was soft-deleted.\n", timeline_events[i].user_id);
// //                 break;
// //             case EVENT_BOOK_EDIT_TITLE:
// //                 printf("Title of Book ID %d was edited.\n", timeline_events[i].book_id);
// //                 break;
// //             case EVENT_BOOK_EDIT_AUTHOR:
// //                 printf("Author of Book ID %d was edited.\n", timeline_events[i].book_id);
// //                 break;
// //             case EVENT_USER_EDIT_NAME:
// //                 printf("Name of User ID %d was edited.\n", timeline_events[i].user_id);
// //                 break;
// //             default:
// //                 printf("Unknown event.\n");
// //                 break;
// //         }
// //     }
// // }