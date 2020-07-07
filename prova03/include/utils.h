#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();
std::vector<std::string> split_string(std::string s, char delimiter);
std::string random_string();

#endif  // !UTILS_H
