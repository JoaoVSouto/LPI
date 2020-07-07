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

  void setNome(std::string nome);
  std::string getNome();
  void setCpf(std::string cpf);
  std::string getCpf();
};

#endif  // !CLIENTE_H
