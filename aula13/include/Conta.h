#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta {
 private:
  int numero;
  double saldo;
  std::string titular;

 public:
  Conta();
  Conta(int numero, double saldo, std::string titular);

  double sacar(double valor);
  double depositar(double valor);
  double transferir(double valor, Conta& conta);
  std::string to_string();

  void setNumero(int numero);
  int getNumero();
  void setSaldo(double saldo);
  double getSaldo();
  void setTitular(std::string titular);
  std::string getTitular();
};

#endif  // !CONTA_H
