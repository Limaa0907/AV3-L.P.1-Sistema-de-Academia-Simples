#ifndef CARDIO_HPP
#define CARDIO_HPP
#include "Exercicio.hpp"
#include <string>

class Cardio : public Exercicio{
  private:
    int duracao;
    double caloriasPorMinuto;
  public: 
    Cardio(std::string name, int duration, double calPerMinute);
    Cardio(int identifier, std::string name, bool active, int duration, double calPerMinute);

    void _exibirExercicio() const override;
    double _calcularTempo() const override;
    double _calcularCalorias() const override;
    
    int _getTipo() const override;
    int _getDuracao() const;
    double _getCaloriasPorMinuto() const;
};

#endif 
