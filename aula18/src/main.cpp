#include <iostream>

#include "../include/Agencia.h"
#include "../include/Caixa.h"
#include "../include/ClientePF.h"
#include "../include/ClientePJ.h"
#include "../include/Conta.h"
#include "../include/Fila.h"
#include "../include/Gerente.h"
#include "../include/Seguranca.h"
#include "./Fila.cpp"

int main() {
  Gerente gerente("Michael", "123.4-5", 2500, "Vendas");
  Caixa caixa("Lorem", "678.9-0", 2800, 33);
  Seguranca seguranca("Dwight", "333.3-0", 3500, true);

  std::cout << "Gerente" << std::endl;
  std::cout << "Nome: " << gerente.get_nome() << std::endl;
  std::cout << "Setor: " << gerente.get_setor() << std::endl;

  std::cout << "----" << std::endl;

  std::cout << "Caixa" << std::endl;
  std::cout << "Nome: " << caixa.get_nome() << std::endl;
  std::cout << "Número: " << caixa.get_numero() << std::endl;

  std::cout << "----" << std::endl;

  std::cout << "Segurança" << std::endl;
  std::cout << "Nome: " << seguranca.get_nome() << std::endl;
  std::cout << "Interno: " << std::boolalpha << seguranca.get_interno() << std::endl;

  return 0;
}
