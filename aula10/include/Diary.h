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
  ~Diary();

  void add(const std::string& message);
  void add(const Message& message);
  void write();
  Message* search(const std::string& what);

 private:
  void double_messages_capacity();
};

#endif  // !DIARY_H
