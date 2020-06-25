#include "../include/Time.h"

#include <iostream>
#include <sstream>

Time::Time() : hour(0), minute(0), second(0) {}

Time::Time(unsigned hour, unsigned minute, unsigned second)
    : hour(hour), minute(minute), second(second) {}

void Time::set_from_string(const std::string& time) {
  std::stringstream stream(time);
  char discard;

  stream >> hour;
  stream >> discard;
  stream >> minute;
  stream >> discard;
  stream >> second;
}

std::string Time::to_string() {
  std::string minute_str("");
  std::string second_str("");

  if (minute <= 9) {
    minute_str = "0";
  }

  if (second <= 9) {
    second_str = "0";
  }

  minute_str.append(std::to_string(minute));
  second_str.append(std::to_string(second));

  return std::to_string(hour) + ":" + minute_str + ":" + second_str;
}
