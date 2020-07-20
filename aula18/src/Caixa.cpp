#include "../include/Caixa.h"

Caixa::Caixa() : numero(0), Funcionario("", "", 0) {}

Caixa::Caixa(std::string nome, std::string id_cadastro,
             double salario, unsigned numero)
    : numero(numero), Funcionario(nome, id_cadastro, salario) {}

void Caixa::set_numero(unsigned numero) {
  this->numero = numero;
}

unsigned Caixa::get_numero() {
  return this->numero;
}
