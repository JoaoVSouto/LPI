#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using vector_string = std::vector<std::string>;
using map_string = std::map<std::string, std::string>;

void show_usage(std::string const& program_name);
short handle_args(int argc, vector_string& args);
short write_message_to_file(std::string const& filename, std::string const& message);
short read_message_from_file(std::string const& filename);
short handle_add(int argc, vector_string args);
short handle_list();

std::string const FILE_NAME = "entries.txt";

map_string const PROGRAM_ARGS = {{"add", "<mensagem>"},
                                 {"list", ""}};

int main(int argc, char const* argv[]) {
  vector_string args(argv, argv + argc);

  if (handle_args(argc, args) != 0) {
    show_usage(args.at(0));
    return 1;
  }

  if (args.at(1) == "add" && handle_add(argc, args) != 0) {
    return 1;
  }

  if (args.at(1) == "list" && handle_list() != 0) {
    return 1;
  }

  return 0;
}

void show_usage(std::string const& program_name) {
  std::cout << "Uso:";
  for (auto const& arg : PROGRAM_ARGS) {
    std::cout << "\t" << program_name << " "
              << arg.first << " " << arg.second << std::endl;
  }
}

short handle_args(int argc, vector_string& args) {
  if (argc == 1) return 1;

  std::string program_name = args.at(0);

  for (auto const& arg : PROGRAM_ARGS) {
    if (arg.first.compare(args.at(1)) == 0) {
      return 0;
    }
  }

  return 1;
}

short write_message_to_file(std::string const& filename, std::string const& message) {
  std::ofstream message_file(filename, std::ios::app);

  if (not message_file or not message_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo\n";
    return 1;
  }

  message_file << "- " << message << "\n";

  message_file.close();

  return 0;
}

short read_message_from_file(std::string const& filename) {
  std::ifstream message_file(filename);

  if (not message_file or not message_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo\n";
    return 1;
  }

  std::cout << "----- INICIO DO ARQUIVO -----" << std::endl;

  std::string message;

  while (std::getline(message_file, message)) {
    std::cout << message << std::endl;
  }

  std::cout << "----- FIM DO ARQUIVO -------" << std::endl;

  message_file.close();

  return 0;
}

short handle_add(int argc, vector_string args) {
  std::string message;

  if (argc == 2) {
    std::cout << "Digite uma mensagem:\n";
    while (std::getline(std::cin, message) and not message.length()) continue;
  }

  if (not message.length()) {
    message = args.at(2);
  }

  if (write_message_to_file(FILE_NAME, message) != 0) {
    return 1;
  }

  std::cout << "Mensagem adicionada com sucesso!\n";

  return 0;
}

short handle_list() {
  if (read_message_from_file(FILE_NAME) != 0) {
    return 1;
  }

  return 0;
}
