#pragma once
#include "Offer.h"
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

template <typename ElementType>

class DynamicArray
{
public:

	//DynamicArray<ElementType>(){capacity(100)}; // = default parameter

	// RULE OF THREE 
	// destructor
	DynamicArray<ElementType>(int capacity=100) {
		length = 0;
		this->capacity = capacity;
		data = new ElementType[capacity]();

		if (data == nullptr) {
			cerr << "DynamicArray(): failed to allocate memory" << endl;
			exit(-1);
		}
	}
	~DynamicArray<ElementType>() {
		//free the allocated memory
		delete[] data;
	}


	DynamicArray<ElementType>& operator=(const DynamicArray<ElementType>& other) {

		if (this != &other) { // self assignment check
			// deep copy of other
			length = other.length;
			capacity = other.capacity;

			delete[] this->data;
			// !! data 
			// data = other.data; NOO! this is shallow copy
			// deep copy of data
			data = new ElementType[other.capacity]();

			if (data == nullptr) {
				cerr << "operator=(): failed to allocate memory" << endl;
				exit(-1);
			}

			for (unsigned int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		return *this; // the type of this is DynamicArray* -> dereferencing
	}

	DynamicArray<ElementType>(const DynamicArray<ElementType>& other) {
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new ElementType[other.capacity]();

		if (data == nullptr) {
			cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}

	void append(ElementType v)
	{
		// todo 
		// check if the length < capacity
		if (length == capacity) {
			// double the capacity
			resize(capacity * 2);
		}
		data[length] = v;
		length++;
	}

	ElementType popBack() {
		// delete and return the last element in the array
		// pre array is not empty
		if (length == 0) {
			// unfriendly way of handling corner cases
			cerr << "Precondition does not hold: popBack()" << endl;
			exit(-1);
		}

		// convention 0 - elements that were not set

		ElementType v = data[length];
		length--;

		return v;
	}

	ElementType remove(unsigned int index)
	{
		//  index >= 0 and index < length
		// pre index >=0 and index < length
		if (index >= 0 && index < length) {
			ElementType v = data[index];
			for (unsigned int i = index; i < length - 1; i++)
				data[i] = data[i + 1];
			length--;
			return v;
		}
		else {
			// unfriendly way of handling corner cases
			cerr << "Precondition does not hold: remove()" << endl;
			exit(-1);
		}
	}


	ElementType& get(unsigned int index) {

		// pre index >=0 and index < length
		if (index >= 0 && index < length) {
			return data[index];
		}
		else {
			// unfriendly way of handling corner cases
			cerr << "Precondition does not hold: get()" << endl;
			exit(-1);
		}
	}

	void resize(unsigned int newCapacity) {

		this->capacity = newCapacity;
		// no realloc  in c++

		ElementType* newData = new ElementType[newCapacity]();
		if (newData == nullptr) {
			cerr << "resize(): failed to allocate memory" << endl;
			exit(-1);
		}
		// previous elements located in data
		// copy them in newData
		for (unsigned int i = 0; i < length; i++) {
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}
	unsigned int get_count() {
		return this->count;
	}
	unsigned int get_length() {
		return this->length;
	}
	unsigned int get_capacity() {
		return this->capacity;
	}
	ElementType* get_data() {
		return this->data;
	}
	
private:
	// static -> it belongs to the class
	static int count;
	// Length – how many elements do we have(0)
	unsigned int length;
	//	Capacity – the max number of elements
	unsigned int capacity;
	// data - array itself
	ElementType* data;

};

