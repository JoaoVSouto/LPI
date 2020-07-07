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

  void setNome(std::string nome);
  std::string getNome();
  void setNumero(std::string numero);
  std::string getNumero();
};

#endif  // !AGENCIA_H
