#include "../include/Exercicio.hpp"
#include <string>

int Exercicio::proximoId = 1;

Exercicio::Exercicio(std::string name){
    nome = name;
    ativo = true;
    id = proximoId++;
}

Exercicio::Exercicio(int identifier, std::string name, bool active){
  id = identifier;
  nome = name;
  ativo = active; 

  if(id >= proximoId){
    proximoId = id + 1;
  }
}

Exercicio::~Exercicio(){}

int Exercicio::_getId() const{
  return id;
}

std::string Exercicio::_getNome() const{
  return nome;
}

bool Exercicio::_estaAtivo() const{
  return ativo;
}

void Exercicio::_desativar(){
  ativo = false;
}

void Exercicio::_atualizarProximoId(int biggestId){
  if(biggestId >= proximoId){
    proximoId = biggestId + 1;
  }
}

