#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){

	double a[SQUARE_DIM][SQUARE_DIM];
	double b[SQUARE_DIM][SQUARE_DIM];

	uint8_t r, c;
	for(r = 0; r < SQUARE_DIM; r++){
		for(c = 0; c < SQUARE_DIM; c++){
			if(c <= r){
				a[r][c] = (double)(1 + r);
			} else {
				a[r][c] = 0.0;
			}
		}
	}

	print_sqr(a);

	inverse_matrix(b,a);

	print_sqr(b);


	return 0;
}