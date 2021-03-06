#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
/*first use orig version*/
entry *findName(char lastName[], hash_table *ht)
{
    hashIndex hash_value = hash_function( lastName);
    entry *ep = ht->bucket[hash_value]->pNext;
    while( ep != NULL) {
        if (strcasecmp(lastName, ep->lastName) == 0)
            return ep;
        ep = ep->pNext;
    }
    return NULL;
}

hash_table *append(char lastName[], hash_table *e)
{
    hashIndex hash_value = hash_function(lastName);
    entry *ep = e->bucket[hash_value]->pNext;
    if(!ep) {
        e->bucket[hash_value]->pNext = (entry *) malloc (sizeof(entry));
        ep = e->bucket[hash_value]->pNext;
        e->bucket[hash_value]->pLast = ep;
    }
    else {
        ep = e->bucket[hash_value]->pLast;
        ep->pNext = (entry *) malloc (sizeof(entry));
        ep = ep->pNext;
        e->bucket[hash_value]->pLast = ep;
    }
    strcpy(ep->lastName, lastName);
    ep->pNext = NULL;
    return e;
}

hash_table *new_hash()
{
    hash_table *ht = (hash_table *) malloc( sizeof(hash_table));
    int i;
    for( i = 0; i < HASH_BUCKET; i++) {
        ht->bucket[i] = (hash_bucket *) malloc( sizeof (hash_bucket));
        ht->bucket[i] ->pNext = NULL;
        ht->bucket[i] ->pLast = NULL;
    }
    return ht;
}

hashIndex hash_function( char lastName[])
{
    unsigned int hash_value = 0;
    while( *lastName != '\0')
        hash_value += (int) *lastName++;
    return hash_value % HASH_BUCKET;
}
