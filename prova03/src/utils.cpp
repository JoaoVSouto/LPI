#include "../include/utils.h"

#include <algorithm>
#include <ctime>
#include <random>

std::string format_current_date(const std::string& format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() {
  return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
  return format_current_date("%H:%M:%S");
}

std::vector<std::string> split_string(std::string s, char delimiter) {
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

std::string random_string() {
  std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

  std::random_device rd;
  std::mt19937 generator(rd());

  std::shuffle(str.begin(), str.end(), generator);

  return str.substr(0, 32);
}
