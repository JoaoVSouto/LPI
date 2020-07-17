#include "../include/Market.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "../include/VariadicTable.h"
#include "../include/utils.h"

Market::Market(const std::string& stock_filename)
    : stock_filename(stock_filename) {
  std::ifstream stock_file(stock_filename);

  if (not stock_file or not stock_file.is_open()) {
    std::cout << "Arquivo " << stock_filename
              << " não encontrado... Operação abortada." << std::endl;
    return;
  }

  std::string line;

  while (std::getline(stock_file, line)) {
    if (line.length() == 0) {
      continue;
    }

    if (line.rfind("COD", 0) == 0) {  // if line starts with "COD" ignore it
      continue;
    }

    std::vector<std::string> splitted_row = utils::split_string(line, ',');

    int product_id = std::stoi(splitted_row[0]);
    std::string product_name = splitted_row[1];
    std::string product_unit = splitted_row[2];

    std::stringstream stream(splitted_row[3]);
    std::string discard;

    stream >> discard;

    double product_price;
    stream >> product_price;

    int product_quantity = std::stoi(splitted_row[4]);

    Product product(product_id, product_name, product_unit,
                    product_price, product_quantity);

    this->add_product(product);
  }

  stock_file.close();
}

void Market::add_product(Product product) {
  this->products.push_back(product);
}

VectorMarket<Product> Market::get_available_products() {
  VectorMarket<Product> available_products;

  for (Product& product : this->products) {
    if (product.get_quantity() > product.get_sold_quantity()) {
      available_products.push_back(product);
    }
  }

  return available_products;
}

VectorMarket<Product> Market::get_sold_products() {
  VectorMarket<Product> sold_products;

  for (Product& product : this->products) {
    if (product.get_sold_quantity() > 0) {
      sold_products.push_back(product);
    }
  }

  return sold_products;
}

void Market::write_cash_register() {
  std::ofstream cash_file("caixa.csv");
  VectorMarket<Product> sold_products = this->get_sold_products();
  double total_profit = 0;

  cash_file << "COD,PRODUTO,PREÇO,QUANTIDADES VENDIDAS,LUCRO\n";

  for (Product& product : sold_products) {
    double profit = product.get_price() * product.get_sold_quantity();
    total_profit += profit;

    cash_file << product.get_id() << ","
              << product.get_name() << ","
              << "R$ " + utils::to_double_precision(product.get_price()) << ","
              << product.get_sold_quantity() << ","
              << "R$ " + utils::to_double_precision(profit) << "\n";
  }

  cash_file << ",,,LUCRO TOTAL,R$" << utils::to_double_precision(total_profit);

  cash_file.close();
}

void Market::write_stock() {
  std::ofstream stock_file(this->stock_filename);

  stock_file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE\n";

  for (Product& product : this->products) {
    stock_file << product.get_id() << ","
               << product.get_name() << ","
               << product.get_unit_of_measurement() << ","
               << "R$ " + utils::to_double_precision(product.get_price()) << ","
               << product.get_quantity() - product.get_sold_quantity() << "\n";
  }

  stock_file.close();
}

void Market::update_data_files() {
  this->write_cash_register();
  this->write_stock();
}

void Market::list_products() {
  VectorMarket<Product> available_products = this->get_available_products();

  VariadicTable<std::string, std::string, std::string, int> vt({"Código",
                                                                "Produto",
                                                                "Preço",
                                                                "Qnt. disponível"});

  for (Product& product : available_products) {
    vt.addRow(std::to_string(product.get_id()),
              product.get_name(),
              "R$ " + utils::to_double_precision(product.get_price()),
              product.get_quantity() - product.get_sold_quantity());
  }

  vt.print(std::cout);
}

void Market::list_cash_register() {
  VectorMarket<Product> sold_products = this->get_sold_products();

  if (sold_products.empty()) {
    std::cout << "Nenhum produto foi vendido!" << std::endl;
    return;
  }

  VariadicTable<int,
                std::string,
                std::string,
                int,
                std::string>
      vt({"Código",
          "Produto",
          "Preço",
          "Qnts. vendidas",
          "Lucro"});

  double total_profit = 0;

  for (Product& product : sold_products) {
    double profit = product.get_price() * product.get_sold_quantity();
    total_profit += profit;

    vt.addRow(
        product.get_id(),
        product.get_name(),
        "R$ " + utils::to_double_precision(product.get_price()),
        product.get_sold_quantity(),
        "R$ " + utils::to_double_precision(profit));
  }

  vt.print(std::cout);

  std::cout << "Lucro total: R$ "
            << utils::to_double_precision(total_profit) << std::endl;
}

short Market::check_if_product_can_be_sold(int product_id) {
  Product* product_found(nullptr);

  for (Product& product : this->products) {
    if (product.get_id() == product_id) {
      product_found = &product;
      break;
    }
  }

  if (not product_found) {
    std::cout << "Erro: produto com o código " << product_id
              << " não encontrado..." << std::endl;
    return 1;
  }

  if (product_found->get_sold_quantity() >= product_found->get_quantity()) {
    std::cout << "Erro: o produto \"" << product_found->get_name()
              << "\" se esgotou!" << std::endl;
    return 1;
  }

  return 0;
}

void Market::sell_product(int product_id) {
  Product* product_found(nullptr);

  for (Product& product : this->products) {
    if (product.get_id() == product_id) {
      product_found = &product;
      break;
    }
  }

  product_found->set_sold_quantity(product_found->get_sold_quantity() + 1);
  this->update_data_files();
}

short Market::resupply(std::string product_name, int quantity) {
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
              << "\" não encontrado no arquivo " << this->stock_filename << std::endl;
    return 1;
  }

  product_found->set_quantity(product_found->get_quantity() + quantity);
  this->write_stock();

  return 0;
}

VectorMarket<Product> Market::get_products() {
  VectorMarket<Product> copy;

  // This was necessary because std::copy and direct assign with this->products
  // would generate segmentation fault
  for (Product& product : this->products) {
    copy.push_back(product);
  }

  return copy;
}
