// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yanez A01706636 
// Date: 24/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include "Heap.h"

int main(int argc, char* argv[]) {
	
	std::ifstream input;
	std::ofstream output;

	if (argc != 3) {
		std::cout << argv[0] << " Uso incorrecto " << std::endl;
		return -1;
	}

	input.open(argv[1]);
	if (input.fail()) {
		std::cout << "No se puede abriri el archivo " << argv[1] << std::endl;
		return -1;
	}

	output.open(argv[2]);
	if (output.fail()) {
		std::cout << "No se puede escribir el archivo " << argv[2] << std::endl;
		return -1;
	}

	int n, e;
	input >> n;

	MinHeap<int> heap;
	for (int i = 0; i < n; i++) {
		input >> e;
		heap.push(e);
	}

	int k = 0;
	int sum;
	while (heap.size() > 1) {
		sum = heap.pop() + heap.pop();
		heap.push(sum);
		k += sum - 1;
	}
	output << k << std::endl;

	return 0;
}