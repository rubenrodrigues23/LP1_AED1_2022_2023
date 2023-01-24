

#include "func_ints.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bipolar.h"
#include "key_holder.h"
#include "keychain_list.h"
#include "user.h"
#include "user_list.h"

#define BUFFER 1024
#define NCOLS 10




int main_func_ints(int argc, const char *argv[]){

    /* Seed the random number generator with the current time */
    srand(time(0));

    //Requisito 2: Dada uma chave pública, calcular a chave privada com base em dois algoritmos
    //diferentes à escolha, i.e., dada uma chave pública n:
    //a. Gerar múltiplos de n até encontrar um nº bipolar (pode ser pouco eficiente);
    /*calc_private_key_int_2(8);
    calc_private_key_int_2(18);
    calc_private_key_int_2(251);
    calc_private_key_int_2(2013);*/
    //Gerar números bipolares sucessivos e verificar se são ou não múltiplos de n.
    /*calc_private_key_int(8);
    calc_private_key_int(18);
    calc_private_key_int(251);
    calc_private_key_int(2013);*/

    //3. Dada uma chave privada, calcular a respectiva chave codificada utilizando uma
    //representação run-length. A representação codificada (run-length) das chaves deve
    //ser mantida/gerida numa matriz de inteiros e strings (tal como para as chaves
    //públicas e privadas);

    //4. Inserir e remover uma ou mais chaves públicas e respectivas chaves privadas e
    //codificadas (run-length) nas estruturas de dados. Inicialmente a inicialização deverá
    //ser efectuada por geração aleatória das chaves públicas e cálculo das respectivas
    //chaves privadas e codificadas. Mais tarde deve ser considerada também a
    //leitura/escrita de chaves através de ficheiros;
    short **matrix_pubkey = alloc_matrix_int(10, NCOLS);
    //print_matrix(matrix_pubkey);
    //printf("\n");

    store_key_int(matrix_pubkey, 10, 1819);
    store_key_int(matrix_pubkey, 10, 2630);
    store_key_int(matrix_pubkey, 10, 18);
    store_key_int(matrix_pubkey, 10, 26);
    store_key_int(matrix_pubkey, 10, 181);
    store_key_int(matrix_pubkey, 10, 263);
    store_key_int(matrix_pubkey, 10, 45);
    store_key_int(matrix_pubkey, 10, 12);
    store_key_int(matrix_pubkey, 10, 23);
    store_key_int(matrix_pubkey, 10, 24);


    printf("Matriz Chaves Publicas\n");
    print_matrix(matrix_pubkey);

    //printf("build private Key matrix\n");
    short **matrix_prvkey = alloc_matrix_int(10, NCOLS);
    for(int i=0;i<10;i++){
        short * pub = matrix_pubkey[i];
        unsigned long long publ = key_digits_2_long_int(pub);
        unsigned long long prvl = calc_private_key_int(publ);
        store_key_int(matrix_prvkey, 10, prvl);
    }

    printf("Matriz Chaves Privadas\n");
    print_matrix(matrix_prvkey);

    //printf("build codified Key matrix\n");

    short **matrix_codkey = alloc_matrix_int(10, NCOLS);
    for(int i=0;i<10;i++){
        short * prv = matrix_prvkey[i];
        unsigned long long prvl = key_digits_2_long_int(prv);
        unsigned long long codl = calc_runlength_int(prvl);
        store_key_int(matrix_codkey, 10, codl);
    }

    printf("Matriz de Chaves Codificadas\n");
    print_matrix(matrix_codkey);
    printf("--------------------\n");
    printf("\n");

    /*sort_all_matrices_int(matrix_pubkey, matrix_prvkey, matrix_codkey, 10, 0);
    print_matrix(matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_prvkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_codkey);*/
    //5. Efectuar pesquisas de chaves, retornando as chaves privadas e codificadas para
    //uma dada chave pública ou partes dessa chave, ou seja, cada pesquisa poderá
    //utilizar subsequências/partes da chave pública na expressão de pesquisa;

    //6. Ordenar a lista de chaves públicas e respectivas chaves privadas e codificadas, por
    //ordem crescente ou decrescente das chaves;

    //7. Listar as chaves públicas e respectivas chaves privadas e codificadas, na ordem em
    //que se encontram inseridas ou noutra ordem indicada (e.g. crescente ou
    //decrescente dos tamanho das chaves, i.e. número de dígitos);
    /*printf("Todas as chaves privadas com chave publica que contem o 26\n");
    short** res = search_private_keys_int(matrix_pubkey, matrix_prvkey, 10, 26);
    print_matrix(res);

    printf("Resultados ordenados em ordem descendente\n");
    sort_matrix_int(res, 10, 0);
    print_matrix(res);

    printf("Todas as chaves privadas com chave publica que contem o 63\n");
    res = search_private_keys_int(matrix_pubkey, matrix_prvkey, 10, 63);
    print_matrix(res);

    printf("Resultados ordenados em ordem crescente\n");
    sort_matrix_int(res, 10, 1);
    print_matrix(res);*/

    /*printf("Todas as matrizes na ordem atual\n");
    list_keys_int(matrix_pubkey,matrix_prvkey,matrix_codkey, 10, 0);

    printf("Todas as matrizes em ordem crescente\n");
    list_keys_int(matrix_pubkey,matrix_prvkey,matrix_codkey, 10, 1);

    printf("Todas as matrizes em ordem decrescente\n");
    list_keys_int(matrix_pubkey,matrix_prvkey,matrix_codkey, 10, 2);*/

    /*printf("Chave Publica em ordem crescente\n");
    sort_matrix_int(matrix_pubkey, 10, 1);
    print_matrix(matrix_pubkey);

    printf("Chave Publica em ordem decrescente\n");
    sort_matrix_int(matrix_pubkey, 10, 0);
    print_matrix(matrix_pubkey);*/


    //8. Agregar numa estrutura de dados designada por KEY_HOLDER (porta-chaves) um
    //conjunto de matrizes de chaves públicas, privadas e codificadas, tal como foram
    //descritas anteriormente (3 matrizes para a versão com dígitos inteiros e 3 matrizes
    //para a versão com strings). Considerar ainda a representação de uma lista ligada de
    //vários porta-chaves, i.e., uma lista ligada em que cada nó contém os dados de 6
    //matrizes de chaves públicas, privadas e codificadas (versão inteiros e strings). Cada
    //porta-chaves deverá ter uma ordem cronológica na sequência de nós da lista.
    //Portanto, cada nó da lista deve ter duas datas: i) data da geração/criação do
    //porta-chaves; ii) data da última actualização/modificação de chaves. Os nós da lista
    //devem ser ordenados cronologicamente pelas datas de modificação dos
    //porta-chaves. Devem ainda ser criadas várias funções para gerir a lista ligada de
    //porta-chaves:
    //a. Criar e inserir um porta chaves numa dada posição da sequência;
    //b. Eliminar um porta-chaves que está numa dada posição;
    //c. Pesquisar chaves apenas em determinados porta-chaves da lista, definidos
    //numa expressão de pesquisa;
   /* KEY_HOLDER * holder1 = malloc(sizeof (KEY_HOLDER));
    holder1->matrix_kpub = matrix_pubkey;
    holder1->matrix_kpriv = NULL;
    
    KEY_HOLDER * holder2 = malloc(sizeof (KEY_HOLDER));
    holder2->matrix_kpub = NULL;
    holder2->matrix_kpriv = matrix_prvkey;

    KEY_CHAIN * kc1 = keychain_create();
    printf("Keychain size: %d\n", keychain_size(kc1));
    keychain_add(kc1, holder1);
    printf("Keychain size: %d\n", keychain_size(kc1));
    keychain_add(kc1, holder2);
    printf("Keychain size: %d\n", keychain_size(kc1));

    KEY_CHAIN * kc2 = keychain_create();
    printf("Keychain size: %d\n", keychain_size(kc2));
    keychain_add(kc2, holder1);
    printf("Keychain size: %d\n", keychain_size(kc2));
    keychain_add(kc2, holder2);
    printf("Keychain size: %d\n", keychain_size(kc2));

    printf("Keyholder 2 Matrix Privada\n");
    KEY_HOLDER *kh = keychain_get(kc1, 1);
    print_matrix(kh->matrix_kpriv);
/*
    printf("\n");
    keychain_remove(kc1, 0);
    kh = keychain_get(kc1, 0);
    print_matrix(kh->matrix_kpriv);
*/


    /*USER_LIST_NODE * node = malloc(sizeof(USER_LIST_NODE));
    USER_LIST * userlist1 = user_list_create();
    USER u1 = {"ruben", "ruben@gmail.com", kc1};
    USER u2 = {"joao", "joao@gmail.com", kc1};
    user_list_add_head(userlist1, &u1);
    user_list_add_head(userlist1, &u2);

    USER u3 = {"carlos", "carlos@gmail.com", kc1};
    USER u4 = {"alberto", "alberto@gmail.com", kc1};
    user_list_add_tail(userlist1, &u3);
    user_list_add_tail(userlist1, &u4);


    printf("Lista de Users:\n");
    USER_LIST_NODE * atual = userlist1->head;
    for (int i = 0; i < userlist1->size; i++) {
        printf("Nome:%s\tEmail:%s\t\n", atual->user->name, atual->user->email);
        atual= atual->next;
    }
     */

    /*printf("\n");
    user_list_get(userlist1, "ruben");
    user_list_get(userlist1, "alberto");
    */
/*
    printf("\n");
    user_list_remove(userlist1, "ruben");
    USER_LIST_NODE * atual1 = userlist1->head;
    for (int i = 0; i < userlist1->size; i++) {
        printf("Nome:%s\tEmail:%s\t\n", atual1->user->name, atual1->user->email);
        atual1= atual1->next;
    }*/

    //char filename[] = "matrix.txt";
    //save_txt_keys_int(matrix_pubkey, matrix_prvkey, matrix_codkey, 10, filename);

    /*load_txt_keys_int(matrix_pubkey, matrix_prvkey, matrix_codkey, 10, filename);
    print_matrix(matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_prvkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_codkey);*/

    //char filename[] = "binarymatrix.bin";
    //save_bin_keys_int(matrix_pubkey, matrix_prvkey, matrix_codkey, 10, filename);

    //load_bin_keys_int(matrix_pubkey, matrix_prvkey, matrix_codkey, 10, filename);
    /*print_matrix(matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_prvkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix(matrix_codkey);*/

    /*bulk_populate_public_keys_int(matrix_pubkey, 10);
    print_matrix(matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    bulk_compute_private_keys_int(matrix_pubkey, matrix_prvkey, 10);
    print_matrix(matrix_prvkey);
    printf("--------------------\n");
    printf("\n");
    bulk_compute_runlengths_int(matrix_prvkey, matrix_codkey, 10);
    print_matrix(matrix_codkey);
    printf("--------------------\n");
    printf("\n");*/


    short** res = search_private_keys_int(matrix_pubkey, matrix_prvkey, 10, 26);
    print_matrix(res);

    return 0;
}

