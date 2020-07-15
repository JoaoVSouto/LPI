#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
 private:
  std::string nome;
  std::string cpf;

 public:
  Cliente();
  Cliente(std::string nome, std::string cpf);

  void set_nome(std::string nome);
  std::string get_nome();
  void set_cpf(std::string cpf);
  std::string get_cpf();
};

#endif  // !CLIENTE_H
