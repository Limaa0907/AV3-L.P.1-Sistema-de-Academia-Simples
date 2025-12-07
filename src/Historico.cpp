#include "../include/Historico.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void Historico::_adicionarRegistro(const Treino& workout_register){
  registro_de_treinos.push_back(workout_register);
}

void Historico::_exibirHistorico() const{
  for(const auto& r : registro_de_treinos){
    std::cout << r.nomeFicha << std::endl;
    std::cout << "ID da ficha: " << r.idFicha << std::endl;
    std::cout << "Duracao do treino: " << r.tempoTotal << std::endl;
    std::cout << "Gasto calorico do treino: " << r.caloriasTotal << std::endl << std::endl;
  }
}

const std::vector<Treino>& Historico::_getTreinos() const{
  return registro_de_treinos;
}
  
void Historico::_carregarArquivo(){
  std::ifstream arquivo("HISTORICO.txt");
  if(!arquivo.is_open()){
    std::cerr << "Erro ao abrir arquivo :(" << std::endl;
    return;
  }

  registro_de_treinos.clear();  
  std::string linha;
  while(getline(arquivo, linha)){
    if(linha.empty()){ continue; }
    std::stringstream ss(linha);
    Treino r;
    std::string temp;

    getline(ss, r.dataHora, ';');

    getline(ss, temp, ';');
    r.idFicha = stoi(temp);

    getline(ss, r.nomeFicha, ';');

    getline(ss, temp, ';');
    r.tempoTotal = stod(temp);

    getline(ss, temp, ';');
    r.caloriasTotal = stod(temp);

    registro_de_treinos.push_back(r);
  }
  arquivo.close();
}

void Historico::_salvarArquivo() const{
  std::ofstream arquivo("HISTORICO.txt");
  if(!arquivo.is_open()){
    std::cerr << "Erro ao abrir arquivo :(" << std::endl;
    return;
  }

  for(const auto& r : registro_de_treinos){
    arquivo << r.dataHora << ";" << r.idFicha << ";" << r.nomeFicha 
            << ";" << r.tempoTotal << ";" << r.caloriasTotal << std::endl;
  }
  arquivo.close();
}
