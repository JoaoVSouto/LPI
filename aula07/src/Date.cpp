#include "../include/Date.h"

#include <iostream>

Date::Date() {}

Date::Date(unsigned year, unsigned month, unsigned day)
    : year(year), month(month), day(day) {
  std::cout << "Date constructor..." << std::endl;
}

void Date::set_from_string(const std::string& date) {}
