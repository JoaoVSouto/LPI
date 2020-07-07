#include "../include/Conta.h"

#include <iomanip>
#include <sstream>

Conta::Conta() : titular(), agencia(), numero(""), saldo(0) {
}

Conta::Conta(Cliente titular, Agencia agencia, std::string numero, double saldo)
    : titular(titular), agencia(agencia), numero(numero), saldo(saldo) {
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

  return "Titular: " + this->titular.getNome() +
         "\nNúmero: " + this->numero +
         "\nSaldo: R$ " + stream.str();
}

void Conta::setTitular(Cliente titular) {
  this->titular = titular;
}

Cliente Conta::getTitular() {
  return this->titular;
}

void Conta::setAgencia(Agencia agencia) {
  this->agencia = agencia;
}

Agencia Conta::getAgencia() {
  return this->agencia;
}

void Conta::setNumero(std::string numero) {
  this->numero = numero;
}

std::string Conta::getNumero() {
  return this->numero;
}

void Conta::setSaldo(double saldo) {
  this->saldo = saldo;
}

double Conta::getSaldo() {
  return this->saldo;
}
