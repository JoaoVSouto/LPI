#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <map>
#include <vector>

#include "Product.h"

class Customer {
 private:
  double balance;
  std::vector<Product> products_bag;
  std::map<int, int> products_quantity;
  static unsigned customers_created;

 public:
  Customer(double balance);

  short buy_product(Product& product);
  void show_products_bag();
  void write_register();
  void increase_balance(double value);

  double get_balance();
};

#endif  // !CUSTOMER_H
