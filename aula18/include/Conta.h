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

  double sacar(double valor);
  double depositar(double valor);
  double transferir(double valor, Conta& conta);
  std::string to_string();

  void set_titular(Cliente titular);
  Cliente get_titular();
  void set_agencia(Agencia agencia);
  Agencia get_agencia();
  void set_numero(std::string numero);
  std::string get_numero();
  void set_saldo(double saldo);
  double get_saldo();
};

#endif  // !CONTA_H
