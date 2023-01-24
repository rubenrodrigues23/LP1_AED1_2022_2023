

#ifndef LP1AED1_PROJETO_USER_H
#define LP1AED1_PROJETO_USER_H

#include "keychain_list.h"

/*
 * Struct User
 */
typedef struct user {
    char name[50];
    char email[50];
    KEY_CHAIN * keychain;
}USER;

int main_user(int argc, const char *argv[]);

#endif //LP1AED1_PROJETO_USER_H
