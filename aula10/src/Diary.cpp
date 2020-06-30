#include "../include/Diary.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "../include/utils.h"

Diary::Diary(const std::string& filename)
    : filename(filename),
      messages(nullptr),
      messages_size(0),
      messages_capacity(8) {
  messages = new Message[messages_capacity];

  std::ifstream diary_file(filename);

  if (not diary_file or not diary_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo...\n";
    return;
  }

  std::string line;
  std::string current_line_date;

  while (std::getline(diary_file, line)) {
    if (line.length() == 0) continue;

    if (line.rfind("#", 0) == 0) {
      current_line_date = line.substr(2);
      continue;
    }

    std::string current_line_time("");
    std::string current_line_content("");

    if (line.rfind("-", 0) == 0) {
      current_line_time = line.substr(2, 8);
    }

    current_line_content = line.substr(11);

    Message message;
    message.content = current_line_content;
    message.date.set_from_string(current_line_date);
    message.time.set_from_string(current_line_time);

    add(message);
  }
}

Diary::~Diary() {
  write();
  delete[] messages;
}

void Diary::add(const std::string& message) {
  if (messages_size >= messages_capacity) {
    double_messages_capacity();
  }

  Message m;
  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  messages[messages_size] = m;
  messages_size += 1;
}

void Diary::add(const Message& message) {
  if (messages_size >= messages_capacity) {
    double_messages_capacity();
  }

  messages[messages_size] = message;
  messages_size += 1;
}

void Diary::write() {
  std::ofstream diary_file(filename);

  if (not diary_file or not diary_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo...\n";
    return;
  }

  std::string current_date("");

  if (messages_size > 0) {
    current_date = messages[0].date.to_string();
    diary_file << "# " << current_date << "\n\n";
  }

  for (size_t i = 0; i < messages_size; ++i) {
    if (messages[i].date.to_string() != current_date) {
      current_date = messages[i].date.to_string();
      diary_file << "\n# " << current_date << "\n\n";
    }

    diary_file << "- " << messages[i].time.to_string()
               << " " << messages[i].content << "\n";
  }
}

Message* Diary::search(const std::string& what) {
  for (size_t i = 0; i < this->messages_size; ++i) {
    std::string const& message_content = this->messages[i].content;

    if (message_content.find(what) != std::string::npos) {
      return this->messages + i;
    }
  }

  return nullptr;
}

void Diary::double_messages_capacity() {
  messages_capacity *= 2;

  Message* temp_array = new Message[messages_capacity];
  std::copy(messages, messages + messages_size, temp_array);

  delete[] messages;
  messages = temp_array;
}
