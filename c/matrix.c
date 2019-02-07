#include "matrix.h"

void inverse_matrix(double a[SQUARE_DIM][SQUARE_DIM], double b[SQUARE_DIM][SQUARE_DIM]){
	double temp[SQUARE_DIM][REC_DIM];
	uint8_t row, col;
	for(row = 0; row < SQUARE_DIM; row++){
		for(col = 0; col < SQUARE_DIM; col++){
			temp[row][col] = b[row][col];
		}
	}

	// print_sqr(b);

	uint8_t i;
	for(i = 0; i < SQUARE_DIM; i++){
		temp[i][i+SQUARE_DIM] = 1.0;
	}

	// print_full(temp);

	rref(temp);

	for(row = 0; row < SQUARE_DIM; row++){
		for(col = 0; col < SQUARE_DIM; col++){
			a[row][col] = temp[row][col+SQUARE_DIM];
		}
	}
}

/* Matrix Operations */

void rref(double a[SQUARE_DIM][REC_DIM]){
	uint8_t target_row;
	uint8_t target_col;
	uint8_t i, j;
	double scale;
	double copy[1][REC_DIM];
	uint8_t row;

	i = 0;
	j = 0;
	for(row = 0; row < SQUARE_DIM; row++){
		// print_full(a);
		// printf("Working Row %d\n", row);
		/* If Aij = 0, swap the i-th row... */
		if( a[i][j] == 0){
			// printf("Swapping Row\n");
			/* with a lower row that the pivot point is not zero */
			for(target_row = i; target_row < SQUARE_DIM; target_row++){
				if(a[target_row][j] != 0){
					swap_row(a, i, target_row);
					// print_full(a);
				}
			}
		}

		/* Divide the i-th row to make pivot 1 */
		scale = 1.0 / a[i][j];
		mult_row(a, scale, i);
		// printf("R%d = %f * R%d\n", i, scale, i);

		/* Eliminate all other entries in the j-th column by subtracting
			multiples of the i-th row from the other rows */

		for(target_row = 0; target_row < SQUARE_DIM; target_row++){
			/*Make sure we're not adjusting our own row */
			if(target_row != i){
				// printf("Scaling Row %d col %d - ", target_row, j);

				/* Generate Scale */
				scale = -1 * (a[target_row][j] / a[i][j]);
				// printf("R%d += %f * R%d\n", target_row, scale, target_row);

				/* Create temporary to subtract */
				for(target_col = 0; target_col < REC_DIM; target_col++){
					copy[0][target_col] = a[i][target_col] * scale;
				}

				/* Subtract out copy */
				add_row(a, copy, target_row);
			}
		}

		i++;
		j++;
	}

	// print_full(a);

}

/* Elementary Operations */
void swap_row(double a[SQUARE_DIM][REC_DIM], uint8_t source, uint8_t target){
	// printf("R%d = R%d -> R%d = R%d", source, target, target, source);
	double temp;
	uint8_t i;
	for(i = 0; i < REC_DIM; i++){
		temp = a[source][i];
		a[source][i] = a[target][i];
		a[target][i] = temp;
	}

}

void mult_row(double a[SQUARE_DIM][REC_DIM], double val, uint8_t row){
	uint8_t i;
	for(i = 0; i < REC_DIM; i++){
		a[row][i] *= val;
	}
}

void add_row(double a[SQUARE_DIM][REC_DIM], double b[1][REC_DIM], uint8_t row){
	uint8_t i;
	for(i = 0; i < REC_DIM; i++){
		a[row][i] += b[0][i];
	}
}

void print_full(double a[SQUARE_DIM][REC_DIM]){
	// return;
	uint8_t r, c;
	for(r = 0; r < SQUARE_DIM; r++){
		for(c = 0; c < REC_DIM; c++){
			printf("%0.f\t",a[r][c]);
		}
		printf("\n");
	}
}


void print_sqr(double a[SQUARE_DIM][SQUARE_DIM]){
	uint8_t r, c;
	for(r = 0; r < SQUARE_DIM; r++){
		for(c = 0; c < SQUARE_DIM; c++){
			printf("%0.3f\t",a[r][c]);
		}
		printf("\n");
	}
}