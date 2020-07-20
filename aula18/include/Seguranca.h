#ifndef SEGURANCA_H
#define SEGURANCA_H

#include <string>

#include "Funcionario.h"

class Seguranca : public Funcionario {
 private:
  bool interno;

 public:
  Seguranca();
  Seguranca(std::string nome, std::string id_cadastro, double salario, bool interno);

  void set_interno(bool interno);
  bool get_interno();
};

#endif  // !SEGURANCA_H
