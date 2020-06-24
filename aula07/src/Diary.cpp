#include "../include/Diary.h"

#include <iostream>

Diary::Diary(const std::string& filename)
    : filename(filename), messages(nullptr), messages_size(0) {
  messages_capacity = 10;
  messages = new Message[messages_capacity];
}

Diary::~Diary() {
  delete[] messages;
}

void Diary::add(const std::string& message) {
  if (messages_size >= messages_capacity) return;

  messages[messages_size].content = message;
  messages_size += 1;
}

void Diary::write() {}
