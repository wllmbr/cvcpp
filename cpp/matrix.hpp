#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdint.h>
#include "array.hpp"
#include <stdlib.h>
// #include <iostream>
// #include <ostream>



template <typename T> class Matrix{

private:
	Array<T>	*arrs;
	uint16_t	row_len;
	uint16_t	col_len;

public:
	Matrix(){
		row_len = 0;
		col_len = 0;
		arrs = new Array<T>[row_len];

		uint16_t i;
		for(i = 0; i < row_len; i++){
			arrs[i].init(col_len);
		}
	}

	~Matrix(){
		// printf("Matrix Destructor Called\n");
		delete[] arrs;
	}

	Matrix(const Matrix& that): arrs(that.arrs), row_len(that.row_len), col_len(that.col_len) {

	}

	Matrix(uint16_t r_len, uint16_t c_len){
		// printf("Constructing Matrix\n");
		// this->row_len = r_len;
		// this->col_len = c_len;
		// arrs = new Array<T>[row_len];

		// uint16_t i;
		// for(i = 0; i < row_len; i++){
		// 	arrs[i].init(col_len);
		// }
		init(r_len,c_len);
	}

	void init(uint16_t r_len, uint16_t c_len){
		// printf("Initializing Matrix\n");
		this->row_len = r_len;
		this->col_len = c_len;
		arrs = new Array<T>[row_len];

		uint16_t i;
		for(i = 0; i < row_len; i++){
			arrs[i].init(col_len);
		}
	}

	Matrix<T> operator* (Matrix<T>& a) const{
		/* Check Matrix Dimensions Agree */
		if(this->col_len != a.getRowLen()){
			// std::cout << "Matrix dimensions don't agree for multiplication!\n";
			exit(-1);
		}
		// printf("Multipling Matrix\n");

		/* Make new dummy matrix */
		Matrix<T> res(row_len,a.getColLen());

		uint16_t row, col, i;
		for(row = 0; row < res.getColLen(); row++){
			for(col = 0; col < res.getRowLen(); col++){
				T accumulator = 0;
				for(i = 0; i < res.getColLen(); i++){
					accumulator += arrs[row][i] * a[i][col];
				}
				res[row][col] = accumulator;
			}
		}
		
		// std::cout << "Performed multiplication\n" << res;

		return res;
	}

	Matrix<T>& operator= (Matrix a){
		/* Check Matrix Dimensions */
		if((row_len != a.getRowLen()) && (col_len != a.getColLen())){
			// std::cout << "Matrix Assignment Dimensions don't agree!\n";
			exit(-1);
		}
		// printf("Assigning Matrix\n");
		uint16_t row,col;
		for(row = 0; row < col_len; row++){
			for(col = 0; col < row_len; col++){
				arrs[row][col] = a[row][col];
			}
		}

		return *this;

	}

	Array<T>& operator[] (const uint16_t& index){
		return this->arrs[index];
	}

	uint16_t getRowLen(void){
		return row_len;
	}

	uint16_t getColLen(void){
		return col_len;
	}

	void display(void){
		uint16_t row, col;
		for(row = 0; row < col_len; row++){
			printf("\n");
			for(col = 0; col < row_len; col++){
				// stream << matrix[row][col] << " ";
				double val = arrs[row][col];
				printf("%7.3f\t",val);
			}
		}
		printf("\n");
	}

};


#endif