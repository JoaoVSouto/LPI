#include <iostream>

#include "../include/Conta.h"

int main() {
  Conta c1(1234, 10000, "João");

  std::cout << "Conta 1:\n"
            << std::endl;

  std::cout << c1.to_string() << std::endl;

  std::cout << "\n----\nConta 1 | Sacando 7000:\n"
            << std::endl;

  c1.sacar(7000);
  std::cout << c1.to_string() << std::endl;

  std::cout << "\n----\nConta 1 | Depositando 1500:\n"
            << std::endl;

  c1.depositar(1500);
  std::cout << c1.to_string() << std::endl;

  Conta c2;
  c2.setNumero(9876);
  c2.setSaldo(27500);
  c2.setTitular("Pedro");

  std::cout << "\n----\nConta 2:\n"
            << std::endl;

  std::cout << c2.to_string() << std::endl;

  std::cout << "\n----\nTransferindo 2000 da Conta 1 para Conta 2:\n"
            << std::endl;

  c1.transferir(2000, c2);
  std::cout << "Conta 1:\n"
            << std::endl;
  std::cout << c1.to_string() << std::endl;
  std::cout << "\nConta 2:\n"
            << std::endl;
  std::cout << c2.to_string() << std::endl;

  std::cout << "\n----\nTransferindo 10500 da Conta 2 para Conta 1:\n"
            << std::endl;

  c2.transferir(10500, c1);
  std::cout << "Conta 1:\n"
            << std::endl;
  std::cout << c1.to_string() << std::endl;
  std::cout << "\nConta 2:\n"
            << std::endl;
  std::cout << c2.to_string() << std::endl;

  return 0;
}
