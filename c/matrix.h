#ifndef MATRIX_H
#define MATRIX_H
#include <stdint.h>
#include <stdio.h>

#define SQUARE_DIM	3
#define REC_DIM		2 * SQUARE_DIM

void inverse_matrix(double a[SQUARE_DIM][SQUARE_DIM], double b[SQUARE_DIM][SQUARE_DIM]);

/* Matrix Operations */
void rref(double a[SQUARE_DIM][REC_DIM]);

/* Elementary Operations */
void swap_row(double a[SQUARE_DIM][REC_DIM], uint8_t source, uint8_t target);
void mult_row(double a[SQUARE_DIM][REC_DIM], double val, uint8_t row);
void add_row(double a[SQUARE_DIM][REC_DIM], double b[1][REC_DIM], uint8_t row);

void print_full(double a[SQUARE_DIM][REC_DIM]);
void print_sqr(double a[SQUARE_DIM][SQUARE_DIM]);
#endif