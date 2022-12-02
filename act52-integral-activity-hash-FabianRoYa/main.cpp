// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yanez A01706636
// Date: 25/11/2022
//
// =================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv){
	if (argc != 3){
		cout<<argv[0]<<"Uso erroneo"<<endl;
		return -1;
	}

	ifstream input(argv[1], std::ios::in);
	if (!input.is_open()){
		cout<<"Error de lectura de archivo"<<endl;
		return -1;
	}

	ofstream output(argv[2], std::ios::out);
	if (!output.is_open()){
		cout<<"Error en la salida del archivo"<<endl;
		return -1;
	}

	int num_lines, num_jobs;
	input>>num_lines>>num_jobs;

	map<string, int> jobs;

	for (int i = 0; i < num_lines; i++){
		string job;
		int time;

		input>>job>>time;
		jobs[job] = time;
	}
	for (int i = 0; i < num_jobs; i++){
		string job;
		int weight = 0;
		while (input >> job){
			if (job == ".")
				break;
			weight += jobs[job];
		}
		output<<weight<<endl;
	}
	input.close();
	output.close();
}