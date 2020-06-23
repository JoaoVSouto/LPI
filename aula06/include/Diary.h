#ifndef DIARY_H
#define DIARY_H

#include <string>

#include "Message.h"

struct Diary {
  std::string filename;
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  Diary(const std::string& filename);

  void add(const std::string& message);
  void write();
};

#endif  // !DIARY_H
