#ifndef APP_H
#define APP_H

#include "Customer.h"
#include "Market.h"

class App {
 private:
  Market market;
  void pre_menu();
  void show_pre_menu();
  void customer_menu();
  void show_customer_menu(double customer_balance);
  void handle_increase_balance(Customer& customer);
  void handle_available_products();
  void handle_buy_product(Customer& customer);
  void handle_show_bag(Customer& customer);
  void handle_show_cash_register();

 public:
  App();

  int run();
};

#endif  // !APP_H
