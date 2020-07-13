#include "../include/Company.h"

Company::Company() {}

Company::Company(std::string name, std::string cnpj)
    : name(name), cnpj(cnpj) {
}

void Company::set_name(std::string name) {
  this->name = name;
}

std::string Company::get_name() {
  return this->name;
}

void Company::set_cnpj(std::string cnpj) {
  this->cnpj = cnpj;
}

std::string Company::get_cnpj() {
  return this->cnpj;
}

void Company::add_employee(Employee employee) {
  this->employees.push_back(employee);
}

std::vector<Employee> Company::get_employees() {
  return this->employees;
}
