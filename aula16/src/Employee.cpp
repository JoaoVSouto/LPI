#include "../include/Employee.h"

Employee::Employee() {}

Employee::Employee(std::string name,
                   std::string department,
                   std::string admission_date,
                   double salary)
    : name(name), department(department), admission_date(admission_date), salary(salary) {
}

void Employee::set_name(std::string name) {
  this->name = name;
}

std::string Employee::get_name() {
  return this->name;
}

void Employee::set_department(std::string department) {
  this->department = department;
}

std::string Employee::get_department() {
  return this->department;
}

void Employee::set_admission_date(std::string admission_date) {
  this->admission_date = admission_date;
}

std::string Employee::get_admission_date() {
  return this->admission_date;
}

void Employee::set_salary(double salary) {
  this->salary = salary;
}

double Employee::get_salary() {
  return this->salary;
}
