#ifndef SISTEMA_HPP
#define SISTEMA_HPP 
#include "Exercicio.hpp"
#include "Ficha.hpp"
#include "Historico.hpp"
#include <vector>

class Sistema{
  private:
    std::vector<Exercicio*> exercicios;
    std::vector<Ficha*> fichas;
    Historico historico;

    Exercicio* _buscarExercicioPorId(int identifier);
    Ficha* _buscarFichaPorId(int identifier);

  public:
    Sistema();
    ~Sistema();

    void _carregarDados();
    void _salvarDados();

    void _cadastrarExercicio();
    void _listarExercicios();
    void _excluirExercicio(); 

    void _criarFicha();
    void _deletarFicha(); 
    void _adicionarExercicioFicha();
    void _listarFichas();

    void _registrarTreino();
    void _exibirHistorico();
};

#endif
