#include "../include/ClientePJ.h"

ClientePJ::ClientePJ() : Cliente(""), cnpj("") {}

ClientePJ::ClientePJ(std::string razao_social, std::string cnpj)
    : Cliente(razao_social), cnpj(cnpj) {
}

void ClientePJ::set_cnpj(std::string cnpj) {
  this->cnpj = cnpj;
}

std::string ClientePJ::get_cnpj() {
  return this->cnpj;
}
