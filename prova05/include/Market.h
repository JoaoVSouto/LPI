#ifndef MARKET_H
#define MARKET_H

#include <string>

#include "Product.h"
#include "VectorMarket.h"

class Market {
 private:
  VectorMarket<Product> products;
  std::string stock_filename;

  void add_product(Product product);
  VectorMarket<Product> get_available_products();
  VectorMarket<Product> get_sold_products();
  void write_cash_register();
  void write_stock();
  void update_data_files();

 public:
  Market(const std::string& stock_filename);

  void list_products();
  void list_cash_register();
  short check_if_product_can_be_sold(int product_id);
  void sell_product(int product_id);
  short resupply(std::string product_name, int quantity);

  VectorMarket<Product> get_products();
};

#endif  // !MARKET_H
