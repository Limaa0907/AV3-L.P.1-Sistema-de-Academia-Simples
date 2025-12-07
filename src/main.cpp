#include "../include/Sistema.hpp"
#include "../include/Utils.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    Sistema sis;
    int opc;

    while(true){
        _limparTela();

        std::cout << "Ola, seja bem vindo! :)\n";
        std::cout << "\n[======= ACADEMIA =======]\n";
        std::cout << "[1] - Cadastrar exercício\n";
        std::cout << "[2] - Listar exercícios\n";
        std::cout << "[3] - Desativar exercício\n";
        std::cout << "[4] - Criar ficha\n";
        std::cout << "[5] - Adicionar exercício à ficha\n";
        std::cout << "[6] - Listar fichas\n";
        std::cout << "[7] - Remover ficha\n";
        std::cout << "[8] - Registrar treino\n";
        std::cout << "[9] - Exibir histórico\n";
        std::cout << "[0] - Sair\n";
        std::cout << "\n-> Escolha: ";
        std::cin >> opc;

        switch(opc){
            case 1: sis._cadastrarExercicio(); break;
            case 2: sis._listarExercicios(); break;
            case 3: sis._excluirExercicio(); break;
            case 4: sis._criarFicha(); break;
            case 5: sis._adicionarExercicioFicha(); break;
            case 6: sis._listarFichas(); break;
            case 7: sis._deletarFicha(); break;
            case 8: sis._registrarTreino(); break;
            case 9: sis._exibirHistorico(); break;
            case 0:
                _limparTela();
                std::cout << "Saindo...\nObrigado, volte sempre! :)\n";
                return 0;

            default:
                std::cout << "Opção inválida!\n";
                break;
        }

        std::cout << "\nPressione ENTER para continuar...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}
