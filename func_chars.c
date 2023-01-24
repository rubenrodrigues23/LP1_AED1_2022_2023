
#include "func_chars.h"
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

int main_func_chars(int argc, const char *argv[]) {
    //key_long_2_digits_char(12345);
    //calc_private_key_char(1234);

    char **c_matrix_pubkey = alloc_matrix_char(10, NCOLS);
    bulk_populate_public_keys_char(c_matrix_pubkey, 10);
    /*print_matrix_char(c_matrix_pubkey);
    printf("--------------------\n");
    printf("\n");*/

    char **c_matrix_privkey = alloc_matrix_char(10, NCOLS);
    bulk_compute_private_keys_char(c_matrix_pubkey, c_matrix_privkey, 10);
    /*print_matrix_char(c_matrix_privkey);
    printf("--------------------\n");
    printf("\n");*/

    char **c_matrix_codkey = alloc_matrix_char(10, NCOLS);
    bulk_compute_runlengths_char(c_matrix_privkey, c_matrix_codkey, 10);
    /*print_matrix_char(c_matrix_codkey);
    printf("--------------------\n");
    printf("\n");*/

    //exists_key_char(c_matrix_pubkey, 10, 42);

    //printf("%llu\n", get_private_key_char(c_matrix_pubkey,c_matrix_privkey, 10, 42));

    //printf("%llu\n", get_runlength_char(c_matrix_privkey, c_matrix_codkey, 10, 84));

    //printf("%llu\n", delete_key_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 42));
    //printf("%llu\n", delete_key_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, '486'));
    //print_matrix_char(c_matrix_pubkey);
    //print_matrix_char(c_matrix_privkey);
    //print_matrix_char(c_matrix_codkey);
    //printf("--------------------\n");
    //printf("\n");

    /*sort_matrix_char(c_matrix_pubkey, 10, 1);
    print_matrix_char(c_matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    sort_matrix_char(c_matrix_pubkey, 10, 0);
    print_matrix_char(c_matrix_pubkey);
    printf("--------------------\n");
    printf("\n");*/

    /*sort_matrix_char(c_matrix_privkey, 10, 1);
    print_matrix_char(c_matrix_privkey);
    printf("--------------------\n");
    printf("\n");
    sort_matrix_char(c_matrix_privkey, 10, 0);
    print_matrix_char(c_matrix_privkey);
    printf("--------------------\n");
    printf("\n");*/

    /*sort_matrix_char(c_matrix_codkey, 10, 1);
    print_matrix_char(c_matrix_codkey);
    printf("--------------------\n");
    printf("\n");
    sort_matrix_char(c_matrix_codkey, 10, 0);
    print_matrix_char(c_matrix_codkey);
    printf("--------------------\n");
    printf("\n");*/

    //sort_all_matrices_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 1);

    //sort_all_matrices_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 0);

    /*printf("Ordem Atual:\n");
    list_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 0);
    printf("Ordem Crescente:\n");
    list_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 1);
    printf("Ordem Derescente:\n");
    list_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, 2);*/

    //char filename[] = "matrixchar.txt";
    //save_txt_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, filename);
    //load_txt_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, filename);

    /*print_matrix_char(c_matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix_char(c_matrix_privkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix_char(c_matrix_codkey);*/

    //char filename[] = "binarycharmatrix.bin";
    //save_bin_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, filename);

    /*load_bin_keys_char(c_matrix_pubkey, c_matrix_privkey, c_matrix_codkey, 10, filename);
    print_matrix_char(c_matrix_pubkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix_char(c_matrix_privkey);
    printf("--------------------\n");
    printf("\n");
    print_matrix_char(c_matrix_codkey);*/

    return 0;
}

/**
 * Conta o número de digitos
 * @param num numero recebido para contar os digitos
 * @return count que é o numero de digitos
 */
int count_num(unsigned long long num){
    int count=0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

/**
 * Print matrix
 * @param matrix
 */
void print_matrix_char(char **matrix){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            if (matrix[i][j]>=0)
                printf("%c ", matrix[i][j]);
            else
                printf(". ");
        }
        printf("\n");
    }
}

/**
 * Create an array of digits in ascii i.e. chars for a given key.
* @param key - long key
 * @return address of array of digits in ascii for a given key
 */
