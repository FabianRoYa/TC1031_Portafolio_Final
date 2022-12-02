// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yanez A01706636
// Date: 4/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
    int n, m, i, value, countA, countB;//Declaracion de variables a utilizar
	vector<int> data;//Declaracion de vectores a utilizar
	vector<int> aux;
	vector<int> wanted;

    cin >> n;//Entrada o llamada de los vectores.
	for(i=0; i < n; i++){   
		cin >> value;
		data.push_back(value);
	}

    cin >> m;//llamada de los datos.
	for(i=0; i < m; i++){   
		cin >> value;
		wanted.push_back(value);
	}

    aux = data;
	cout<< bubbleSort(aux) <<" "; 
	aux = data;
	cout<< selectionSort(aux) <<" ";
	aux = data;
	cout<< insertionSort(aux) <<"\n\n";

//Impresion de las comparaciones binaria y secuencial.
    for(i=0; i < m; i++){
		countA = 0;                             
		countB = 0;
		cout<<binarySearch(aux, wanted[i], countB)<<" ";
		sequentialSearch(aux, wanted[i], countA);
		cout<< countA <<" ";
		cout<< countB <<"\n";
	}

	return 0;
}
