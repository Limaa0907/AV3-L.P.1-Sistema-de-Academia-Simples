#include "../include/Sistema.hpp"
#include "../include/Cardio.hpp"
#include "../include/Forca.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <vector>
#include <string>


Sistema::Sistema(){
  _carregarDados();
}

Exercicio* Sistema::_buscarExercicioPorId(int identifier){
  for(auto e : exercicios){
    if(e->_getId() == identifier){
      return e;
    }
  }
  return nullptr;
}

Ficha* Sistema::_buscarFichaPorId(int identifier){
  for(auto f : fichas){
    if(f->_getId() == identifier){
      return f;
    }
  }
  return nullptr;
}

void Sistema::_carregarDados(){
  std::ifstream arquivo1("EXERCICIOS.txt");
  if(!arquivo1.is_open()){
    std::cerr << "Erro ao abrir arquivo :(" << std::endl;
    return;
  }

  std::string linha;
  while(getline(arquivo1, linha)){
    if(linha.empty()){ continue; }
    std::stringstream ss(linha);
    std::string nome;
    std::string parte;
    int tipo;
    int id;
    int ativo;

    getline(ss, parte, ';');

    std::cout << "[EX] Parte tipo = '" << parte << "'" << std::endl;
    tipo = std::stoi(parte);

    getline(ss, parte, ';');
   
    std::cout << "[EX] Parte id = '" << parte << "'" << std::endl;
    id = std::stoi(parte);
    
    getline(ss, nome, ';');

    getline(ss, parte, ';');
   
    std::cout << "[EX] Parte ativo = '" << parte << "'" << std::endl;
    ativo = std::stoi(parte);

    if(tipo == 1){
      std::string d, c;

      getline(ss, d, ';');
      getline(ss, c, ';');
      
      Exercicio* e = new Cardio(id, nome, ativo == 1, std::stoi(d), std::stod(c));
      exercicios.push_back(e);
    } 
    else{
      std::string c, s, r, d;

      getline(ss, c, ';');
      getline(ss, s, ';');
      getline(ss, r, ';');
      getline(ss, d, ';');
      
      Exercicio* e = new Forca(id, nome, ativo == 1, std::stod(c), std::stoi(s), std::stoi(r), std::stoi(d));
      exercicios.push_back(e);
    }
  }
  arquivo1.close();
  
  std::ifstream arquivo2("FICHAS.txt");
  if(!arquivo2.is_open()){
    std::cerr << "Erro ao abrir arquivo :(" << std::endl;
    return;
  }

  while(getline(arquivo2, linha)){
    if(linha.empty()){ continue; }
    std::stringstream ss(linha);
    std::string parte;
    std::string nome;
    int id;
            
    getline(ss, parte, ';');


    std::cout << "[FI] Parte id ficha = '" << parte << "'" << std::endl;
    id = std::stoi(parte);
    
    getline(ss, nome, ';');
    Ficha* f = new Ficha(id, nome);

    if(getline(ss, parte, ';')){
      std::stringstream ids(parte);
      std::string x;

      std::cout << "[FI] Parte lista exercicios bruta = '" << parte << "'" << std::endl;
      while(getline(ids, x, ';')){
        if(x.empty()){ continue; }      
        int ide = std::stoi(x);
        Exercicio* e = _buscarExercicioPorId(ide);
        if(e){ f->_adicionarExercicio(e); }
      }
    }
    fichas.push_back(f);
  }
  arquivo2.close();
  historico._carregarArquivo();
} 

void Sistema::_salvarDados(){
 std::ofstream arquivo1("EXERCICIOS.txt");
  for(Exercicio* e : exercicios){
    int tipo = e->_getTipo();
    arquivo1 << tipo << ";" << e->_getId() << ";"  
             << e->_getNome() << ";" << (e->_estaAtivo() ? 1 : 0) << ";";
    if(tipo == 1){
      Cardio* c = dynamic_cast<Cardio*>(e);
      arquivo1 << c->_getDuracao() << ";" << c->_getCaloriasPorMinuto() << "\n";
    } 
    else{
      Forca* f = dynamic_cast<Forca*>(e);
      arquivo1 << f->_getCarga() << ";" 
               << f->_getSeries() << ";" 
               << f->_getRepeticoes() << ";" 
               << f->_getDescanso() << "\n";
    }
  }
  arquivo1.close();

  std::ofstream arquivo2("FICHAS.txt");
  for(Ficha* f : fichas){
    arquivo2 << f->_getId() << ";" << f->_getNome() << ";" << f->_getExercicios().size() << ";";
    std::vector<Exercicio*> lista = f->_getExercicios();
    
    for(size_t i = 0; i < lista.size(); i++){
      arquivo2 << lista[i]->_getId();
      
      if(i + 1 < lista.size()){
        arquivo2 << ";";
      }
    }
    arquivo2 << "\n";
  }
  arquivo2.close();
  historico._salvarArquivo();
}

