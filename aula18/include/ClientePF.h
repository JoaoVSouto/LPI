#ifndef CLIENTEPF_H
#define CLIENTEPF_H

#include <string>

#include "Cliente.h"

class ClientePF : public Cliente {
 private:
  std::string cpf;

 public:
  ClientePF();
  ClientePF(std::string nome, std::string cpf);

  void set_cpf(std::string cpf);
  std::string get_cpf();
};

#endif  // !CLIENTEPF_H
