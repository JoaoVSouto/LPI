#ifndef CONTA_H
#define CONTA_H

#include <string>

#include "Agencia.h"
#include "Cliente.h"

class Conta {
 private:
  Cliente titular;
  Agencia agencia;
  std::string numero;
  double saldo;

 public:
  Conta();
  Conta(Cliente titular, Agencia agencia, std::string numero, double saldo);

  static int quantidade_contas;

  double sacar(double valor);
  double depositar(double valor);
  double transferir(double valor, Conta& conta);
  std::string to_string();

  void setTitular(Cliente titular);
  Cliente getTitular();
  void setAgencia(Agencia agencia);
  Agencia getAgencia();
  void setNumero(std::string numero);
  std::string getNumero();
  void setSaldo(double saldo);
  double getSaldo();
};

#endif  // !CONTA_H
