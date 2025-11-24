#include <iostream>
#include <fstream>
#include <cstdio>
#include "../include/login.hpp"
#include "../include/json.hpp"

using json = nlohmann::ordered_json;

const std::string ALUNOS_PATH = "./data/alunos.json";
const std::string INSTRUTOR_PATH = "./data/instrutor.json";

int checkDados(std::string cpf, std::string senha, std::string jsonPath);

void login(int choice) {
    std::string jsonPath = choice == 1 ? ALUNOS_PATH : INSTRUTOR_PATH;
    std::string loginMode = choice == 1 ? "ALUNO" : "INSTRUTOR";

    std::string cpf;
    std::string senha;

    std::cout << "\nVocê está fazendo LogIn como: " << loginMode << "\n\n";

    std::cout << "CPF (12345678900): ";
    std::getline(std::cin, cpf);

    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    if(checkDados(cpf, senha, jsonPath)) {
        std::cout << "Logado com sucesso!";
    }
}

int checkDados(std::string cpf, std::string senha, std::string jsonPath) {
    json dados;
    std::ifstream arquivo(jsonPath);
    if(arquivo.is_open()) {
        arquivo >> dados;
    }

    for (const auto& valor : dados) {
        if(valor.contains("cpf") && valor["cpf"] == cpf) {
            if (valor.contains("senha") && valor["senha"] == senha) {
                return 1;
            }
        }
    }

    return 0;

}