/**
 * Generate a random integer to be used as the public key.
 * @return random number representing a public key
 */
unsigned long long new_public_key_int(void){
    int public_key;
    /* Generate a random integer between 0 and RAND_MAX */
    public_key = rand() % 999+1;
    printf("Public key: %d\n", public_key);
    return public_key;
}


/**
 * Create an array of digits for a given key.
 * @param key - long key
 * @return address of array of digits for a given key
 */
short* key_long_2_digits_int(unsigned long long key){
    short * digits = malloc(NCOLS * sizeof(short)); // Declare an array of integers
    int temp = key;  // Assign the key to a temporary variable

    for(int i=0;i<NCOLS;i++)
        digits[i]=-1; //0; /// -1 condição de paragem

    // Extract each digit from the key and store it in the array
    int i;
    for (i = 0; temp > 0; i++) {
        digits[i] = temp % 10;  // Extract the last digit of the number
        temp /= 10;  // Divide the number by 10 to remove the last digit
    }
    //i gets number of digits

    // Reverse the array so that the digits are in the correct order
    int start = 0;
    int end = i-1;
    while (start < end) {
        int temp = digits[start];
        digits[start] = digits[end];
        digits[end] = temp;
        start++;
        end--;
    }

    /*// Print the array of digits
    for (int i = 0; i < 5; i++) {
        printf("%d ", digits[i]);
    }*/

    return digits;

}

