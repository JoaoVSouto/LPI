#include "../include/Message.h"

#include <iostream>

Message::Message() {}

Message::Message(std::string content, Date date, Time time)
    : content(content), date(date), time(time) {}

std::string Message::to_string() {
  return "- " + this->date.to_string() + " " +
         this->time.to_string() + " " + this->content;
}
