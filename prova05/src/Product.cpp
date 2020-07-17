#include "../include/Product.h"

Product::Product()
    : id(0), name(""), unit_of_measurement(""), price(0), quantity(0), sold_quantity(0) {}

Product::Product(std::string name, int quantity)
    : name(name), quantity(quantity) {}

Product::Product(int id, std::string name,
                 std::string unit_of_measurement,
                 double price, int quantity)
    : id(id), name(name), unit_of_measurement(unit_of_measurement), price(price), quantity(quantity), sold_quantity(0) {
}

int Product::get_id() {
  return this->id;
}

std::string Product::get_name() {
  return this->name;
}

std::string Product::get_unit_of_measurement() {
  return this->unit_of_measurement;
}

double Product::get_price() {
  return this->price;
}

int Product::get_quantity() {
  return this->quantity;
}

void Product::set_quantity(int quantity) {
  this->quantity = quantity;
}

int Product::get_sold_quantity() {
  return this->sold_quantity;
}

void Product::set_sold_quantity(int quantity) {
  this->sold_quantity = quantity;
}
