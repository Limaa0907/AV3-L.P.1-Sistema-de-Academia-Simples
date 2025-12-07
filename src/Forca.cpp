#include "../include/Forca.hpp"
#include <iostream>
#include <string>

const int TEMPO_POR_REPETICAO = 3;

Forca::Forca(std::string name, double weight, int sets, int reps, int rest) : Exercicio(name){
  carga = weight;
  series = sets;
  repeticoes = reps;
  descanso = rest;
}

Forca::Forca(int identifier, std::string name, bool active, double weight, int sets, int reps, int rest): Exercicio(identifier, name, active){
  carga = weight;
  series = sets;
  repeticoes = reps;
  descanso = rest; 
}

void Forca::_exibirExercicio() const{
  std::string aux;
  aux = "Forca";
  
  std::cout << "\nEXERCICIO (" << aux << ")" << std::endl;
  std::cout << Exercicio::_getNome() << "(" << _getCarga() << ")" << std::endl;
  std::cout << "Series: " << _getSeries() << "x" << _getRepeticoes() << std::endl;
  std::cout << _getDescanso() << " segundos entre series" << std::endl;
  std::cout << "ID: " << _getId() << std::endl;
  std::cout << "Status: " << (_estaAtivo() ? "Ativo" : "Inativo") << std::endl;
}

double Forca::_calcularTempo() const{
  auto time = (series * repeticoes * TEMPO_POR_REPETICAO) + (series * descanso);
  time = time / 60;
  return time;
}

double Forca::_calcularCalorias() const{
  return series * repeticoes * carga * 0.15;
}

int Forca::_getTipo() const{
  return 2;
}

double Forca::_getCarga() const{
  return carga;
}

int Forca::_getSeries() const{
  return series;
}

int Forca::_getRepeticoes() const{
  return repeticoes;
}

int Forca::_getDescanso() const{
  return descanso;
}
