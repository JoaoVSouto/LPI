#include <iostream>

#include "../include/Agencia.h"
#include "../include/Cliente.h"
#include "../include/Conta.h"

int main() {
  Cliente cliente1("João", "937.832.313-73");
  Agencia agencia1("Caixa", "8392");
  Conta conta1(cliente1, agencia1, "83712-3", 10000);

  std::cout << "Conta 1:\n"
            << std::endl;

  std::cout << conta1.to_string() << std::endl;

  std::cout << "\n----\nConta 1 | Sacando 7000:\n"
            << std::endl;

  conta1.sacar(7000);
  std::cout << conta1.to_string() << std::endl;

  std::cout << "\n----\nConta 1 | Depositando 1500:\n"
            << std::endl;

  conta1.depositar(1500);
  std::cout << conta1.to_string() << std::endl;

  Cliente cliente2("Pedro", "783.003.837-60");
  Agencia agencia2("Banco do Brasil", "29178");
  Conta conta2(cliente2, agencia2, "29833-3", 27500);

  std::cout << "\n----\nConta 2:\n"
            << std::endl;

  std::cout << conta2.to_string() << std::endl;

  std::cout << "\n----\nTransferindo 2000 da Conta 1 para Conta 2:\n"
            << std::endl;

  conta1.transferir(2000, conta2);
  std::cout << "Conta 1:\n"
            << std::endl;
  std::cout << conta1.to_string() << std::endl;
  std::cout << "\nConta 2:\n"
            << std::endl;
  std::cout << conta2.to_string() << std::endl;

  std::cout << "\n----\nTransferindo 10500 da Conta 2 para Conta 1:\n"
            << std::endl;

  conta2.transferir(10500, conta1);
  std::cout << "Conta 1:\n"
            << std::endl;
  std::cout << conta1.to_string() << std::endl;
  std::cout << "\nConta 2:\n"
            << std::endl;
  std::cout << conta2.to_string() << std::endl;

  return 0;
}
