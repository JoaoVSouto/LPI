#include "../include/Supplier.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/VariadicTable.h"
#include "../include/utils.h"

Supplier::Supplier(const std::string& supply_filename)
    : supply_filename(supply_filename) {
  std::ifstream supply_file(supply_filename);

  if (not supply_file or not supply_file.is_open()) {
    std::cout << "Arquivo " << supply_filename
              << " não encontrado... Operação abortada." << std::endl;
    return;
  }

  std::string line;

  while (std::getline(supply_file, line)) {
    if (line.length() == 0) {
      continue;
    }

    if (line.rfind("PRODUTO", 0) == 0) {  // if line starts with "PRODUTO" ignore it
      continue;
    }

    std::vector<std::string> splitted_row = utils::split_string(line, ',');

    std::string product_name = splitted_row[0];
    int product_quantity = std::stoi(splitted_row[1]);

    Product product(product_name, product_quantity);

    this->add_product(product);
  }

  supply_file.close();
}

void Supplier::add_product(Product product) {
  this->products.push_back(product);
}

VectorMarket<Product> Supplier::get_available_products() {
  VectorMarket<Product> available_products;

  for (Product& product : this->products) {
    if (product.get_quantity() > 0) {
      available_products.push_back(product);
    }
  }

  return available_products;
}

void Supplier::write_supply() {
  std::ofstream supply_file(this->supply_filename);

  supply_file << "PRODUTO,QUANTIDADE\n";

  for (Product& product : this->products) {
    supply_file << product.get_name() << "," << product.get_quantity() << "\n";
  }

  supply_file.close();
}

void Supplier::list_products() {
  VectorMarket<Product> available_products = this->get_available_products();

  VariadicTable<std::string, int> vt({"Produto", "Quantidade"});

  for (Product& product : available_products) {
    vt.addRow(product.get_name(), product.get_quantity());
  }

  vt.print(std::cout);
}

void Supplier::pass_product_to(Market& market, std::string product_name,
                               int quantity) {
  Product* product_found(nullptr);

  std::string product_name_received_lowercase = product_name;
  std::transform(product_name_received_lowercase.begin(),
                 product_name_received_lowercase.end(),
                 product_name_received_lowercase.begin(),
                 ::tolower);

  for (Product& product : this->products) {
    std::string product_name_lowercase = product.get_name();
    std::transform(product_name_lowercase.begin(),
                   product_name_lowercase.end(),
                   product_name_lowercase.begin(),
                   ::tolower);

    if (product_name_lowercase == product_name_received_lowercase) {
      product_found = &product;
      break;
    }
  }

  if (not product_found) {
    std::cout << "Erro: Produto de nome \"" << product_name
              << "\" não encontrado no arquivo " << this->supply_filename
              << std::endl;
    return;
  }

  if (product_found->get_quantity() <= 0) {
    std::cout << "Erro: Produto de nome \"" << product_name
              << "\" não está disponível no fornecedor" << std::endl;
    return;
  }

  if (product_found->get_quantity() < quantity) {
    std::cout << "Erro: O fornecedor não possui " << quantity
              << " unidades do produto \"" << product_name
              << "\", possui apenas " << product_found->get_quantity() << std::endl;
    return;
  }

  short market_resupply_response = market.resupply(product_name, quantity);

  if (market_resupply_response > 0) {
    return;
  }

  product_found->set_quantity(product_found->get_quantity() - quantity);
  this->write_supply();
}
