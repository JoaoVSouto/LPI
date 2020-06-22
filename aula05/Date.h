#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
  int year;
  int month;
  int day;

  std::string get_formatted_date();
  bool compare(const Date& date);
};

#endif  // !DATE_H
