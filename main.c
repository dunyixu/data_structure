#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct {
    hash_link hl;
    char*      val;
}hash_node_t;

hash_node_t* hash_newnode(const char* key, const char* val)
{
    hash_node_t* t;
    t = (hash_node_t*) malloc(sizeof(hash_node_t));
    
    t->hl.key = (char*) malloc(strlen(key) * sizeof(char));
    strcpy(t->hl.key, key);

    t->val = (char*) malloc(strlen(val) * sizeof(char));
    strcpy(t->val, val);

    return t;
}

void hash_free(void* node)
{
    hash_node_t* t = (hash_node_t*) node;
    free((char*)t->hl.key);
    free((char*)t->val);
    free((hash_node_t*) t);
}
int main()
{
    hash_table* ht;
    hash_node_t* dat;
    ht = hash_create((HASHCMP*)strcmp, 229, hash4);
    dat = hash_newnode("ux", "man");
    hash_join(ht, &dat->hl);
    
    dat = hash_newnode("pao", "woman");
    hash_join(ht, &dat->hl);

    dat = hash_newnode("xule", "man");
    hash_join(ht, &dat->hl);

    dat = hash_newnode("huawei", "man");
    hash_join(ht, &dat->hl);

    hash_first(ht);
    dat = (hash_node_t*) hash_next(ht);
    while(dat){
        printf("name:%s\tsex:%s\n", (char*)dat->hl.key, (char*)dat->val);
        dat = (hash_node_t*) hash_next(ht);
    }
    dat = (hash_node_t*)hash_lookup(ht,"pao");
    printf("lookup:name:%s\tsex:%s\n", (char*)dat->hl.key, (char*)dat->val);
    hashFreeItems(ht, (HASHFREE*) hash_free);
    hashFreeMemory(ht);

    return 0;

}
