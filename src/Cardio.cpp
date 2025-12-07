#include "../include/Cardio.hpp"
#include <iostream>
#include <string>

Cardio::Cardio(std::string name, int duration, double calPerMinute) : Exercicio(name){
  duracao = duration;
  caloriasPorMinuto = calPerMinute;
}

Cardio::Cardio(int identifier, std::string name, bool active, int duration, double calPerMinute) : Exercicio(identifier, name, active){
  duracao = duration;
  caloriasPorMinuto = calPerMinute;
}

void Cardio::_exibirExercicio() const{
  std::string aux;
  aux = "Cardio";

  std::cout << "\nEXERCICIO (" << aux << ")" << std::endl;
  std::cout << Exercicio::_getNome() << std::endl;
  std::cout << "ID: " << _getId() << std::endl;
  std::cout << "Status: " << (_estaAtivo() ? "Ativo" : "Inativo") << std::endl;
  std::cout << "Duracao: " << _getDuracao() << std::endl;
  std::cout << "Gasto Calorico: " << _getCaloriasPorMinuto() << std::endl;
}

double Cardio::_calcularTempo() const{
  return duracao;
}

double Cardio::_calcularCalorias() const{
  return duracao * caloriasPorMinuto;
}   

int Cardio::_getTipo() const{
  return 1;
}

int Cardio::_getDuracao() const{
  return duracao;
}

double Cardio::_getCaloriasPorMinuto() const{
  return caloriasPorMinuto;
}

