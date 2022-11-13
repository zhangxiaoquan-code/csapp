#ifndef COMMON_H
#define COMMON_H

typedef struct list_head
{
    struct list_head *prev;
    struct list_head *next;
}list_head;

void list_add(list_head *new, list_head *head);

#endif // !COMMON_H