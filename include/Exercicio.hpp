#ifndef EXERCICIO_HPP 
#define EXERCICIO_HPP 
#include <string>

class Exercicio{
  protected:
    int id;
    std::string nome;
    bool ativo;
    static int proximoId;
  public:
    Exercicio(std::string name);
    Exercicio(int identifier, std::string name, bool active);

    virtual void _exibirExercicio() const = 0;
    virtual double _calcularTempo() const = 0;
    virtual double _calcularCalorias() const = 0;
    
    virtual int _getTipo() const = 0; // 1 = Cardio, 2 = Força
    int _getId() const;
    std::string _getNome() const;

    bool _estaAtivo() const;
    void _desativar();
    static void _atualizarProximoId(int biggestId);

    virtual ~Exercicio();
};

#endif 
