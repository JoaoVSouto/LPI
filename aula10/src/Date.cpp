#include "../include/Date.h"

#include <iostream>
#include <sstream>

Date::Date() : year(0), month(0), day(0) {}

Date::Date(unsigned year, unsigned month, unsigned day)
    : year(year), month(month), day(day) {}

void Date::set_from_string(const std::string& date) {
  std::stringstream stream(date);
  char discard;

  stream >> day;
  stream >> discard;
  stream >> month;
  stream >> discard;
  stream >> year;
}

std::string Date::to_string() {
  std::string day_str("");
  std::string month_str("");

  if (day <= 9) {
    day_str = "0";
  }

  if (month <= 9) {
    month_str = "0";
  }

  day_str.append(std::to_string(day));
  month_str.append(std::to_string(month));

  return day_str + "/" + month_str + "/" + std::to_string(year);
}
