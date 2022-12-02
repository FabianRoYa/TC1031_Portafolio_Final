// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yanez A01706636
// Date: 18/09/2022
//
// =================================================================
// Trate de hacer que las alidas quedaran lo mas parecidasposibles, pero no salieron iguales, hay algunas
// diferebncias en los archivos. 

#include <iostream>
#include "header.h"
#include "exception.h"
#include "merge.h"
#include "catch.h"
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  // usamos la libreria fstream para leer y escribir los archivos .txt 
  ifstream inputfile;
  ofstream outputfile;

  if(argc != 3){
    cout<< "Ingesa otros archivos de entrada." << endl; 
  }
  
  inputfile.open(argv[1]); // entrada a array
  if(inputfile.fail()){
    cout << "Error al leer el archivo" << endl;
    return -1;
  }

  outputfile.open(argv[2]);
  if(inputfile.fail()){
    cout << "No se puede escribir el archivo" << endl;
    return -1;
  }

//Declaracion de variables
  int num_ships;
  string id, date, hour, port, UBI;

  class Registro {
  public:
  int year, day, month;
  std::string date, UBI, port, hour;
  };

  std::vector < Registro > Registros;

// =================================================================
//Lectura de archivos
inputfile >> num_ships;
inputfile >> id;

// fucnion substr para el manejo de strings
for (int i = 0; i < num_ships; i++){
    inputfile >> date >> hour >> port >> UBI; 
    string day = date.substr(0, date.find("-")); 
    string month = date.substr(3, date.find("-"));
    string year = date.substr(6);
    size_t found = UBI.rfind(id); 
    // Stoi para convertir un string a un int
    if(found != string::npos){
    Registros.push_back({stoi(year), stoi(month),stoi(day), date, hour, port, UBI}); 
    }
  }

  mergeSortDay(Registros); 
  mergeSortMonth(Registros); 

// Escritura del archivo de salida
  for(int i = 0; i<Registros.size(); i++){
    outputfile << Registros[i].date << " " << Registros[i].hour << " " << Registros[i].port << " " << Registros[i].UBI << endl;
  }

return 0;
}

