#include "matrix.h"

void	init_mat(struct Matrix_Double *a, uint16_t row, uint16_t col){
	a->vals = (double **)malloc(sizeof(double) * row);
	uint16_t i;
	for(i = 0; i < col; i++){
		a->vals[i] = (double *)malloc(sizeof(double) * col);
	}
	printf("Made Matrix\n");

	a->row_len = col;
	a->col_len = row;
}

double 	read_mat(struct Matrix_Double *a, uint16_t row, uint16_t col){
	return a->vals[row][col];
}

void 	assign_mat(struct Matrix_Double *a, uint16_t row, uint16_t col, double val){
	a->vals[row][col] = val;
}

void 	mult_mat(struct Matrix_Double *a, struct Matrix_Double *b, struct Matrix_Double *c){
	
	/* Perform size check */
	if(b->col_len != c->row_len){
		printf("Matrix dimensions don't agree for multiplication!\n");
		exit(-1);
	}

	uint16_t row, col, i;

	for(row = 0; row < a->col_len; row++){
		for(col = 0; col < a->row_len; col++){
			double accumulator = 0;
			for(i = 0; i < a->col_len; i++){
				accumulator += b->vals[row][i] * c->vals[i][col];
			}
			a->vals[row][col] = accumulator;
		}
	}
}

void	print_mat(struct Matrix_Double *a){
	uint16_t row, col;
	for(row = 0; row < a->col_len; row++){
		printf("\n");
		for(col = 0; col < a->row_len; col++){
			double val = a->vals[row][col];
			printf("%7.3f\t",val);
		}
	}
	printf("\n");
}