char* key_long_2_digits_char(unsigned long long key){
    // Calculate number of digits in key
    int num_digits = count_num(key);

    // Allocate memory for array of digits
    char * key_digits = malloc((num_digits+1) * sizeof(char));
    if (key_digits == NULL) {
        printf("Error allocating memory for key digits array\n");
        exit(1);
    }
    // Convert key to array of digits
    sprintf(key_digits, "%llu", key);

    // Print the array of digits
    /*for (int i = 0; i < num_digits; i++) {
        printf("%c ", key_digits[i]);
        printf("\n");
    }*/
    return key_digits;
}

/**
 * Receives an array of digits in ascii i.e. chars and returns the long key.
 * @param keydigits - array of digits of key
 * @return address of array of digits for a given key
 */
unsigned long long key_digits_2_long_char(char* keydigits){
    unsigned long long longkey = strtoull(keydigits, NULL, 10); //Converter a string para unsigned long long
    return longkey;
}

/**
 * Calculate the bipolar private key from a given public key (returns the bipolar private key).
 * @param pubkey - public key for which to calculate the private key
 * @return bipolar number representing the private key
 */
unsigned long long calc_private_key_char(unsigned long long pubkey){
    return calc_private_key_int(pubkey);
}

/**
 * Calculate the run-length from a given private key.
 * @param privkey - private key for which to calculate the run-length
 * @return run-length number representing the private key
 */
unsigned long long calc_runlength_char(unsigned long long privkey){
    return calc_runlength_int(privkey);
}

/**
 * Calculate the private key from a run-length.
 * @param runlengthkey - run-length for which to calculate the private key
 * @return private key that corresponds to the runlengthkey arg
 */
unsigned long long private_key_from_runlength_char(unsigned long long runlengthkey){
    return private_key_from_runlength_int(runlengthkey);
}

/**
 * Memory allocation for a char matrix with nlines and ncolumns
 * @param nlines - number of lines
 * @param ncolumns - number of columns
 * @return pointer to the allocated memory of the matrix
 */
char** alloc_matrix_char(int nlines, int ncolumns){
    char **matrix;
    matrix = malloc(nlines * sizeof(char *));
    for (int i = 0; i < nlines; i++)
    {
        matrix[i] = malloc(ncolumns * sizeof(char));
    }

    // Initialize the matrix
    for (int i = 0; i < nlines; i++)
    {
        for (int j = 0; j < ncolumns; j++)
        {
            matrix[i][j] = '\0';
        }
    }
    return matrix;
}

/**
 * Store a key (pub, priv or run-length) into the first available position of given matrix.
 * @param matrix - matrix to store the key
 * @param lines - matrix number of lines
 * @param key - key to be stored
 */
void store_key_char(char **matrix, int lines, unsigned long long key){
    for (int i = 0; i < lines; i++) {
        if (matrix[i][0] == '\0'){
            char * keydigits = key_long_2_digits_char(key);
            //printf("%s,%d\n", keydigits, key);
            strcpy(matrix[i], keydigits);
            break;
        }
    }
}

/**
 * Verify if a given key exists in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return 1 if it exists, 0 if it doesn't
 */
int exists_key_char(char **matrix, int lines, unsigned long long key){
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_char(matrix[i]) == key){
            //printf("Existe!");
            return 1;
        }
    }
    return 0;
}

/**
 * Returns the private key corresponding to the given public key
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key of the given pubkey
 */
unsigned long long get_private_key_char(char **matrix_kpub, char **matrix_kpriv, int lines, unsigned long long pubkey){
    for (int i = 0; i < lines; i++) {
        unsigned long long pubkey_in_matrix = key_digits_2_long_char(matrix_kpub[i]);
        if (pubkey_in_matrix == pubkey) {
            return key_digits_2_long_char(matrix_kpriv[i]);
        }
    }
    return 0;
}

/**
 * Returns the run-length key of a given private key
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key for which we want the private key
 * @return private key runlength of the given pubkey
 */
unsigned long long get_runlength_char(char **matrix_kpriv, char **matrix_kcod, int lines, unsigned long long privkey){
    for (int i = 0; i < lines; i++) {
        unsigned long long privkey_in_matrix = key_digits_2_long_char(matrix_kpriv[i]);
        if (privkey_in_matrix == privkey) {
            return key_digits_2_long_char(matrix_kcod[i]);
        }
    }
    return 0;
}

