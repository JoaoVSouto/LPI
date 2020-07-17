#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

#include "Market.h"
#include "Product.h"
#include "VectorMarket.h"

class Supplier {
 private:
  VectorMarket<Product> products;
  std::string supply_filename;

  void add_product(Product product);
  VectorMarket<Product> get_available_products();
  void write_supply();

 public:
  Supplier(const std::string& supply_filename);

  void list_products();
  void pass_product_to(Market& market, std::string product_name, int quantity);
};

#endif  // !SUPPLIER_H
