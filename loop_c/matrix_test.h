#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include <stdint.h>
#include <stdlib.h>

#include "matrix.h"

void configure_test(void);
void display_results(void);
uint32_t execute_matrix_test(uint32_t iter) __attribute__((optimize("-O0")));



#endif