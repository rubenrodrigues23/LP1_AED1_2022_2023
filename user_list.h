
#ifndef LP1AED1_PROJETO_USER_LIST_H
#define LP1AED1_PROJETO_USER_LIST_H


#include "user.h"

typedef struct user_list {
    struct user_list_node * head;
    struct user_list_node * tail;
    int size;
} USER_LIST;


typedef struct user_list_node { //lista de utilizadores e cada user tem uma keychain
    USER * user;
    struct user_list_node * next;
} USER_LIST_NODE;


USER_LIST * user_list_create();

void user_list_add_sorted(USER_LIST * user_list, USER * user);

void user_list_add_head(USER_LIST * user_list, USER * user);

void user_list_add_tail(USER_LIST * user_list, USER * user);

USER * user_list_get(USER_LIST * user_list, char * name);

USER * user_list_remove(USER_LIST * user_list, char * name);

int user_list_size(USER_LIST * user_list);

void user_list_sort(USER_LIST * user_list);

int main_user_list(int argc, const char *argv[]);

#endif //LP1AED1_PROJETO_USER_LIST_H
