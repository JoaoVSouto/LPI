#ifndef TIME_H
#define TIME_H

#include <string>

struct Time {
  int hour;
  int minutes;
  int seconds;

  std::string get_formatted_time();
  bool compare(const Time& time);
};

#endif  // !TIME_H