/**
 * Receives an array of digits and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_int(short* keydigits) {
    long key = 0;
    int i=0;
    while (keydigits[i]>=0 && i < NCOLS) {
        key = key * 10 + keydigits[i];
        i++;
    }
    return key;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_int(unsigned long long pubkey){
    //printf("Pubkey: %u!\n", pubkey);
    unsigned long long i = pubkey*2;
    while(bipolar_number_ints(i) != 0) {
        i += pubkey;
    }

    return i;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_int_2(unsigned long long pubkey){
    //printf("pubkey: %d!\n", pubkey);
    unsigned long long i=1;
    while( i <= pubkey || i % pubkey != 0 || bipolar_number_ints(i) != 0)
        i++;

    return i;

}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_int(unsigned long long privkey){
    char text[20];
    itoa(privkey, text, 10);
    size_t l = strlen(text);
    char result[20];
    char cnt = '1';
    int j = 0;
    int i = 0;
    while(i < l){
        while(i < l-1 && text[i]==text[i+1]){
            cnt++;
            i++;
        }
        result[j++] = cnt;
        result[j++] = text[i];
        cnt = '1';
        i++;
    }
    result[j]='\0';
    return atoi(result);
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_int(unsigned long long runlengthkey){
    int current = 0, previous = 0;
    int conv = (int) runlengthkey;
    int array[4];
    for (int i = 0; i < 4; i++) {
        array[i] = conv % 10;
        conv /= 10;
    }
    int temp;
    for(int i = 0; i < 4/2; i++){
        temp = array[i];
        array[i] = array[4-i-1];
        array[4-i-1] = temp;
    }
    for (int i = 0; i < 1 ; i++) {
        current = array[1];
        previous = array[0];
        for (int j = 0; j < previous; j++) {
            printf("%d ", current);
        }
        current = array[3];
        previous = array[2];
        for (int j = 0; j < previous; j++) {
            printf("%d ", current);
        }
        printf("\n");
    }
}

/**
 * Memory allocation for a int matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
short** alloc_matrix_int(int nlines, int ncolumns){
    short **matrix;
    matrix = malloc(nlines * sizeof(int *));
    for (int i = 0; i < nlines; i++)
    {
        matrix[i] = malloc(ncolumns * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i < nlines; i++)
    {
        for (int j = 0; j < ncolumns; j++)
        {
            matrix[i][j] = -1;
        }
    }

    //print_matrix(matrix);

    // Free the memory
    /*for (int i = 0; i < nlines; i++)
    {
        free(matrix[i]);
    }
    free(matrix);*/
    return matrix;
}

