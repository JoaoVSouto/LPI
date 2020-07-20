#ifndef GERENTE_H
#define GERENTE_H

#include <string>

#include "Funcionario.h"

class Gerente : public Funcionario {
 private:
  std::string setor;

 public:
  Gerente();
  Gerente(std::string nome, std::string id_cadastro, double salario, std::string setor);

  void set_setor(std::string setor);
  std::string get_setor();
};

#endif  // !GERENTE_H
