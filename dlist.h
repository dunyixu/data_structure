#ifndef _UX_DLIST_H_
#define _UX_DLIST_H_

#include <stdlib.h>
#include <assert.h>






typedef struct _dlist_node{
    void* data;
    struct _dlist_node* prev;
    struct _dlist_node* next;
}dlist_node_t;

typedef struct {
    dlist_node_t* head;
    dlist_node_t* tail;
    u_int         nnodes;
    size_t        size;
}dlist_t;

typedef dlist_node_t* dlist_iter_t;

dlist_t* dlist_create(size_t size);
void     dlist_free();


#endif
