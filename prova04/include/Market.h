#ifndef MARKET_H
#define MARKET_H

#include <list>
#include <string>

#include "Product.h"

class Market {
 private:
  std::list<Product> products;

  void add_product(Product product);
  std::list<Product> get_available_products();
  std::list<Product> get_sold_products();
  void write_cash_register();
  void write_stock();
  void update_data_files();

 public:
  Market(const std::string& stock_filename);

  void list_products();
  void list_cash_register();
  short check_if_product_can_be_sold(int product_id);
  void sell_product(int product_id);

  std::list<Product> get_products();
};

#endif  // !MARKET_H
