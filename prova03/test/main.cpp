#include <iostream>
#include <string>

#include "../include/Message.h"
#include "../include/utils.h"

int main(int argc, char const* argv[]) {
  std::cout << random_string() << std::endl;

  // std::string FORMAT = "[%d %t] %m";

  // Message m;
  // m.content = "acordei";
  // m.date.set_from_string(get_current_date());
  // m.time.set_from_string(get_current_time());

  // size_t foundDate;
  // while ((foundDate = FORMAT.find("%d")) != std::string::npos) {
  //   FORMAT.replace(foundDate, 2, m.date.to_string());
  // }

  // size_t foundTime;
  // while ((foundTime = FORMAT.find("%t")) != std::string::npos) {
  //   FORMAT.replace(foundTime, 2, m.time.to_string());
  // }

  // size_t foundContent;
  // while ((foundContent = FORMAT.find("%m")) != std::string::npos) {
  //   FORMAT.replace(foundContent, 2, m.content);
  // }

  // std::cout << FORMAT << std::endl;

  return 0;
}