/**
 * Print matrix
 * @param matrix
 */
void print_matrix(short **matrix){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            if (matrix[i][j]>=0)
                printf("%d ", matrix[i][j]);
            else
                printf(". ");
        }
        printf("\n");
    }
}

/**
 * Store a key (pub, priv or run-length) into the first available position of given matrix.
 * @param matrix - matrix to store the key
 * @param lines - matrix number of lines
 * @param key - key to be stored
 */
void store_key_int(short **matrix, int lines, unsigned long long key){
    for (int i = 0; i < lines; i++) {
        if (matrix[i][0] == -1/*0*/){
            short * digits = key_long_2_digits_int(key);

            //printf("size=%d\n", size);

            for (int k = 0; k < NCOLS ; k++) {
                matrix[i][k] = digits[k];
            }
            break;
        }
    }
}

/**
 * return 1 if search is found in pub
 * @param pub
 * @param search
 * @return
 */
int contains_partial_key(short * pub, short * search){ // (matrix_kpub, 26)
    char p[NCOLS+1]; // +1 por causa do \0
    char s[NCOLS+1]; // +1 por causa do \0
    int i = 0;
    while(i < NCOLS && pub[i]>=0) { //1819
        p[i] = '0' + pub[i];
        i++;
    }
    p[i]=0; //termina a string
    i=0;
    while(i < NCOLS && search[i]>=0){ //26
        s[i]='0' + search[i];
        i++;                    //converte cada um do array short para uma string de digitos
    }
    s[i]=0;

    if (strstr(p, s) != NULL)  //devolve um apontador para a primeira ocorrencia da string p
        return 1;  //1 contem
    else
        return 0;  //0 nao contem
}

