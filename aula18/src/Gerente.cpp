#include "../include/Gerente.h"

Gerente::Gerente() : setor(""), Funcionario("", "", 0) {}

Gerente::Gerente(std::string nome, std::string id_cadastro,
                 double salario, std::string setor)
    : setor(setor), Funcionario(nome, id_cadastro, salario) {}

void Gerente::set_setor(std::string setor) {
  this->setor = setor;
}

std::string Gerente::get_setor() {
  return this->setor;
}
