#ifndef FICHA_HPP
#define FICHA_HPP
#include "Exercicio.hpp"
#include <string>
#include <vector>

class Ficha{
  private:
    int id;
    std::string nome;
    std::vector<Exercicio*> exercicios;
    static int proximoId;
  public:
    Ficha(std::string name);
    Ficha(int identifier, std::string name);

    void _adicionarExercicio(Exercicio* exercise);
    void _exibirFicha() const;
    void _exibirExercicios();  

    double _calcularTempoTotal() const;
    double _calcularCaloriasTotais() const;
    
    int _getId() const;
    std::string _getNome() const;
    const std::vector<Exercicio*>& _getExercicios() const;
    
    static void _atualizarProximoId(int biggestId);

    ~Ficha();
};

#endif 
