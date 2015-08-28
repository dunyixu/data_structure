#ifndef _UX_STACK_H_
#define _UX_STACK_H_

#include <assert.h>
#include <stdlib.h>

#define stack_top(s) ((s)->base + (s)->size * ((s)->top - 1))
#define stack_empty(s) ((s)->top == 0)

typedef struct {
    void *base;
    u_int top;
    u_int nalloc;
    size_t size;
}stack_t;

stack_t* stack_create(int n, int size){
    stack_t* s;
    s = (stack_t*) malloc(sizeof(stack_t));
    if (s == NULL) return NULL;
    s->base = (void*)malloc(n * size);
    if (s->base == NULL){
        free(s);
        return NULL;
    }
    s->size = size;
    s->nalloc = n;
    s->top = 0;
    return s;
}

void stack_destroy(stack_t* s)
{
    free(s->base);
    free(s);
}

void* stack_push(stack_t* s)
{
    if(s->top >= s->nalloc){
        s->base = (void*) realloc(s->base, s->nalloc * s->size * 2);
        assert(s->base != NULL);
        s->nalloc *= 2;
    }
    return s->base + s->size * s->top++;
}

void stack_pop(stack_t* s)
{
    assert(s->top != 0);
    s->top--;
}

#endif