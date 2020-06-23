#include "../include/Diary.h"

#include <iostream>

Diary::Diary(const std::string& filename) : filename(filename) {
  std::cout << "Diary constructor..." << std::endl;
}

void Diary::add(const std::string& message) {}

void Diary::write() {}
