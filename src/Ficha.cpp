#include "../include/Ficha.hpp"
#include <iostream>
#include <string>
#include <vector>

int Ficha::proximoId = 1;

Ficha::Ficha(std::string name){
  nome = name;
  id = proximoId++;
}

Ficha::Ficha(int identifier, std::string name){
  nome = name;
  id = identifier;

  if(id >= proximoId){
    proximoId = id + 1;
  }
}

void Ficha::_adicionarExercicio(Exercicio* exercise){
  exercicios.push_back(exercise);
}

void Ficha::_exibirFicha() const{
  std::cout << "\nFICHA\n";
  std::cout << nome << "\n";
  std::cout << "ID: " << id << "\n";
  std::cout << "Total de exercícios: " << exercicios.size() << "\n\n";

  if(exercicios.empty()){
    std::cout << "Nenhum exercício nesta ficha.\n";
    return;
  }
}

void Ficha::_exibirExercicios(){    
  std::cout << "===== Exercicios da Ficha =====\n";
  for(auto e : exercicios){
    e->_exibirExercicio();  
  }
}

double Ficha::_calcularTempoTotal() const{
  double total = 0.0;
  for(const auto& e : exercicios){
    total += e->_calcularTempo();
  }
  return total;
}

double Ficha::_calcularCaloriasTotais() const{
  double total = 0.0;
  for(const auto& e : exercicios){
    total += e->_calcularCalorias();
  }
  return total;
}

int Ficha::_getId() const{
  return id;
}

std::string Ficha::_getNome() const{
  return nome;
}

const std::vector<Exercicio*>& Ficha::_getExercicios() const{
  return exercicios;
}

void Ficha::_atualizarProximoId(int biggestId){
  if(biggestId >= proximoId){
    proximoId = biggestId + 1;
  }
}

Ficha::~Ficha(){ 
  exercicios.clear();
}
