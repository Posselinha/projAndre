#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include "../include/json.hpp"
#include "../include/jsonUpdate.hpp"

using json = nlohmann::ordered_json;

const std::string PESSOAS_PATH = "./data/pessoas.json";

void alunoCadastrar(
    std::string nome,
    std::string cpf,
    std::string nascimento,
    std::string telefone,
    std::string email,
    std::string endereco,
    std::string numero_plano
);

void updateJson(std::string arquivo_path, json novo_dado);

void aluno();

void aluno()
{
    std::string nome, cpf, nascimento, telefone, email, endereco, numero_plano;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "CPF: ";
    std::getline(std::cin, cpf);

    std::cout << "Data de Nascimento (DD/MM/AAAA): ";
    std::getline(std::cin, nascimento);

    std::cout << "Telefone (ex: 19978129148): ";
    std::getline(std::cin, telefone);

    std::cout << "E-mail: ";
    std::getline(std::cin, email);

    std::cout << "Endereço (BAIRRO. RUA, NUMERO): ";
    std::getline(std::cin, endereco);

    std::cout << "Identificador da assinatura: ";
    std::getline(std::cin, numero_plano);

    std::cout << "\n";


    alunoCadastrar(nome, cpf, nascimento, telefone, email, endereco, numero_plano);
}

void alunoCadastrar(
    std::string nome,
    std::string cpf,
    std::string nascimento,
    std::string telefone,
    std::string email,
    std::string endereco,
    std::string numero_plano
) { 

    std::unordered_map<std::string, std::string> aluno_dados = {
        {"nome", nome},
        {"cpf", cpf},
        {"nascimento", nascimento},
        {"telefone", telefone},
        {"email", email},
        {"endereco", endereco},
        {"numero_plano", numero_plano}
    };

    std::vector<std::string> ordem = {
        "nome", "cpf", "nascimento", "telefone", "email", "endereco", "numero_plano"
    };

    json novaPessoa;

    for(const auto& chave : ordem) {
        novaPessoa[chave] = aluno_dados[chave];
    }

    updateJson(PESSOAS_PATH, novaPessoa);


}

