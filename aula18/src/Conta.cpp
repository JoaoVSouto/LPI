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

  return "Titular: " + this->titular.get_nome() +
         "\nNúmero: " + this->numero +
         "\nSaldo: R$ " + stream.str();
}

void Conta::set_titular(Cliente titular) {
  this->titular = titular;
}

Cliente Conta::get_titular() {
  return this->titular;
}

void Conta::set_agencia(Agencia agencia) {
  this->agencia = agencia;
}

Agencia Conta::get_agencia() {
  return this->agencia;
}

void Conta::set_numero(std::string numero) {
  this->numero = numero;
}

std::string Conta::get_numero() {
  return this->numero;
}

void Conta::set_saldo(double saldo) {
  this->saldo = saldo;
}

double Conta::get_saldo() {
  return this->saldo;
}
