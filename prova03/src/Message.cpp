#include "../include/Message.h"

#include <iostream>

#include "../include/utils.h"

Message::Message() {}

Message::Message(std::string content, Date date, Time time)
    : content(content), date(date), time(time) {}

std::string Message::to_string() {
  return "- " + this->date.to_string() + " " +
         this->time.to_string() + " " + this->content;
}

std::string Message::format(std::string format) {
  size_t foundDate;
  while ((foundDate = format.find("%d")) != std::string::npos) {
    format.replace(foundDate, 2, this->date.to_string());
  }

  size_t foundTime;
  while ((foundTime = format.find("%t")) != std::string::npos) {
    format.replace(foundTime, 2, this->time.to_string());
  }

  std::string string_hash = random_string();
  size_t foundContentOnMessage;
  while ((foundContentOnMessage = this->content.find("%m")) != std::string::npos) {
    this->content.replace(foundContentOnMessage, 2, string_hash);
  }

  size_t foundContent;
  while ((foundContent = format.find("%m")) != std::string::npos) {
    format.replace(foundContent, 2, this->content);
  }

  size_t foundStringHash;
  while ((foundStringHash = this->content.find(string_hash)) != std::string::npos) {
    this->content.replace(foundStringHash, string_hash.size(), "%m");
  }

  size_t foundStringHashOnFormat;
  while ((foundStringHashOnFormat = format.find(string_hash)) != std::string::npos) {
    format.replace(foundStringHashOnFormat, string_hash.size(), "%m");
  }

  return format;
}
