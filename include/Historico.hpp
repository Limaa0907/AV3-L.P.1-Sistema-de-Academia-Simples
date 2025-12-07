#ifndef HISTORICO_HPP
#define HISTORICO_HPP
#include <string>
#include <vector>

struct Treino{
    std::string dataHora;
    int idFicha;
    std::string nomeFicha;
    double tempoTotal;
    double caloriasTotal;
};

class Historico{
  private:
    std::vector<Treino> registro_de_treinos;
  public:
    void _adicionarRegistro(const Treino& workout_register);
    void _exibirHistorico() const;

    const std::vector<Treino>& _getTreinos() const;
      
    void _carregarArquivo();
    void _salvarArquivo() const;
};

#endif 
