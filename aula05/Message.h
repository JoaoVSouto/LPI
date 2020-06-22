#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

#include "Date.h"
#include "Time.h"

struct Message {
  std::string content;
  Date date;
  Time time;

  bool compare_dates(const Message& message);
};

#endif  // !MESSAGE_H
