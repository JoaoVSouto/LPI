#ifndef AGENCIA_H
#define AGENCIA_H

#include <string>

class Agencia {
 private:
  std::string nome;
  std::string numero;

 public:
  Agencia();
  Agencia(std::string nome, std::string numero);

  void set_nome(std::string nome);
  std::string get_nome();
  void set_numero(std::string numero);
  std::string get_numero();
};

#endif  // !AGENCIA_H
