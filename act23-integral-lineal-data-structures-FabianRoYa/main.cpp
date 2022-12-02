// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yañez A01706636
// Date: 
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "merge.h"
#include "Boat.h"

using namespace std;

//Para el metodo de obtener las fechas del mes, me base en el codigo del video
//https://www.youtube.com/watch?v=ExuUYZhzuNY perteneciente al canal de Diana Paz
//"Video Tutorial Programa de los meses del año en Dev C++" 
//Codigo con la funcionalidad de detectar y convertir el mes en forma numerica
//a string para los outputs.
string dateArray(string date){
	switch (stoi(date)){
	case 1:
		return "jan";
		break;
	case 2:
		return "feb";
		break;
	case 3:
		return "mar";
		break;
	case 4:
		return "apr";
		break;
	case 5:
		return "may";
		break;
	case 6:
		return "jun";
		break;
	case 7:
		return "jul";
		break;
	case 8:
		return "aug";
		break;
	case 9:
		return "sep";
		break;
	case 10:
		return "oct";
		break;
	case 11:
		return "nov";
		break;
	case 12:
		return "dec";
		break;
	}
	return "Error en la fecha ingresada";
}

string dateArray(int date){
	switch (date){
	case 1:
		return "jan";
		break;
	case 2:
		return "feb";
		break;
	case 3:
		return "mar";
		break;
	case 4:
		return "apr";
		break;
	case 5:
		return "may";
		break;
	case 6:
		return "jun";
		break;
	case 7:
		return "jul";
		break;
	case 8:
		return "aug";
		break;
	case 9:
		return "sep";
		break;
	case 10:
		return "oct";
		break;
	case 11:
		return "nov";
		break;
	case 12:
		return "dec";
		break;
	}
	return "Error en la fecha ingresada";
}

//El uso para convertir los int de los meses (Numericos) a string
//en donde con la funcion de stoi se hace para su manejo.

int main(int argc, char *argv[]){
	//Lectura de los archivos de entrada usando la libreria fstream
	if (argc != 3){
		cout << "Invalid usage" << endl;
		return -1;
	}

	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);
	if (inFile.fail())
		return -1;
	if (outFile.fail())
		return -1;

    //Declaracion de variables/contador
	int numBoats = 0;
	string prefix = "";

	//lectura del archivo 
	inFile >> numBoats >> prefix;

    //Creacion del vetor de la clase Boat.h para su manejo
	vector<Boat *> boats;

	//Parametros/variables 
	string date, hour, entry, UBI;

	//Ciclo for para recorrer y leer los archivos inputs
	for (int i = 0; i < numBoats; i++){
		inFile >> date >> hour >> entry >> UBI;
		if (UBI.substr(0, 3) == prefix)
			boats.push_back(new Boat(date, hour, entry, UBI));
	}

	//Algoritmo de ordenamiento para los datos (por fecha)
	mergeSort(boats);

	vector<Boat *> m;
	vector<Boat *> r;

	for (int i = 1; i < 13; i++){
		for (Boat *b : boats){
			if (stoi(b->date.substr(3, 2)) == i){
				if (b->entry == "M"){
					m.push_back(b);
				}
				else{
					r.push_back(b);
				}
			}
			if (stoi(b->date.substr(3, 2)) > i)
				break;
		}
		if (m.size() > 0 || r.size() > 0)
			outFile << dateArray(i) << endl;
		if (m.size() != 0){
			outFile << "M " << m.size() << ": ";
			for (Boat *b : m){
				outFile << b->UBI << " ";
			}
			outFile << endl;
		}
		if (r.size() != 0){
			outFile << "R " << r.size() << ": ";
			for (Boat *b : r){
				outFile << b->UBI << " ";
			}
			outFile << endl;
		}
		r.clear();
		m.clear();
	}
	return 0;
}