/**
 * Return a list of all private keys matching a given partial public key.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param partialpubkey - part of public key to filter the private keys
 * @return array of private keys matching the partialpubkey
 */
short** search_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines, unsigned long long partialpubkey){

    short * search = key_long_2_digits_int(partialpubkey);

    //alloc matrix for NLINES
    short **result = alloc_matrix_int(lines, NCOLS); //aloca uma matriz de result para as linhas todos e percorre as chaves publicas

    //look for all pubkeys than contain all digits of partial pub key
    //
    for(int i = 0; i < lines && matrix_kpub[i][0] != -1; i++){ //stop searching if find a line starting with -1
        if (contains_partial_key(matrix_kpub[i], search)==1){
            store_key_int(result, lines, key_digits_2_long_int(matrix_kpriv[i]));  //devolve a matriz se percorrer todas.
        }
    }

    return result;
}

/**
 * Sort a matrix keys in ascending or descending order
 * @param matrix - matrix to be sorted
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_matrix_int(short **matrix, int lines, int order) {     //select
    int num;
    for (num = 0; num < 10 && matrix[num][0] >=0; num++);

    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            unsigned long long l1 = key_digits_2_long_int(matrix[i]);
            unsigned long long l2 = key_digits_2_long_int(matrix[j]);
            if (order == 1 && l1 > l2 || order != 1 && l1 < l2) {//swap
                short *tmp = matrix[i];  //vetor de vetores trocando a linha inteira de uma so vez
                matrix[i] = matrix[j];
                matrix[j] = tmp;
            }
        }
    }
}

/**
 * Sort all matrices keys in ascending or descending order
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_all_matrices_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order){
    //sort all matrices independently will get them unsynchronized
    //sorted on pub key only
    //determine how many used lines
    //troca as posicoes mas ficam sincronizadas
    int num;
    for (num = 0; num < lines && matrix_kpub[num][0] >=0; num++);

    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            unsigned long long l1 = key_digits_2_long_int(matrix_kpub[i]);
            unsigned long long l2 = key_digits_2_long_int(matrix_kpub[j]);
            if (order == 1 && l1 > l2 || order != 1 && l1 < l2) {//swap
                short *tmp = matrix_kpub[i];
                matrix_kpub[i] = matrix_kpub[j];
                matrix_kpub[j] = tmp;

                tmp = matrix_kpriv[i];
                matrix_kpriv[i] = matrix_kpriv[j];
                matrix_kpriv[j] = tmp;

                tmp = matrix_kcod[i];
                matrix_kcod[i] = matrix_kcod[j];
                matrix_kcod[j] = tmp;
            }
        }
    }

}

/**
 * counts the digits of the key
 * @param key
 * @return
 */
int count_digits(short * key){ //quantos digitos existem no short
    int num;
    for (num = 0; num < NCOLS && key[num] >=0; num++);
    return num;
}

/**
 * Print all keys on the console, sorted by pubkeys sizes (i.e. number of digits).
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 0 ? current order : order == 1 ? ascending : descending
 */
