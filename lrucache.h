#ifndef _LRUCACHE_H_
#define _LRUCACHE_H_

#include "hash.h"

typedef int LRUCACHE_CMP(const void* , const void*);
typedef int LRUCACHE_FREE(void*);

typedef struct {
    void* key;
    lrucache_node_t* prev;
    lrucache_node_t* next;
}lrucache_node_t;

typedef struct {
    int capacity;
    int cnt;
    lrucache_node_t* head;
    lrucache_node_t* tail; 
    hash_table* ht;

    LRUCACHE_CMP* lrucache_cmp;
    LRUCACHE_FREE* lrucache_free;
}lrucache_t;


lrucache_t* lrucache_create(LRUCACHE_CMP * cmp_f, LRUCACHE_FREE* node_free_f, int capacity);
void lrucache_destroy(lrucache_t* cache);
void lrucache_insert(lrucache_t* cache, int key, int val);
void lrucache_replace(lrucache_t* cache, int key, int val);
int lrucache_lookup(lrucache_t* cache, int key);




#endif
