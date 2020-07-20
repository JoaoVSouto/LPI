#include "../include/Agencia.h"

Agencia::Agencia() : nome(""), numero("") {
}

Agencia::Agencia(std::string nome, std::string numero)
    : nome(nome), numero(numero) {
}

void Agencia::set_nome(std::string nome) {
  this->nome = nome;
}

std::string Agencia::get_nome() {
  return this->nome;
}

void Agencia::set_numero(std::string numero) {
  this->numero = numero;
}

std::string Agencia::get_numero() {
  return this->numero;
}
