#include "../include/Time.h"

#include <iostream>

Time::Time(unsigned hour, unsigned minute, unsigned second)
    : hour(hour), minute(minute), second(second) {
  std::cout << "Time constructor..." << std::endl;
}

void Time::set_from_string(const std::string& time) {}
