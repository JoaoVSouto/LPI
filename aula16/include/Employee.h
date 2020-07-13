#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
 private:
  std::string name;
  std::string department;
  std::string admission_date;
  double salary;

 public:
  Employee();
  Employee(std::string name, std::string department,
           std::string admission_date, double salary);

  void set_name(std::string name);
  std::string get_name();
  void set_department(std::string department);
  std::string get_department();
  void set_admission_date(std::string admission_date);
  std::string get_admission_date();
  void set_salary(double salary);
  double get_salary();
};

#endif  // !EMPLOYEE_H
