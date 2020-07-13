#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
 private:
  int id;
  std::string name;
  std::string unit_of_measurement;
  double price;
  int quantity;
  int sold_quantity;

 public:
  Product(int id, std::string name,
          std::string unit_of_measurement, double price, int quantity);

  int get_id();
  std::string get_name();
  std::string get_unit_of_measurement();
  double get_price();
  int get_quantity();
  int get_sold_quantity();
  void set_sold_quantity(int quantity);
};

#endif  // !PRODUCT_H
