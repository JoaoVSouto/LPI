#include "../include/Cliente.h"

int Cliente::quantidade_clientes;

Cliente::Cliente() : nome(""), cpf("") {
  this->quantidade_clientes += 1;
}

Cliente::Cliente(std::string nome, std::string cpf)
    : nome(nome), cpf(cpf) {
  this->quantidade_clientes += 1;
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
