#include <stdio.h>
#include "matrix.hpp"

typedef Matrix<double> Double_Matrix;

int main(void){

	Double_Matrix a(2,2);
	Double_Matrix b(2,2);
	Double_Matrix c(2,2);


	a[0][0] = 1;
	a[0][1] = 0;
	a[1][0] = 0;
	a[1][1] = 1;

	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;
	b[1][1] = 4;

	c = a * b;

	std::cout << a << b << c;

	return 0;
}
