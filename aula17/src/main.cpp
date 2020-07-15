#include <iostream>

#include "../include/Agencia.h"
#include "../include/Cliente.h"
#include "../include/ClientePJ.h"
#include "../include/Conta.h"
#include "../include/Fila.h"
#include "./Fila.cpp"

int main() {
  Fila<Cliente> clientes;

  Cliente cliente1("João", "864.974.420-65");
  Cliente cliente2("Mayra", "140.739.380-45");
  Cliente cliente3("Pedro", "654.248.650-03");

  clientes.push(cliente1);
  clientes.push(cliente2);

  std::cout << "Próximo cliente da fila:" << std::endl;
  std::cout << clientes.front().get_nome() << std::endl;

  clientes.pop();

  std::cout << "Próximo cliente da fila:" << std::endl;
  std::cout << clientes.front().get_nome() << std::endl;

  clientes.push(cliente3);
  clientes.pop();

  std::cout << "Próximo cliente da fila:" << std::endl;
  std::cout << clientes.front().get_nome() << std::endl;

  clientes.push(cliente2);
  clientes.push(cliente1);

  std::cout << "Último cliente da fila:" << std::endl;
  std::cout << clientes.back().get_nome() << std::endl;

  std::cout << "Quantidade de clientes na fila:" << std::endl;
  std::cout << clientes.size() << std::endl;

  clientes.pop();
  clientes.pop();

  std::cout << "Fila vazia?" << std::endl;
  std::cout << (clientes.empty() ? "Sim" : "Não") << std::endl;

  clientes.pop();

  std::cout << "Fila vazia?" << std::endl;
  std::cout << (clientes.empty() ? "Sim" : "Não") << std::endl;

  Fila<ClientePJ> clientes_pj;

  ClientePJ cliente_pj1("Nordestão", "50.727.079/0001-25");
  ClientePJ cliente_pj2("Carrefour", "94.657.100/0001-39");

  clientes_pj.push(cliente_pj1);
  clientes_pj.push(cliente_pj2);

  std::cout << "Próximo cliente PJ da fila:" << std::endl;
  std::cout << clientes_pj.front().get_razao_social() << std::endl;

  std::cout << "Último cliente PJ da fila:" << std::endl;
  std::cout << clientes_pj.back().get_razao_social() << std::endl;

  return 0;
}
