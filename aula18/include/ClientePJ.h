#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

#include "Cliente.h"

class ClientePJ : public Cliente {
 private:
  std::string cnpj;

 public:
  ClientePJ();
  ClientePJ(std::string razao_social, std::string cnpj);

  void set_cnpj(std::string cnpj);
  std::string get_cnpj();
};

#endif  // !CLIENTEPJ_H
