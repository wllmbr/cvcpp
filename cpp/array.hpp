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
		// printf("Array Destructor Called\n");
		delete[] dataStorage;
	}

	Array(){
		len = 0;
	}

	Array(uint16_t i){
		dataStorage = new T[i];
		len = i;

		uint16_t index;
		for(index = 0; index < i; i++){
			dataStorage[index] = 0x77;
		}

	}

	void init(uint16_t i){
		dataStorage = new T[i];
		len = i;
	}

	Array& operator = (const Array& a){
		if(len != a.getLen()){
			/* Normally should raise an exception, 
				but instead just print an error and
				exit the program
			*/

			// printf("Array Assignment lengths do not match!\n");
			exit(-1);
		}

		/* Copy over all elements one at a time */
		uint16_t i;
		for(i = 0; i < len; i++){
			dataStorage[i] = a.dataStorage[i];
		}

		return *this;
	}

	T& operator[] (const uint16_t i){
		return dataStorage[i];
	}

	uint16_t getLen(void){
		return len;
	}
};

#endif