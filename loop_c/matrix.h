#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Matrix_Double{
	double 		**vals;
	uint16_t	row_len;
	uint16_t	col_len;
};

void	init_mat(struct Matrix_Double *a, uint16_t row, uint16_t col);
double 	read_mat(struct Matrix_Double *a, uint16_t row, uint16_t col);
void 	assign_mat(struct Matrix_Double *a, uint16_t row, uint16_t col, double val);
void 	mult_mat(struct Matrix_Double *a, struct Matrix_Double *b, struct Matrix_Double *c);
void	print_mat(struct Matrix_Double *a);

#endif