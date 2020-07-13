#include "../include/App.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/Customer.h"
#include "../include/utils.h"

App::App() : market("estoque.csv") {
}

int App::run() {
  this->pre_menu();

  return 0;
}

void App::pre_menu() {
  std::string entry("");

  while (entry != "2") {
    this->show_pre_menu();

    while (std::getline(std::cin, entry) and not entry.length()) continue;

    if (entry == "1") {
      this->customer_menu();
    }
  }
}

void App::show_pre_menu() {
  std::cout << "┌─────────────────────────────────────┐" << std::endl;
  std::cout << "│   Seja bem-vindo(a) ao mercado!     │" << std::endl;
  std::cout << "│                                     │" << std::endl;
  std::cout << "│   Selecione o que deseja:           │" << std::endl;
  std::cout << "│                                     │" << std::endl;
  std::cout << "│   1. Entrar como um novo cliente    │" << std::endl;
  std::cout << "│   2. Sair                           │" << std::endl;
  std::cout << "└─────────────────────────────────────┘" << std::endl;
}

void App::customer_menu() {
  std::string entry("");

  Customer customer(100);

  while (entry != "6") {
    this->show_customer_menu(customer.get_balance());

    while (std::getline(std::cin, entry) and not entry.length()) continue;

    if (entry == "1") {
      this->handle_increase_balance(customer);
    } else if (entry == "2") {
      this->handle_available_products();
    } else if (entry == "3") {
      this->handle_buy_product(customer);
    } else if (entry == "4") {
      this->handle_show_bag(customer);
    } else if (entry == "5") {
      this->handle_show_cash_register();
    }
  }
}

void App::show_customer_menu(double customer_balance) {
  std::cout << "┌─────────────────────────────────────┐" << std::endl;
  std::cout << "│   Olá Cliente!                      │" << std::endl;
  std::cout << "│                                     │" << std::endl;
  std::cout << "│   Seu saldo é de R$ " << utils::to_double_precision(customer_balance) << "          │" << std::endl;
  std::cout << "│                                     │" << std::endl;
  std::cout << "│   Selecione o que deseja:           │" << std::endl;
  std::cout << "│                                     │" << std::endl;
  std::cout << "│   1. Adicionar saldo                │" << std::endl;
  std::cout << "│   2. Produtos disponíveis           │" << std::endl;
  std::cout << "│   3. Comprar produto                │" << std::endl;
  std::cout << "│   4. Minha sacola                   │" << std::endl;
  std::cout << "│   5. Ver caixa do mercado           │" << std::endl;
  std::cout << "│   6. Sair                           │" << std::endl;
  std::cout << "└─────────────────────────────────────┘" << std::endl;
}

void App::handle_increase_balance(Customer& customer) {
  std::string entry;
  double increase = 0;

  std::cout
      << "Digite a quantidade em reais que deseja adicionar ao seu saldo:"
      << std::endl;

  while (std::getline(std::cin, entry) and not entry.length()) continue;

  std::stringstream stream(entry);
  stream >> increase;

  while (not increase) {
    std::cout << "Valor inválido para o saldo!" << std::endl;
    std::cout << "Digite novamente:" << std::endl;

    while (std::getline(std::cin, entry) and not entry.length()) continue;

    std::stringstream stream(entry);
    stream >> increase;
  }

  customer.increase_balance(increase);
}

void App::handle_available_products() {
  this->market.list_products();
}

void App::handle_buy_product(Customer& customer) {
  std::string product_name("");

  std::cout << "Digite o nome do produto que deseja comprar:" << std::endl;

  while (std::getline(std::cin, product_name) and not product_name.length()) continue;

  std::string product_name_lowercase = product_name;

  std::transform(product_name_lowercase.begin(),
                 product_name_lowercase.end(),
                 product_name_lowercase.begin(),
                 ::tolower);

  std::list<Product> market_products = this->market.get_products();
  std::list<Product>::iterator it;

  it = std::find_if(market_products.begin(),
                    market_products.end(),
                    [product_name_lowercase](Product product) -> bool {
                      std::string current_product_name = product.get_name();

                      std::transform(current_product_name.begin(),
                                     current_product_name.end(),
                                     current_product_name.begin(),
                                     ::tolower);

                      return product_name_lowercase == current_product_name;
                    });

  if (it == market_products.end()) {
    std::cout << "Erro: Produto de nome \"" << product_name
              << "\" não encontrado" << std::endl;
    return;
  }

  short sell_product_code = this->market.check_if_product_can_be_sold(it->get_id());

  if (sell_product_code > 0) {
    return;
  }

  short buy_product_code = customer.buy_product(*it);

  if (buy_product_code > 0) {
    return;
  }

  this->market.sell_product(it->get_id());
}

void App::handle_show_bag(Customer& customer) {
  customer.show_products_bag();
}

void App::handle_show_cash_register() {
  this->market.list_cash_register();
}
