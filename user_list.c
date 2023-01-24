#include <string.h>
#include <stdio.h>
#include "user_list.h"
#include "user.h"


int main_user_list(int argc, const char *argv[]) {

    return 0;

}

/**
 * Create user list
 * @return  list
 */
USER_LIST * user_list_create(){
    USER_LIST * list = malloc(sizeof(USER_LIST));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void user_list_add_sorted(USER_LIST * user_list, USER * user){

}

/**
 * Add user to head
 * @param user_list
 * @param user
 */
void user_list_add_head(USER_LIST * user_list, USER * user){
    USER_LIST_NODE * node = malloc(sizeof(USER_LIST_NODE));

    node->user = user;
    node->next = user_list->head;

    user_list->head = node;
    if (user_list->tail==NULL) {   //a tail passa a ser a head se for null
        user_list->tail = user_list->head;
    }
    user_list->size++;
}

/**
 * Add user to tail
 * @param user_list
 * @param user
 */
void user_list_add_tail(USER_LIST * user_list, USER * user){
    USER_LIST_NODE * node = malloc(sizeof(USER_LIST_NODE));

    node->user = user;
    node->next = NULL;

    if (user_list->head==NULL){  //lista esta vazia
        user_list->head = node;  //
    }else{
        user_list->tail->next = node; //a proxima passa a ser o node, a tail é sempre o node
    }
    user_list->tail = node;
    user_list->size++;
}

/**
 * Get user from list
 * @param user_list
 * @param name
 */
USER * user_list_get(USER_LIST * user_list, char * name){
    USER_LIST_NODE * t=user_list->head;
    while (t!=NULL){
        if (strcmp(name,t->user->name)==0) //se encontrar devolve a struct do user
        {
            printf("Nome:%s\tEmail:%s\t\n", t->user->name, t->user->email);
            return t->user;
        }
        t=t->next;
    }
    return NULL;
}

/**
 * Remove user
 * @param user_list
 * @param name
 * @return
 */
USER * user_list_remove(USER_LIST * user_list, char * name){
    USER_LIST_NODE * t=user_list->head;
    USER_LIST_NODE * ant = NULL;
    while (t!=NULL){
        if (strcmp(name,t->user->name)==0) {
            USER * user = t->user; //vamos buscar o userr para depois devolver para o return
            if (ant==NULL){
                //removing the head
                user_list->head = t->next;  //a cabeça passa a ser a antiga cabeça ao remove-la
                if (user_list->head==NULL) { //so tinha uma coisa na lista ficando vazia
                    user_list->tail = NULL;
                }
            }else if (user_list->tail == t) {
                user_list->tail=ant; //se estamos na ultima posicao passa para a anterior
            }

            ant->next = t->next;
            user_list->size--;
            return user;
        }
        ant=t;
        t=t->next;
    }
    return NULL;
}

/**
 * Size of list user
 * @param user_list
 */
int user_list_size(USER_LIST * user_list){
    return user_list->size;
}

void user_list_sort(USER_LIST * user_list){

}