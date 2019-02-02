#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <class T>
class Array{
private:
	T* dataStorage;
	uint16_t len;

public:

	~Array(){
		delete[] dataStorage;
	}

	Array(){
		this->len = 0;
	}

	Array(uint16_t i){
		this->dataStorage = new T[i];
		this->len = i;
	}

	void init(uint16_t i){
		this->dataStorage = new T[i];
		this->len = i;
	}

	Array& operator = (const Array& a){
		if(this->len != a.getLen()){
			/* Normally should raise an exception, 
				but instead just print an error and
				exit the program
			*/

			printf("Array Assignment lengths do not match!\n");
			exit(-1);
		}

		/* Copy over all elements one at a time */
		uint16_t i;
		for(i = 0; i < this->len; i++){
			this->dataStorage[i] = a.dataStorage[i];
		}

		return *this;
	}

	T& operator[] (const uint16_t i){
		return this->dataStorage[i];
	}

	uint16_t getLen(void){
		return this->len;
	}
};

#endif