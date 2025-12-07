#ifndef FORCA_HPP
#define FORCA_HPP
#include "Exercicio.hpp"
#include <string>

class Forca : public Exercicio{ 
  private:
    double carga;
    int series;
    int repeticoes;
    int descanso;
  public:
    Forca(std::string name, double weight, int sets, int reps, int rest);
    Forca(int identifier, std::string name, bool active, double weight, int sets, int reps, int rest);

    void _exibirExercicio() const override;
    double _calcularTempo() const override;
    double _calcularCalorias() const override;
    
    int _getTipo() const override;
    double _getCarga() const;
    int _getSeries() const;
    int _getRepeticoes() const;
    int _getDescanso() const;
};

#endif 
