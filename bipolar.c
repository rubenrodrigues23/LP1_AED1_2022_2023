#include "bipolar.h"
#include "libs_src/lib_util.h"
#define BUFFER 1024


int main_bipolar(int argc, const char *argv[]) {
    return 0;
}

/**
 * This function checks if a char is a digit or not.
 * @param c - char to be checked.
 * @return 1 (if is digit); 0 otherwise.
 */
int is_digit(char c){
    switch (c) {
        case '0'...'9':
            return 1;
        default:
            return 0;
    }
}

/**
 * Recebe uma string e verifica se é bipolar
 * @param text número em string
 * @return valor inteiro correspondente ao bipolar se text for representação válida de um bipolar, caso text não seja bipolar
 * ou inteiro retorna código de erro negativo
 */
int bipolar_number(char * text){
    int sz = strlen(text);
    int countChanges = 0;
    int i = 0;
    if(sz < 2){ //verificar se comprimento é maior que 2
        printf("Nao Bipolar!\n");
        return -1;
    }
    for (int j = 0; j < sz; j++) {
        if (!is_digit(text[j])) { //Verificar se são digitos
            printf("Nao Bipolar!\n");
            return -2;
        }
    }
    while (text[i+1] != '\0'){
        if(text[i] != text[i+1]){
            countChanges++;
        }
        i++;
    }
    if(countChanges > 1){ //Verificar se existe mais do que 1 mudança de dígito
        printf("Nao Bipolar!\n");
        return -3;
    }
    printf("Bipolar!\n");
    return 0;
}

/**
 * Recebe uma string e verifica se é bipolar
 * @param num
 * @return valor inteiro correspondente ao bipolar se text for representação válida de um bipolar, caso text não seja bipolar
 * ou inteiro retorna código de erro negativo
 */
int bipolar_number_ints(int num){
    char text[20];
    itoa(num, text, 10);
    //printf("Num: %s\n", text);
    int sz = strlen(text);
    int countChanges = 0;
    int i = 0;
    if(sz < 2){ //verificar se comprimento é maior que 2
        //printf("Nao Bipolar!\n");
        return -1;
    }
    for (int j = 0; j < sz; j++) {
        if (!is_digit(text[j])) { //Verificar se são digitos
            //printf("Nao Bipolar!\n");
            return -2;
        }
    }
    while (text[i+1] != '\0'){
        if(text[i] != text[i+1]){
            countChanges++;
        }
        i++;
    }
    if(countChanges > 1){ //Verificar se existe mais do que 1 mudança de dígito
        //printf("Nao Bipolar!\n");
        return -3;
    }
    //printf("Bipolar!\n");
    return 0;
}

/**
 * Count digits frequency
 * @param num
 * @param hist10
 */
void count_digits_frequency(int num, int hist10[]){
    long long n;
    int i, lastDigit;
    n = num;
    while(n != 0)
    {
        lastDigit = n % 10; /* Vai ao último digito */
        n /= 10;/* Remove o último digito */
        hist10[lastDigit]++;/* Incrementa a frequência no array */
    }
    printf("Histograma de digitos de %d: \n", num);
    for(i = 0; i < 10; i++)
    {
        printf("Numero %d aparece %d vezes\n", i, hist10[i]);
    }
}


