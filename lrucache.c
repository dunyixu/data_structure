#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lrucache.h"

static int hash_primes[] = {
    103,
    229,
    467,
    977,
    1979,
    4019,
    6037,
    7951,
    12149,
    16231,
    33493,
    65357,
    0
};

lrucache_t* lrucache_create(LRUCACHE_CMP* cmp_f, LRUCACHE_FREE* node_free_f, int capacity)
{
    lrucache_t* t;
    int i = 0;

    t = (lrucache_t*) malloc(sizeof(lrucache_t));
    assert(t != NULL);
    t->capacity = capacity;
    t->cnt = 0;
    t-> head = NULL;
    t-> tail = NULL;
    
    while(hash_primes[i]){
        if(hash_primes[i] >= capacity) break;
        i++;
    }
    t->ht = hash_create((HASHCMP*)cmp_f, hash_primes[i], hash4);
    assert(t->ht != NULL);

    t->lrucache_cmp = cmp_f;
    t->lrucache_free = node_free_f;
}

void lrucache_destroy(lrucache_t* cache)
{

}