/**
 * index of a given key  in the matrix.
 * @param matrix - matrix with keys
 * @param lines - matrix number of lines
 * @param key - key to check if it exists
 * @return index if it exists, -1 if it doesn't
 */
int key_index_char(char **matrix, int lines, unsigned long long key) {
    for (int i = 0; i < lines; i++) {
        if (key_digits_2_long_char(matrix[i]) == key)
            return i;
    }
    return -1;
}

/**
 * Delete a given public key (and corresponding priv and runlength keys) from all matrices.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param pubkey - public key to delete
 * @return pubkey that was deleted
 */
unsigned long long delete_key_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char pubkey){
 /*   if (exists_key_char(matrix_kpub, 10, pubkey)) { //Verifica se a chave existe na matriz
        unsigned long long privkey = calc_private_key_int(pubkey); // calcula a chave privada
        unsigned long long runkey = calc_runlength_int(privkey); // calcula o run length da chave privada
        for (int i = key_index_char(matrix_kpub, 10, pubkey); i < lines; i++) { //
            if (i + 1 == lines) { //Verificar se esta na ultima posição da matriz
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpub[i][j] = '\0';
                }
            } else {
                matrix_kpub[i] = matrix_kpub[i + 1];  // igual a proxima posiçao
                if (matrix_kpub[i][0] == '\0') // se n tiver cheia salta fora
                    break;
            }
        }
        for (int i = key_index_char(matrix_kpriv, 10, privkey); i < lines; i++) {
            if (i == -1) // se n existir retorna -1 no key index char
                break;
            if (i + 1 == lines) { // ultima posição
                for (int j = 0; j < NCOLS; ++j) {
                    matrix_kpriv[i][j] = '\0';
                }
            } else {
                matrix_kpriv[i] = matrix_kpriv[i + 1];
                if (matrix_kpriv[i + 1][0] == '\0')
                    break;
            }
        }
        for (int i = key_index_char(matrix_kcod, 10, runkey); i < lines; i++) {
            if (i == -1)
                break;
            if (i + 1 == lines) {
                for (int j = 0; j < 4; ++j) {
                    matrix_kcod[i][j] = '\0';
                }
            } else {
                matrix_kcod[i] = matrix_kcod[i + 1];
                if (matrix_kcod[i + 1][0] == '\0')
                    break;
            }
        }
    } else {
        printf("Nao existe\n");
    }*/
}

/**
 * Automatically generate and save a given amount (<lines>) of public keys.
 * @param matrix_kpub - public keys matrix
 * @param lines - matrix number of lines
 */
void bulk_populate_public_keys_char(char **matrix_kpub, int lines){
    for (int i = 0; i < lines; i++) {
        store_key_char(matrix_kpub,lines, new_public_key_int());

    }
}

/**
 * Automatically calculate, generate and store all private keys for the existing public keys.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_private_keys_char(char **matrix_kpub, char **matrix_kpriv, int lines){
    for (int i = 0; i < lines; i++) {
        unsigned long long priv = calc_private_key_char(key_digits_2_long_char(matrix_kpub[i]));
        store_key_char(matrix_kpriv, lines, priv);
    }
}

/**
 * Automatically calculate and store all run-lengths for the existing private keys.
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 */
void bulk_compute_runlengths_char(char **matrix_kpriv, char **matrix_kcod, int lines){
    for (int i = 0; i < lines; i++) {
        unsigned long long runlength = calc_runlength_char(key_digits_2_long_char(matrix_kpriv[i]));
        store_key_char(matrix_kcod, lines, runlength);
    }
}

/**
 * Return a list of all private keys matching a given partial public key.
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param lines - matrix number of lines
 * @param partialpubkey - part of public key to filter the private keys
 * @return array of private keys matching the partialpubkey
 */
char** search_private_keys_char(char **matrix_kpub, char **matrix_kpriv, int lines, unsigned long long partialpubkey){

}

/**
 * Sort a matrix keys in ascending or descending order
 * @param matrix - matrix to be sorted
 * @param lines - matrix number of lines
 * @param order - order == 1 ? ascending : descending
 */
