#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>

#include "Employee.h"

class Company {
 private:
  std::string name;
  std::string cnpj;
  std::vector<Employee> employees;

 public:
  Company();
  Company(std::string name, std::string cnpj);

  void set_name(std::string name);
  std::string get_name();
  void set_cnpj(std::string cnpj);
  std::string get_cnpj();
  void add_employee(Employee employee);
  std::vector<Employee> get_employees();
};

#endif  // !COMPANY_H
