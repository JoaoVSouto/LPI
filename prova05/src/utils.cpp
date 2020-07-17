#include "../include/utils.h"

#include <iomanip>
#include <sstream>

std::vector<std::string> utils::split_string(std::string s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  size_t pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + 1);
  }

  tokens.push_back(s);

  return tokens;
}

std::string utils::to_double_precision(double d) {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << d;

  return stream.str();
}
