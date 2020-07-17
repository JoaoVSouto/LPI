#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace utils {
std::vector<std::string> split_string(std::string s, char delimiter);
std::string to_double_precision(double d);
}  // namespace utils

#endif  // !UTILS_H
