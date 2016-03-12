#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/*choose one prime number*/
#define HASH_BUCKET 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct phonebooK_detail {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail *pDetail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct _hash_bucket {
    entry *pNext;
} hash_bucket;

typedef struct _hash_table {
    hash_bucket  *bucket[HASH_BUCKET];
} hash_table;

typedef unsigned int hashIndex;

entry *findName(char lastname[], hash_table *h);
hash_table *append(char lastName[], hash_table *h);
hashIndex hash_function( char lastname[]);
hash_table *new_hash();

#endif
