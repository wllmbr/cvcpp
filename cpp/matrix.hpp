#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdint.h>
#include "array.hpp"
#include <stdlib.h>
#include <iostream>
#include <ostream>



template <typename T> class Matrix{

private:
	Array<T>	*arrs;
	uint16_t	row_len;
	uint16_t	col_len;

public:
	Matrix(){
		this->row_len = 0;
		this->col_len = 0;
		this->arrs = new Array<T>[this->row_len];

		uint16_t i;
		for(i = 0; i < this->row_len; i++){
			this->arrs[i].init(this->col_len);
		}
	}

	~Matrix(){
		delete[] this->arrs;
	}

	Matrix(uint16_t row_len, uint16_t col_len){
		printf("Initializing Matrix\n");
		this->row_len = row_len;
		this->col_len = col_len;
		this->arrs = new Array<T>[this->row_len];

		uint16_t i;
		for(i = 0; i < this->row_len; i++){
			this->arrs[i].init(this->col_len);
		}
	}

	Matrix<T>& operator* (const Matrix& a){
		/* Check Matrix Dimensions Agree */
		if(this->getColLen() != a.getRowLen()){
			std::cout << "Matrix dimensions don't agree for multiplication!\n";
			exit(-1);
		}

		/* Make new dummy matrix */
		Matrix res(this->row_len,a.getColLen());

		uint16_t row, col, i;
		for(row = 0; row < res.getColLen(); row++){
			for(col = 0; col < res.getRowLen(); col++){
				T accumulator = 0;
				for(i = 0; i < res.getColLen(); i++){
					accumulator += this[row][i] * a[i][col];
				}
				res[row][col] = accumulator;
			}
		}
		
		return res;
	}

	Matrix<T>& operator= (const Matrix& a){
		/* Check Matrix Dimensions */
		if((this->row_len != a.getRowLen()) && (this->col_len != a.getColLen())){
			std::cout << "Matrix Assignment Dimensions don't agree!\n";
			exit(-1);
		}

		uint16_t row,col;
		for(row = 0; row < this->col_len; row++){
			for(col = 0; col < this->row_len; col++){
				this->arrs[row][col] = a[row][col];
			}
		}

		return *this;

	}

	Array<T>& operator[] (const uint16_t& index){
		return this->arrs[index];
	}

	uint16_t getRowLen(void){
		return this->row_len;
	}

	uint16_t getColLen(void){
		return this->col_len;
	}

	friend std::ostream& operator << (std::ostream& stream, const Matrix& matrix){

		uint16_t row, col;
		for(row = 0; row < matrix.getColLen; row++){
			stream << std::endl;
			for(col = 0; col < matrix.getRowLen; col++){
				stream << matrix[row][col] << " ";
			}
		}

		stream << std::endl;

		return stream;
	}

};


#endif