void sort_matrix_char(char **matrix, int lines, int order){
    if(order == 1){
        int n = lines;  //Selection Sort
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (key_digits_2_long_char(matrix[j]) < key_digits_2_long_char(matrix[min_idx]))
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            char *temp = matrix[min_idx];
            matrix[min_idx] = matrix[i];
            matrix[i] = temp;
        }
    }
    else{
        int n = lines;
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the maximum element in unsorted array
            int max_idx = i;
            for (int j = i + 1; j < n; j++)
                if (key_digits_2_long_char(matrix[j]) > key_digits_2_long_char(matrix[max_idx]))
                    max_idx = j;

            // Swap the found minimum element with the first
            // element
            char *temp = matrix[max_idx];
            matrix[max_idx] = matrix[i];
            matrix[i] = temp;
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
void sort_all_matrices_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, int order){
        sort_matrix_char(matrix_kpub, lines, order);
        print_matrix_char(matrix_kpub);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kpriv, lines, order);
        print_matrix_char(matrix_kpriv);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kcod, lines, order);
        print_matrix_char(matrix_kcod);
        printf("--------------------\n");
        printf("\n");
}

/**
 * Print all keys on the console, sorted by pubkeys sizes (i.e. number of digits).
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param order - order == 0 ? current order : order == 1 ? ascending : descending
 */
void list_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, int order){
    if(order == 0){ //Ordem atual
        print_matrix_char(matrix_kpub);
        printf("--------------------\n");
        printf("\n");
        print_matrix_char(matrix_kpriv);
        printf("--------------------\n");
        printf("\n");
        print_matrix_char(matrix_kcod);
    }
    else if (order == 1){ // Ordem Crescente
        sort_matrix_char(matrix_kpub, 10, 1);
        print_matrix_char(matrix_kpub);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kpriv, 10, 1);
        print_matrix_char(matrix_kpriv);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kcod, 10, 1);
        print_matrix_char(matrix_kcod);
    }
    else{ //Ordem Decrescente
        sort_matrix_char(matrix_kpub, 10, 0);
        print_matrix_char(matrix_kpub);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kpriv, 10, 0);
        print_matrix_char(matrix_kpriv);
        printf("--------------------\n");
        printf("\n");
        sort_matrix_char(matrix_kcod, 10, 0);
        print_matrix_char(matrix_kcod);
    }

}

/**
 * Save all matrix data to a text file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the text file where to store the data
 */
void save_txt_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){
    FILE *fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\matrixchar.txt", "w");
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro!\n");
        return;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fprintf(fp, "%c ", matrix_kpub[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fprintf(fp, "%c ", matrix_kpriv[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fprintf(fp, "%c ", matrix_kcod[i][j]);
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
void load_txt_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){
    FILE *fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\matrixchar.txt", "r");
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro!\n");
        return;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%s ", &matrix_kpub[i][j]);
        }
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%s ", &matrix_kpriv[i][j]);
        }
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < NCOLS; j++) {
            fscanf(fp, "%s ", &matrix_kcod[i][j]);
        }
    }
    fclose(fp);
    printf("Dados Carregados no ficheiro %s\n", filename);
}

/**
 * Save all matrix data to a binary file
 * @param matrix_kpub - public keys matrix
 * @param matrix_kpriv - private keys matrix
 * @param matrix_kcod - run-lengths matrix
 * @param lines - matrix number of lines
 * @param filename - name of the binary file where to store the data
 */
void save_bin_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){
    FILE* fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\binarycharmatrix.bin", "wb");
    int i;
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;
    }
    for (i = 0; i < lines; i++) {
        fwrite(matrix_kpub[i], sizeof(char), lines, fp);
        fwrite(matrix_kpriv[i], sizeof(char), lines, fp);
        fwrite(matrix_kcod[i], sizeof(char), lines, fp);
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
void load_bin_keys_char(char **matrix_kpub, char **matrix_kpriv, char **matrix_kcod, int lines, char filename[]){
    FILE* fp = fopen("C:\\Users\\ruben\\Desktop\\LP1AED1_Projeto\\binarycharmatrix.bin", "rb");
    int i;
    if (fp == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;
    }
    for (i = 0; i < lines; i++) {
        fread(matrix_kpub[i], sizeof(char), lines, fp);
        fread(matrix_kpriv[i], sizeof(char), lines, fp);
        fread(matrix_kcod[i], sizeof(char), lines, fp);
    }
    fclose(fp);
    printf("Dados carregados do ficheiro binario %s\n", filename);
}

