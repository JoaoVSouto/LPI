#include "../include/ClientePJ.h"

ClientePJ::ClientePJ() : razao_social(""), cnpj("") {}

ClientePJ::ClientePJ(std::string razao_social, std::string cnpj)
    : razao_social(razao_social), cnpj(cnpj) {
}

void ClientePJ::set_razao_social(std::string razao_social) {
  this->razao_social = razao_social;
}

std::string ClientePJ::get_razao_social() {
  return this->razao_social;
}

void ClientePJ::set_cnpj(std::string cnpj) {
  this->cnpj = cnpj;
}

std::string ClientePJ::get_cnpj() {
  return this->cnpj;
}
