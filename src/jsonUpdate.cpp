#include "../include/jsonUpdate.hpp"
#include <iostream>
#include <fstream>

void updateJson(std::string arquivo_path, json novo_dado) {
    json conteudoJson;
    
    std::ifstream arquivo_in(arquivo_path);
    if(arquivo_in.is_open() && arquivo_in.peek() != std::ifstream::traits_type::eof()) {
        arquivo_in >> conteudoJson;
    } else {
        std::cout << "Arquivo vazio";
        conteudoJson = json::array();
    }

    arquivo_in.close();

    conteudoJson.push_back(novo_dado);

    std::ofstream arquivo_out(arquivo_path);

    if(arquivo_out.is_open()) {
        arquivo_out << conteudoJson.dump(4);
        arquivo_out.close();
    }
}