void Sistema::_cadastrarExercicio(){
  _limparTela();
  int input;
  std::string nome;

  std::cout << "========== CADASTRO DE EXERCICIO ==========" << std::endl;
  std::cout << "Qual exercicio deseja cadastrar?" << std::endl;
  std::cout << "[1] - Exercicio de Cardio" << std::endl;
  std::cout << "[2] - Exercicio de Forca" << std::endl;
  std::cout << "[0] - Sair" << std::endl; 
  std::cout << "-> Escolha: ";
  std::cin >> input;

  if(input == 0){ return; }

  if(input == 1){
    _limparTela();
    int duracao;
    double calPorMinuto;

    std::cout << "=== Digite as informacoes do exercicio ===" << std::endl;
    std::cout << "Nome do Exercicio: ";
    std::cin.ignore();
    getline(std::cin, nome);

    std::cout << "Duracao do Exercicio (min): ";
    std::cin >> duracao;

    std::cout << "Gasto calorico (cal/min): ";
    std::cin >> calPorMinuto;

    Exercicio* e = new Cardio(nome, duracao, calPorMinuto);
    exercicios.push_back(e);

    std::cout << "\nExercicio Cadastrado com Sucesso!" << std::endl;
  }
  else if(input == 2){
    _limparTela();
    double peso; 
    int series;
    int repeticoes;
    int descanso;

    std::cout << "=== Digite as informacoes do exercicio ===" << std::endl;
    std::cout << "Nome do Exercicio: ";
    std::cin.ignore();
    getline(std::cin, nome);

    std::cout << "Carga utilizada (KG): ";
    std::cin >> peso;

    std::cout << "Series realizadas: ";
    std::cin >> series;

    std::cout << "Numero de repeticoes por serie: ";
    std::cin >> repeticoes;

    std::cout << "Descanso entre series (s): ";
    std::cin >> descanso;

    Exercicio* e = new Forca(nome, peso, series, repeticoes, descanso);
    exercicios.push_back(e);

    std::cout << "\nExercicio Cadastrado com Sucesso!" << std::endl;
  }
  else{
    std::cout << "Tipo de exercicio invalido!" << std::endl;
  }

}

void Sistema::_listarExercicios(){
  _limparTela();
  std::cout << "========== LISTA DE EXERCICIO(S) ATIVOS ==========" << std::endl;  for(auto e : exercicios){
    if(e->_estaAtivo()){
      e->_exibirExercicio();
    }
  }
}

void Sistema::_excluirExercicio(){
  _limparTela();
  std::cout << "========== DESATIVACAO DE EXERCICIO ==========" << std::endl; 
  int id;
  std::cout << "Insira o ID do exercicio: ";
  std::cin >> id;
  auto e = _buscarExercicioPorId(id);
  
  if(e != nullptr && e->_estaAtivo() == true){
    e->_exibirExercicio();
    std::cout << "\nExercicio encontrado! Deseja desativar?" << std::endl;
    std::cout << "-> Escolha (S/N): ";
    char input;
    std::cin >> input;
    if(input == 'S'){
      e->_desativar();
      std::cout << "Exercicio desativado!" << std::endl;
    }
    else if(input == 'N'){
      std::cout << "Ok! O exercicio nao foi desativado!" << std::endl;
      return;
    }
    else{
      std::cout << "Valor inserido invalido!" << std::endl;
      return;
    }
  }
  else{
    std::cout << "Exercicio nao encontrado ou ja esta inativo :(" << std::endl;
  }
}

void Sistema::_criarFicha(){
  _limparTela();
  std::string nome;
  std::cout << "Insira o nome da sua nova ficha!" << std::endl;
  
  std::cin.ignore();
  getline(std::cin, nome);
  Ficha* f = new Ficha(nome);
  fichas.push_back(f);
  
  std::cout << "Ficha criada com sucesso!" << std::endl;
  /*std::cout << "Deseja adicionar exercicios ja cadastrados?" << std::endl;
  char input;
  std::cout << "\n-> Escolha (S/N): ";
  std::cin >> input;
  if(input == 'S'){
    std::cout << "Exercicios disponiveis!";
    _listarExercicios(); 
    std::cout << 
  }
  else if(input == 'N'){
    std::cout << "Ok! Ficha de treino criada com sucesso!" << std::endl;
    return;
  }
  else{
    std::cout << "Valor inserido invalido!" << std::endl;
    return;
  }*/
}

