#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

class ClientePJ {
 private:
  std::string razao_social;
  std::string cnpj;

 public:
  ClientePJ();
  ClientePJ(std::string razao_social, std::string cnpj);

  void set_razao_social(std::string razao_social);
  std::string get_razao_social();
  void set_cnpj(std::string cnpj);
  std::string get_cnpj();
};

#endif  // !CLIENTEPJ_H
