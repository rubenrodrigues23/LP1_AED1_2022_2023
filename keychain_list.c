
#include "keychain_list.h"


/**
 * Create keychain
 * @return
 */
KEY_CHAIN * keychain_create(){
    KEY_CHAIN * key_chain = malloc(sizeof(KEY_CHAIN));
    key_chain->head=NULL;
    key_chain->size=0;
    return key_chain;
}

/**
 * Add keychain
 * @param keychain
 * @param key_holder
 */
void keychain_add(KEY_CHAIN * keychain, KEY_HOLDER * key_holder){
    time_t now = time(0);
    struct tm stm = *localtime(&now);

    KEY_CHAIN_NODE * node = malloc(sizeof(KEY_CHAIN_NODE));
    node->date_create = stm; //guardar a data criada
    node->date_update = stm;
    node->key_holder = key_holder; //guardamos a key
    node->next=NULL;

    if (keychain->head==NULL) {
        keychain->head = node;
    }else {
        KEY_CHAIN_NODE *n = keychain->head; //enquanto o proximo for diferente de null avançamos para o proximo
        while (n->next != NULL)
            n = n->next;

        n->next = node;
    }
    keychain->size++; //tamanho fica com 1

}

/**
 * Get Keychain
 * @param keychain
 * @param position
 * @return
 */
KEY_HOLDER * keychain_get(KEY_CHAIN * keychain, int position){
    if (position>=keychain->size) //se for maior ou igual a size e null

        return NULL;

    KEY_CHAIN_NODE * n = keychain->head;
    for(int i=0;i<position;i++)
        n=n->next;
    
    return n->key_holder;
    
}

/**
 * Remove keychain
 * @param keychain
 * @param position
 * @return kh
 */
KEY_HOLDER * keychain_remove(KEY_CHAIN * keychain, int position){
    if (position>=keychain->size)  //se for maior ou igual a size e null
        return NULL;

    KEY_CHAIN_NODE * n = keychain->head;
    KEY_CHAIN_NODE * prev = NULL;
    for(int i=0;i<position;i++){ //
        prev=n;
        n=n->next;    //avançamos n posicoa e o previous é o anterior
    }

    if (prev==NULL){  //inserimos na posicoes zero
        //removing the head
        keychain->head = n->next; //removemos a head e passa a ser a proxima
    }else{
        //prev will point to next of the one to be removed
        prev->next = n->next; //a anterior aponta para a proxima
    }

    KEY_HOLDER *kh = n->key_holder;
    free(n);
    
    return kh;
    
}

/**
 * Size of keychain
 * @param keychain
 * @return
 */
int keychain_size(KEY_CHAIN * keychain){
    return keychain->size; //devolve o size
}

