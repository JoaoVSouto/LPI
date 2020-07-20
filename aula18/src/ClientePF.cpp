#include "../include/ClientePF.h"

ClientePF::ClientePF() : Cliente(""), cpf("") {}

ClientePF::ClientePF(std::string nome, std::string cpf)
    : Cliente(nome), cpf(cpf) {
}

void ClientePF::set_cpf(std::string cpf) {
  this->cpf = cpf;
}

std::string ClientePF::get_cpf() {
  return this->cpf;
}
