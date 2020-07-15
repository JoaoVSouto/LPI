#include "../include/Cliente.h"

Cliente::Cliente() : nome(""), cpf("") {}

Cliente::Cliente(std::string nome, std::string cpf)
    : nome(nome), cpf(cpf) {
}

void Cliente::set_nome(std::string nome) {
  this->nome = nome;
}

std::string Cliente::get_nome() {
  return this->nome;
}

void Cliente::set_cpf(std::string cpf) {
  this->cpf = cpf;
}

std::string Cliente::get_cpf() {
  return this->cpf;
}
