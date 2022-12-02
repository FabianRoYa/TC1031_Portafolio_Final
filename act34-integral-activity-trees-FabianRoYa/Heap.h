
// =================================================================
//
// File: Heap.h
// Author: Fabian Erubiel Rojas Yanez A01706636 
//
// =================================================================

#ifndef MINHEAP_H
#define MINHEAP_H

#include <climits>
#include <sstream>
#include <cmath>
#include <vector>

typedef unsigned int uint;

template <class T>
class MinHeap {
private:
	std::vector<T> data;

	uint parent(uint) const;
	uint left(uint i) const;
	uint right(uint i) const;

	void swap(uint, uint);

public:
	MinHeap() {};

	uint size() const;
	bool empty() const;

	void heapify(uint);

	T top() const;
	void push(const T);
	int pop();

	std::string toString() const;
	std::string byLevel() const;
};

template <class T>
uint MinHeap<T>::parent(uint i) const {
	return (i - 1) / 2;
}

template <class T>
uint MinHeap<T>::left(uint i) const {
	return 2 * i + 1;
}

template <class T>
uint MinHeap<T>::right(uint i) const {
	return 2 * i + 2;
}

template <class T>
bool MinHeap<T>::empty() const {
	return data.empty();
}

template <class T>
uint MinHeap<T>::size() const {
	return data.size();
}

template <class T>
void MinHeap<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void MinHeap<T>::heapify(uint pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint min = pos;

	if ((le < data.size()) && (data[le] < data[min])) {
		min = le;
	}
	if ((ri < data.size()) && (data[ri] < data[min])) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
T MinHeap<T>::top() const {
	if (empty()) {
		return INT_MAX;
	}
	else {
		return data[0];
	}
}

template <class T>
void MinHeap<T>::push(const T item) {
	data.push_back(item);
	uint pos = data.size() - 1;
	while ((pos > 0) && (data[parent(pos)] > data[pos])) {
		swap(pos, parent(pos));
		pos = parent(pos);
	}
}

template <class T>
int MinHeap<T>::pop() {
	if (empty()) {
		return INT_MAX;
	}
	else {
		T item = data[0];
		data[0] = data[data.size() - 1];
		data.pop_back();
		heapify(0);
		return item;
	}
}

template <class T>
std::string MinHeap<T>::toString() const {
	std::stringstream aux;
	for (uint i = 0; i < data.size(); i++) {
		aux << data[i] << " ";
	}
	return aux.str();
}


template <class T>
std::string MinHeap<T>::byLevel() const {
	std::stringstream aux;
	uint level = 0;
	uint count = 0;
	uint max = 1;
	for (uint i = 0; i < data.size(); i++) {
		aux << data[i] << " ";
		count++;
		if (count == max) {
			aux << std::endl;
			level++;
			count = 0;
			max = pow(2, level);
		}
	}
	return aux.str();
}

#endif