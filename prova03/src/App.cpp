#include "../include/App.h"

#include <iostream>
#include <string>
#include <unordered_map>

#include "../include/Message.h"

App::App() : config("diary.config"), diary(this->config.getConfigs()["path"]) {
}

int App::run(int argc, char const* argv[]) {
  if (argc == 1) {
    return this->show_usage();
  }

  std::string action = argv[1];

  if (action == "add") {
    if (argc == 2) {
      this->add();
    } else {
      this->add(argv[2]);
    }
  } else if (action == "list") {
    if (argc == 2) {
      this->list_messages(this->config.getConfigs()["default_format"]);
    } else {
      this->list_messages(argv[2]);
    }
  } else if (action == "search") {
    if (argc == 2) {
      this->search();
    } else {
      this->search(argv[2]);
    }
  } else if (action == "interactive") {
    this->interactive_mode();
  } else {
    return this->show_usage();
  }

  return 0;
}

void App::add() {
  std::string message;
  std::cout << "Digite sua mensagem:" << std::endl;
  while (std::getline(std::cin, message) and not message.length()) continue;

  this->add(message);
}

void App::add(const std::string message) {
  this->diary.add(message);
}

void App::list_messages(const std::string& format) {
  if (this->diary.messages.empty()) {
    std::cout << "Não há mensagens para serem mostradas..." << std::endl;
    return;
  }

  for (Message& message : this->diary.messages) {
    std::cout << message.format(format) << std::endl;
  }
}

void App::search() {
  std::string what;
  std::cout << "Digite o termo de busca:" << std::endl;
  std::getline(std::cin, what);

  this->search(what);
}

void App::search(const std::string& what) {
  std::vector<Message*> occurrences = this->diary.search(what);

  if (not occurrences.empty()) {
    std::cout << "Ocorrência(s) encontrada(s):" << std::endl;

    for (Message* occurrence : occurrences) {
      std::cout << occurrence->to_string() << std::endl;
    }

    return;
  }

  std::cout << "Mensagem não encontrada..." << std::endl;
}

void App::interactive_mode() {
  std::string option = "-1";

  while (option != "0") {
    this->show_menu();
    std::cin >> option;

    if (option == "1") {
      std::cout << std::endl;
      this->list_messages(this->config.getConfigs()["default_format"]);
    } else if (option == "2") {
      std::cout << std::endl;
      this->add();
    }
  }
}

int App::show_usage() {
  std::cout << "Uso:   add <mensagem>" << std::endl;
  std::cout << "       search <termo de busca>" << std::endl;
  std::cout << "       list <formato>" << std::endl;
  std::cout << "       interactive" << std::endl;

  return 1;
}

void App::show_menu() {
  std::cout << "\n\033[1;36mDiário 1.0" << std::endl;

  std::cout << "\n\033[1;33mSelecione uma ação:" << std::endl;

  std::cout << "\n\033[1;32m1) Listar mensagens" << std::endl;
  std::cout << "2) Adicionar nova mensagem" << std::endl;

  std::cout << "\n\033[1;31m0) Finalizar\033[0m\n"
            << std::endl;
}
