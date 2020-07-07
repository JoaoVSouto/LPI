#include "../include/Agencia.h"

Agencia::Agencia() : nome(""), numero("") {
}

Agencia::Agencia(std::string nome, std::string numero)
    : nome(nome), numero(numero) {
}

void Agencia::setNome(std::string nome) {
  this->nome = nome;
}

std::string Agencia::getNome() {
  return this->nome;
}

void Agencia::setNumero(std::string numero) {
  this->numero = numero;
}

std::string Agencia::getNumero() {
  return this->numero;
}
