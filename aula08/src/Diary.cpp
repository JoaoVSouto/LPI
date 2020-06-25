#include "../include/Diary.h"

#include <iostream>

#include "../include/utils.h"

Diary::Diary(const std::string& filename)
    : filename(filename),
      messages(nullptr),
      messages_size(0),
      messages_capacity(10) {
  messages = new Message[messages_capacity];
}

Diary::~Diary() {
  delete[] messages;
}

void Diary::add(const std::string& message) {
  if (messages_size >= messages_capacity) return;

  Message m;
  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  messages[messages_size] = m;
  messages_size += 1;
}

void Diary::write() {}
