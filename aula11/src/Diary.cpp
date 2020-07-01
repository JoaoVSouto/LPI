#include "../include/Diary.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "../include/utils.h"

Diary::Diary(const std::string& filename)
    : filename(filename) {
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
}

void Diary::add(const std::string& message) {
  Message m;
  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  this->messages.push_back(m);
}

void Diary::add(const Message& message) {
  this->messages.push_back(message);
}

void Diary::write() {
  std::ofstream diary_file(filename);

  if (not diary_file or not diary_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo...\n";
    return;
  }

  std::string current_date("");

  if (this->messages.size() > 0) {
    current_date = messages[0].date.to_string();
    diary_file << "# " << current_date << "\n\n";
  }

  for (Message& message : this->messages) {
    if (message.date.to_string() != current_date) {
      current_date = message.date.to_string();
      diary_file << "\n# " << current_date << "\n\n";
    }

    diary_file << "- " << message.time.to_string()
               << " " << message.content << "\n";
  }
}

std::vector<Message*> Diary::search(const std::string& what) {
  std::vector<Message*> occurrences;

  for (Message& message : this->messages) {
    std::string const& message_content = message.content;

    if (message_content.find(what) != std::string::npos) {
      occurrences.push_back(&message);
    }
  }

  return occurrences;
}
