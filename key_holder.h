
#ifndef LP1AED1_PROJETO_KEY_HOLDER_H
#define LP1AED1_PROJETO_KEY_HOLDER_H

/**
 * Struc para guardar as matrizes de chaves publicas, privadas e codificadas de ints e chars
 */
typedef struct {
    short **matrix_kpub;
    short **matrix_kpriv;
    short **matrix_kcod;

    char **c_matrix_kpub;
    char **c_matrix_kpriv;
    char **c_matrix_kcod;

    int lines;
} KEY_HOLDER;



#endif //LP1AED1_PROJETO_KEY_HOLDER_H