void list_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, int order){
    if (order!=0){ //se for zero imprime a ordem atual

        int num;
        for (num = 0; num < 10 && matrix_kpub[num][0] >= 0; num++);

        for (int i = 0; i < num - 1; i++) {
            for (int j = i + 1; j < num; j++) {
                int l1 = count_digits(matrix_kpub[i]);
                int l2 = count_digits(matrix_kpub[j]);
                if (order == 1 && l1 > l2 || order != 1 && l1 < l2) {//swap
                    short *tmp = matrix_kpub[i];
                    matrix_kpub[i] = matrix_kpub[j];
                    matrix_kpub[j] = tmp;

                    tmp = matrix_kpriv[i];
                    matrix_kpriv[i] = matrix_kpriv[j];
                    matrix_kpriv[j] = tmp;

                    tmp = matrix_kcod[i];
                    matrix_kcod[i] = matrix_kcod[j];
                    matrix_kcod[j] = tmp;
                }
            }
        }
    }
    print_matrix(matrix_kpub);
    printf("--------------------\n");
    print_matrix(matrix_kpriv);
    printf("--------------------\n");
    print_matrix(matrix_kcod);

}

/**
 * Save all matrix data to a text file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the text file where to store the data
 */
void save_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE *fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\matrix.txt", "w");
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro!\n");
        return;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fprintf(fp, "%d ", matrix_kpub[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fprintf(fp, "%d ", matrix_kpriv[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {

            fprintf(fp, "%d ", matrix_kcod[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Dados Guardados no ficheiro %s\n", filename);
}

/**
 * Loads data into the matrices from a text file.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the text file to load data from
 */
void load_txt_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE *fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\matrix.txt", "r");
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro!\n");
        return;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%hd ", &matrix_kpub[i][j]);
        }
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%hd ", &matrix_kpriv[i][j]);
        }
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%hd ", &matrix_kcod[i][j]);
        }
    }
    fclose(fp);
    printf("Dados Carregados do ficheiro %s\n", filename);
}

/**
 * Save all matrix data to a binary file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the binary file where to store the data
 */
void save_bin_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE* fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\binarymatrix.bin", "wb");
    int i;
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;
    }

    for (i = 0; i < lines; i++) {
        fwrite(matrix_kpub[i], sizeof(short), lines, fp);
        fwrite(matrix_kpriv[i], sizeof(short), lines, fp);
        fwrite(matrix_kcod[i], sizeof(short), lines, fp);
    }

    fclose(fp);
    printf("Dados Guardados no ficheiro binario %s\n", filename);
}


/**
 * Loads data into the matrices from a binary file.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename -name of the binary file to load data from
 */
void load_bin_keys_int(short **matrix_kpub, short **matrix_kpriv, short **matrix_kcod, int lines, char filename[]){
    FILE* fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\binarymatrix.bin", "rb");
    int i;
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;
    }
    for (i = 0; i < lines; i++) {
        fread(matrix_kpub[i], sizeof(short), lines, fp);
        fread(matrix_kpriv[i], sizeof(short), lines, fp);
        fread(matrix_kcod[i], sizeof(short), lines, fp);
    }
    fclose(fp);
    printf("Dados carregados do ficheiro binario %s\n", filename);
}

/**
 * Automatically generate and save a given amount (<lines>) of public keys.
 * @param matrix_kpub - public keys matrix
 * @param lines - matrix number of lines
 */
void bulk_populate_public_keys_int(short **matrix_kpub, int lines){
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kpub, lines, new_public_key_int());
    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_int(short **matrix_kpub, short **matrix_kpriv, int lines){
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kpriv, lines, calc_private_key_int(key_digits_2_long_int(matrix_kpub[i])));
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_int(short **matrix_kpriv, short **matrix_kcod, int lines){
    for (int i = 0; i < lines; ++i) {
        store_key_int(matrix_kcod, 10, calc_runlength_int(key_digits_2_long_int(matrix_kpriv[i])));
    }
}
