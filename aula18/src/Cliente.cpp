#include "../include/Cliente.h"

Cliente::Cliente() : nome("") {}

Cliente::Cliente(std::string nome) : nome(nome) {}

void Cliente::set_nome(std::string nome) {
  this->nome = nome;
}

std::string Cliente::get_nome() {
  return this->nome;
}
