#include "common.h"

static inline void __list_add(list_head *new, list_head *prev, list_head *next)   //(新插入的节点，上一个节点，下一个节点)
{
    next->prev = new;                              //
    new->next = next;                              // A-B-C   //B为prev,C为next,则在B，C之间插入new
    new->prev = prev;			       // 相应的C的上一个为new;new的下一个为C
    prev->next = new;			       // new的上一个为prev;prev的下一个为new
}

void list_add(list_head *new, list_head *head)
{
    __list_add(new, head, head->next);   //在这，head相当于__list_add的上一个，head->next相当于__list_add中的下一个
}