void Sistema::_deletarFicha(){
  _limparTela();
  std::cout << "========== REMOÇÃO DE FICHA ==========" << std::endl; 
  int id;
  std::cout << "Insira o ID da ficha que deseja deletar (0 para voltar): ";
  
  std::cin >> id;
  if(id == 0){
    return;
  }
  for(size_t i = 0; i < fichas.size(); i++){
    if(fichas[i]->_getId() == id){
      std::cout << "Ficha encontrada:\n";
      fichas[i]->_exibirFicha();
      
      char op;
      std::cout << "\nTem certeza que deseja deletar esta ficha? (S/N): ";
      std::cin >> op;
      
      if(op == 'S' || op == 's'){
        delete fichas[i];  
        fichas.erase(fichas.begin() + i);
        std::cout << "\nFicha deletada com sucesso!\n";
        _salvarDados(); 
        return;
      }
      else{
        std::cout << "Operação cancelada.\n";
        return;
      }
    }
  }
  std::cout << "Nenhuma ficha com esse ID foi encontrada.\n"; 
}

void Sistema::_adicionarExercicioFicha(){
  _limparTela();
  int id;
  std::cout << "Insira o ID da ficha: ";
  std::cin >> id;
  auto f = _buscarFichaPorId(id);

  _limparTela();
  if(f != nullptr){
    std::cout << "Ficha Encontrada!" << std::endl;
    f->_exibirFicha();
  }
  else{
    std::cout << "Ficha nao encontrado :(" << std::endl;
    return;
  }

  std::cout << "\n====== Exercicios disponiveis ======\n";
  for(Exercicio* e : exercicios){
    if(e->_estaAtivo()){
      e->_exibirExercicio();
    }
  }
  int idAux;
  std::cout << "\n-> Insira o ID do exercicio a ser adicionado (0 para voltar): ";
  std::cin >> idAux;

  if(idAux == 0){ return; }

  Exercicio* ex = _buscarExercicioPorId(idAux);
  if(ex == nullptr){
    std::cout << "Exercicio nao encontrado!" << std::endl;
    return;
  }

  if(!ex->_estaAtivo()){
    std::cout << "Nao eh possível adicionar um exercício desativado!" << std::endl;
    return;
  }

  f->_adicionarExercicio(ex);
  std::cout << "Exercicio adicionado com sucesso!" << std::endl;
}

void Sistema::_listarFichas(){
  _limparTela();

  if(fichas.empty()){
    std::cout << "Nenhuma ficha cadastrada!\n";
    return;
  }

  for(auto f : fichas){
    std::cout << "FICHA: " << f->_getNome() << " || ID: " << f->_getId() << std::endl;
  }

  std::cout << "Digite o ID da ficha que deseja listar (0 para voltar): ";
  int input;
  std::cin >> input;
  
  if(input == 0){ return; }

  auto ficha = _buscarFichaPorId(input);
  if(ficha == nullptr){ 
    std::cout << "Ficha nao encontrada! " << std::endl;
    return;
  }
  
  _limparTela();
  std::cout << "=== FICHA SELECIONADA ===" << std::endl;
  ficha->_exibirFicha();
  ficha->_exibirExercicios();
}

void Sistema::_registrarTreino(){
    _limparTela();
    _listarFichas();
    
    std::cout << "Digite o ID da ficha realizada: ";
    int id;
    std::cin >> id;

    Ficha* ficha = _buscarFichaPorId(id);
    if (ficha == nullptr){
        std::cout << "Ficha nao encontrada!" << std::endl;
        return;
    }

    double tempoTotal = ficha->_calcularTempoTotal();
    double caloriasTotal = ficha->_calcularCaloriasTotais();

    Treino r;
    r.idFicha = ficha->_getId();
    r.nomeFicha = ficha->_getNome();
    r.dataHora = _getDataHoraAtual(); 
    r.tempoTotal = tempoTotal;
    r.caloriasTotal = caloriasTotal;

    historico._adicionarRegistro(r);

    std::cout << "Treino registrado com sucesso!" << std::endl;
}

void Sistema::_exibirHistorico(){
  _limparTela();
  historico._exibirHistorico();
}

Sistema::~Sistema(){  
  _salvarDados();

  for(auto e : exercicios){
    delete e;
  }
  for(auto f : fichas){
    delete f;
  }
}
