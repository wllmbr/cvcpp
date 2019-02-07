#include "matrix_test.h"

struct Matrix_Double a_matrix;
struct Matrix_Double b_matrix;
struct Matrix_Double c_matrix;

void configure_test(void){

	init_mat(&a_matrix, 12, 12);
	init_mat(&b_matrix, 12, 12);
	init_mat(&c_matrix, 12, 12);


	uint16_t i, j;
	double q = 0;
	for(i = 0; i < 12; i++){
		for(j = 0; j < 12; j++){
			a_matrix.vals[i][j] = q++;
			b_matrix.vals[i][j] = q++;
		}
	}

	printf("Finished Initializing Matrix\n");
}

void display_results(void){
	print_mat(&c_matrix);
}

uint32_t execute_matrix_test(uint32_t iter){
	uint32_t i;
	for(i = 0; i < iter; i++){
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
		mult_mat(&c_matrix, &a_matrix, &b_matrix);
	}

	return 10;
}
