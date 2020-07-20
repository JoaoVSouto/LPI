#ifndef CAIXA_H
#define CAIXA_H

#include <string>

#include "Funcionario.h"

class Caixa : public Funcionario {
 private:
  unsigned numero;

 public:
  Caixa();
  Caixa(std::string nome, std::string id_cadastro, double salario, unsigned numero);

  void set_numero(unsigned numero);
  unsigned get_numero();
};

#endif  // !CAIXA_H
