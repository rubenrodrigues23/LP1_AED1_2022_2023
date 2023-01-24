
#ifndef LP1AED1_PROJETO_KEYCHAIN_LIST_H
#define LP1AED1_PROJETO_KEYCHAIN_LIST_H
#include "key_holder.h"
#include <stdlib.h>
#include <time.h>

typedef struct key_chain {
    struct key_chain_node * head;
    int size;
} KEY_CHAIN;


typedef struct key_chain_node {
    KEY_HOLDER * key_holder;
    struct tm date_create;
    struct tm date_update;
    struct key_chain_node * next;
} KEY_CHAIN_NODE;


KEY_CHAIN * keychain_create();

void keychain_add(KEY_CHAIN * keychain, KEY_HOLDER * key_holder);

KEY_HOLDER * keychain_get(KEY_CHAIN * keychain, int position);

KEY_HOLDER * keychain_remove(KEY_CHAIN * keychain, int position);

int keychain_size(KEY_CHAIN * keychain);






#endif //LP1AED1_PROJETO_KEYCHAIN_LIST_H
