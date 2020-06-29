#include "App.h"

#include <iostream>
#include <string>

#include "../include/Message.h"

App::App(const std::string& filename) : diary(filename) {}

int App::run(int argc, char const* argv[]) {
  if (argc == 1) {
    return show_usage();
  }

  std::string action = argv[1];

  if (action == "add") {
    if (argc == 2) {
      add();
    } else {
      add(argv[2]);
    }
  } else if (action == "list") {
    list_messages();
  } else {
    return show_usage();
  }

  return 0;
}

void App::add() {
  std::string message;
  std::cout << "Enter your message:" << std::endl;
  std::getline(std::cin, message);

  add(message);
}

void App::add(const std::string message) {
  diary.add(message);
}

void App::list_messages() {
  for (size_t i = 0; i < diary.messages_size; ++i) {
    std::cout << "- " << diary.messages[i].date.to_string()
              << " " << diary.messages[i].time.to_string()
              << " " << diary.messages[i].content << std::endl;
  }
}

int App::show_usage() {
  std::cout << "Uso: add <mensagem>" << std::endl;
  std::cout << "     list" << std::endl;
  return 1;
}
