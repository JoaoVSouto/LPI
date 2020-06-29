#include "../include/Message.h"

#include <iostream>

Message::Message() {}

Message::Message(std::string content, Date date, Time time)
    : content(content), date(date), time(time) {}
