#include "../include/Customer.h"

#include <fstream>
#include <iostream>

#include "../include/VariadicTable.h"
#include "../include/utils.h"

unsigned Customer::customers_created = 0;

Customer::Customer(double balance) : balance(balance) {
  this->customers_created += 1;
}

short Customer::buy_product(Product& product) {
  if (product.get_price() > this->balance) {
    std::cout
        << "Erro: você não tem dinheiro suficiente para comprar o produto \""
        << product.get_name() << "\"" << std::endl;
    return 1;
  }

  std::cout << product.get_name() << " comprado com sucesso!" << std::endl;

  this->balance -= product.get_price();

  std::map<int, int>::iterator it = this->products_quantity.find(product.get_id());

  if (it == this->products_quantity.end()) {
    this->products_bag.push_back(product);
    this->products_quantity.insert({product.get_id(), 1});
    this->write_register();
    return 0;
  }

  it->second = it->second + 1;
  this->write_register();

  return 0;
}

void Customer::show_products_bag() {
  if (this->products_bag.empty()) {
    std::cout << "Ops... Sua sacola está vazia!" << std::endl;
    return;
  }

  VariadicTable<std::string,
                std::string,
                int,
                std::string>
      vt({"Produto",
          "Preço",
          "Quantidade",
          "Preço total"});

  double total_pay = 0;

  for (Product& product : this->products_bag) {
    double product_total_price = product.get_price() *
                                 this->products_quantity[product.get_id()];
    total_pay += product_total_price;

    vt.addRow(
        product.get_name(),
        "R$ " + utils::to_double_precision(product.get_price()),
        this->products_quantity[product.get_id()],
        "R$ " + utils::to_double_precision(product_total_price));
  }

  vt.print(std::cout);

  std::cout << "Total pago: R$ "
            << utils::to_double_precision(total_pay) << std::endl;
}

void Customer::write_register() {
  if (this->products_bag.empty()) {
    std::cout << "Ops... Sua sacola está vazia!" << std::endl;
    return;
  }

  std::ofstream register_file("cliente_" +
                              std::to_string(this->customers_created) + ".txt");

  VariadicTable<std::string,
                std::string,
                int,
                std::string>
      vt({"Produto",
          "Preço",
          "Quantidade",
          "Preço total"});

  double total_pay = 0;

  for (Product& product : this->products_bag) {
    double product_total_price = product.get_price() * this->products_quantity[product.get_id()];
    total_pay += product_total_price;

    vt.addRow(
        product.get_name(),
        "R$ " + utils::to_double_precision(product.get_price()),
        this->products_quantity[product.get_id()],
        "R$ " + utils::to_double_precision(product_total_price));
  }

  vt.print(register_file);

  register_file << "Total pago: R$ "
                << utils::to_double_precision(total_pay);

  register_file.close();
}

void Customer::increase_balance(double value) {
  this->balance += value;
}

double Customer::get_balance() {
  return this->balance;
}
