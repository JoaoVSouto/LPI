#include "../include/Funcionario.h"

Funcionario::Funcionario() : nome(""), id_cadastro("00.00-0"), salario(0) {}

Funcionario::Funcionario(std::string nome, std::string id_cadastro, double salario)
    : nome(nome), id_cadastro(id_cadastro), salario(salario) {}

void Funcionario::set_nome(std::string nome) {
  this->nome = nome;
}

std::string Funcionario::get_nome() {
  return this->nome;
}

void Funcionario::set_id_cadastro(std::string id_cadastro) {
  this->id_cadastro = id_cadastro;
}

std::string Funcionario::get_id_cadastro() {
  return this->id_cadastro;
}

void Funcionario::set_salario(double salario) {
  this->salario = salario;
}

double Funcionario::get_salario() {
  return this->salario;
}
