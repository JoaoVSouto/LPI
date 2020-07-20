#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
 private:
  std::string nome;

 public:
  Cliente();
  Cliente(std::string nome);

  void set_nome(std::string nome);
  std::string get_nome();
};

#endif  // !CLIENTE_H
