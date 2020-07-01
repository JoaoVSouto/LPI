#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>

#include "Message.h"

struct Diary {
  std::string filename;
  std::vector<Message> messages;

  Diary(const std::string& filename);
  ~Diary();

  void add(const std::string& message);
  void add(const Message& message);
  void write();
  std::vector<Message*> search(const std::string& what);
};

#endif  // !DIARY_H
