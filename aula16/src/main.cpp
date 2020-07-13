#include <iomanip>
#include <iostream>
#include <sstream>

#include "../include/Company.h"
#include "../include/Employee.h"

int main(int argc, char const* argv[]) {
  Company company("John Corp.", "17.658.257/0001-38");

  int employees;
  std::cout << "How many employees do you want in your company?" << std::endl;
  std::cin >> employees;

  for (size_t i = 0; i < employees; i++) {
    Employee employee;
    std::string name;
    std::string department;
    double salary;

    std::cout << "Employee no. " << i + 1 << std::endl;
    std::cout << "Name:" << std::endl;
    while (std::getline(std::cin, name) and not name.length()) continue;
    std::cout << "Department:" << std::endl;
    while (std::getline(std::cin, department) and not department.length()) continue;
    std::cout << "Salary:" << std::endl;
    std::cin >> salary;

    employee.set_name(name);
    employee.set_department(department);
    employee.set_admission_date("13/07/2020");
    employee.set_salary(salary);

    company.add_employee(employee);
  }

  std::string department;
  std::cout
      << "Which department do you want to give a 10% raise on employees' salary?" << std::endl;
  while (std::getline(std::cin, department) and not department.length()) continue;

  for (Employee& employee : company.get_employees()) {
    if (employee.get_department() == department) {
      std::stringstream stream_old_salary;
      stream_old_salary << std::fixed << std::setprecision(2) << employee.get_salary();

      std::cout << employee.get_name() << "'s old salary was $"
                << stream_old_salary.str() << std::endl;

      double new_salary = employee.get_salary() * 1.1;
      employee.set_salary(new_salary);

      std::stringstream stream_new_salary;
      stream_new_salary << std::fixed << std::setprecision(2) << employee.get_salary();

      std::cout << employee.get_name() << "'s new salary is $"
                << stream_new_salary.str() << std::endl;
    }
  }

  return 0;
}
