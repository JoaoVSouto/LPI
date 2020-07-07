#include "../include/Cliente.h"

Cliente::Cliente() : nome(""), cpf("") {}

Cliente::Cliente(std::string nome, std::string cpf)
    : nome(nome), cpf(cpf) {
}

void Cliente::setNome(std::string nome) {
  this->nome = nome;
}

std::string Cliente::getNome() {
  return this->nome;
}

void Cliente::setCpf(std::string cpf) {
  this->cpf = cpf;
}

std::string Cliente::getCpf() {
  return this->cpf;
}
