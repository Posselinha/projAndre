#include <iostream>
#include <string>
#include <array>

void alunoCadastrar(
    std::string nome,
    std::string cpf,
    std::string nascimento,
    std::string telefone,
    std::string email,
    std::string endereco,
    std::string numero_plano
);

int main()
{
    std::string nome, cpf, nascimento, telefone, email, endereco, numero_plano;

    std::cout << "Nome: ";
    std::cin >> nome;

    std::cout << "CPF: ";
    std::cin >> cpf;

    std::cout << "Data de Nascimento (DD/MM/AAAA): ";
    std::cin >> nascimento;

    std::cout << "Telefone (ex: 19978129148): ";
    std::cin >> telefone;

    std::cout << "E-mail: ";
    std::cin >> email;

    std::cout << "Endereço (BAIRRO. RUA, NUMERO): ";
    std::cin >> endereco;

    std::cout << "Identificador da assinatura: ";
    std::cin >> numero_plano;


    alunoCadastrar(nome, cpf, nascimento, telefone, email, endereco, numero_plano);
    return 0;
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

    std::array<std::string, 7> aluno_dados = {
        nome,
        cpf,
        nascimento,
        telefone,
        email,
        endereco,
        numero_plano
    };

    std::cout << aluno_dados.at(0);
    std::cout << aluno_dados.at(1);
    std::cout << aluno_dados.at(2);
    std::cout << aluno_dados.at(3);
    std::cout << aluno_dados.at(4);
    std::cout << aluno_dados.at(5);
    std::cout << aluno_dados.at(6);
    
}