#ifndef _UX_LIST_H_
#define _UX_LIST_H_

#include <stdlib.h>
#include <assert.h>

#define list_size(l)            ((l)->nnodes)
#define list_empty(l)           ((l)->head->next == NULL)
#define list_head(l)            ((l)->nnodes == 0? NULL : (l)->head->data)
#define list_tail(l)            ((l)->nnodes == 0? NULL : (l)->tail->data)
#define list_data(node)         ((node)->data)
#define list_iter_start(l)      (l)->head
#define list_iter_end(l)        NULL
#define list_iter_next(it)      ((it)->next)


typedef struct _list_node{
    void *data;
    struct _list_node* next;
}list_node_t;

typedef struct {
    list_node_t* head;
    list_node_t* tail;
    u_int nnodes;
    size_t size;
}list_t;

typedef list_node_t* list_iter_t;

list_t* list_create(size_t size)
{
    list_t* t = (list_t*) malloc(sizeof(list_t));
    assert(t != NULL);
    t->head = NULL;
    t->tail = NULL;
    t->nnodes = 0;
    t->size = size;
    return t;
}

void list_free(list_t* l)
{
    list_node_t* cur;
    while(l->head != NULL){
        cur = l->head;
        l->head = l->head->next;
        free(cur);
    }

    l->nnodes = 0;
    l->head = l->tail = NULL;
}

void list_destroy(list_t* l)
{
    list_free(l);
    free(l);
}
void* list_insert_head(list_t* l)
{
    list_node_t* cur;
    cur = (list_node_t*) malloc(sizeof(list_node_t));
    assert(cur != NULL);

    cur->data = malloc(sizeof(l->size));
    assert(cur->data != NULL);
    cur->next = NULL;

    if (l->nnodes == 0){
        l->tail = l->head = cur;
    }else{
        cur->next = l->head;
        l->head = cur;
    }
    l->nnodes++;
    return cur->data;
}

void* list_insert_tail(list_t* l)
{
    list_node_t* cur;
    cur = (list_node_t*) malloc(sizeof(list_node_t));
    assert(cur != NULL);

    cur->data = malloc(sizeof(l->size));
    assert(cur->data != NULL);
    cur->next = NULL;

    if (l->nnodes == 0){
        l->tail = l->head = cur;
    }else{
        l->tail->next = cur;
        l->tail = cur;
    }

    l->nnodes++;
    return cur->data;
}

void list_delete_head(list_t* l)
{
    list_node_t* t = l->head;
    if (l->nnodes == 0) return;
    if (l->nnodes == 1){
        l->nnodes--;
        free(t);
        l->head = l->tail = NULL;
        return;
    }
    l->head = l->head->next;
    l->nnodes--;
    free(t);
}

void list_reverse(list_t* l)
{
    list_node_t dummy;
    dummy.next = NULL;
    list_node_t* cur = l->head;
    list_node_t* t;

    l->head = l->tail;
    l->tail = cur;

    while(cur != NULL){
        t = cur;
        cur = cur->next;
        t->next = dummy.next;
        dummy.next = t;
    }

}

#endif //UNIX_LIST_H
