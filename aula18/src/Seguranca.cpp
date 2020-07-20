#include "../include/Seguranca.h"

Seguranca::Seguranca() : interno(false), Funcionario("", "", 0) {}

Seguranca::Seguranca(std::string nome, std::string id_cadastro,
                     double salario, bool interno)
    : interno(interno), Funcionario(nome, id_cadastro, salario) {}

void Seguranca::set_interno(bool interno) {
  this->interno = interno;
}

bool Seguranca::get_interno() {
  return this->interno;
}
