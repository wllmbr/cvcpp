#include "matrix_test.hpp"

Matrix<double> a_matrix;
Matrix<double> b_matrix;
Matrix<double> c_matrix;

void configure_test(void){

	/* Initialize Matricies */
	a_matrix.init(12,12);
	b_matrix.init(12,12);
	c_matrix.init(12,12);

	double q = 0;

	uint16_t i, j;
	for(i = 0; i < 12; i++){
		for(j = 0; j < 12; j++){
			a_matrix[i][j] = q++;
			b_matrix[i][j] = q++;
		}
	}

	printf("Finished Initializing Matrix\n");

	return;
}


uint32_t execute_matrix_test(uint32_t iter){
	uint32_t i;
	for(i = 0; i < iter; i++){
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
		c_matrix = a_matrix * b_matrix;
	}

	return 10;
};

void display_results(void){
	c_matrix.display();

}