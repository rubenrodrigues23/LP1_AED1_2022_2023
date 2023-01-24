//
// Created by ruben on 22/11/2022.
//

#ifndef LP1AED1_PROJETO_BIPOLAR_H
#define LP1AED1_PROJETO_BIPOLAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libs_src/lib_util.h"


int main_bipolar(int argc, const char *argv[]);
int is_digit(char c);
int bipolar_number(char * text);
int bipolar_number_ints(int num);
void count_digits_frequency(int num, int hist10[]);
#endif //LP1AED1_PROJETO_BIPOLAR_H

