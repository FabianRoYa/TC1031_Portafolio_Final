// =================================================================
//
// File: main.cpp
// Author: Fabian Erubiel Rojas Yanez A01706636 
// Date: 12/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>

#include "Ugraph.cpp"

int main(int argc, char **argv){
    if (argc != 3){
        std::cout << argv[0] << "Invocacion Incorrecta"
                  << std::endl;
        return 1;
    }

    std::fstream input_file(argv[1], std::ios::in);
    if (!input_file.is_open()){
        std::cout << "No se puede abrir el archivo de  entrada." << std::endl;
        return 1;
    }

    std::fstream output_file(argv[2], std::ios::out);
    if (!output_file.is_open()){
        std::cout << "No se puede escribir el archivo de salida" << std::endl;
        return 1;
    }

    int size{};
    input_file >> size;

    std::string port_1{}, port_2{};
    UGraph<std::string> graph;

    for (int i = 0; i < size; i++){
        input_file >> port_1 >> port_2;
        graph.add_edge(port_1, port_2);
    }

    int num_queries{};
    input_file >> num_queries;

    int count{}, query_mnp{};
    std::string mnp_port{};

    for (int i = 0; i < num_queries; i++){
        input_file >> mnp_port >> query_mnp;
        graph.get_mnp()[mnp_port] = query_mnp;
        graph.bfs(mnp_port);

        for (auto &port : graph.get_distance())
            if (port.second > query_mnp)
                count++;

        output_file << "Case " << i + 1 << ": "
                    << count << " ports not reachable from port "
                    << mnp_port << " with MNP = " << query_mnp
                    << "." << std::endl;

        // reset
        count = 0;
        graph.reset();
    }
}