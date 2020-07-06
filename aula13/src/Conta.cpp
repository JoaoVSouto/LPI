#include "../include/Conta.h"

#include <iomanip>
#include <sstream>

Conta::Conta() : numero(0), saldo(0), titular("") {
}

Conta::Conta(int numero, double saldo, std::string titular)
    : numero(numero), saldo(saldo), titular(titular) {
}

double Conta::sacar(double valor) {
  this->saldo -= valor;
  return this->saldo;
}

double Conta::depositar(double valor) {
  this->saldo += valor;
  return this->saldo;
}

double Conta::transferir(double valor, Conta& conta) {
  conta.depositar(valor);
  return this->sacar(valor);
}

std::string Conta::to_string() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << this->saldo;

  return "Titular: " + this->titular +
         "\nNúmero: " + std::to_string(this->numero) +
         "\nSaldo: R$ " + stream.str();
}

void Conta::setNumero(int numero) {
  this->numero = numero;
}

int Conta::getNumero() {
  return this->numero;
}

void Conta::setSaldo(double saldo) {
  this->saldo = saldo;
}

double Conta::getSaldo() {
  return this->saldo;
}

void Conta::setTitular(std::string titular) {
  this->titular = titular;
}

std::string Conta::getTitular() {
  return this->titular;
}
