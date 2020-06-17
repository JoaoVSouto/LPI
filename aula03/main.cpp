#include <fstream>
#include <iostream>
#include <string>

short write_message_to_file(std::string const& filename, std::string const& message);

int main(int argc, char const* argv[]) {
  std::string const FIRST_ARG = "add";

  if (argc == 1 or FIRST_ARG.compare(argv[1]) != 0) {
    std::cout << "Uso: " << argv[0] << " " << FIRST_ARG << " <mensagem>\n";
    return 1;
  }

  std::string message;

  if (argc == 2) {
    std::cout << "Digite uma mensagem:\n";
    while (std::getline(std::cin, message) and not message.length()) continue;
  }

  if (not message.length()) {
    message = argv[2];
  }

  if (write_message_to_file("entries.txt", message) != 0) {
    std::cout << "Erro: não foi possível abrir o arquivo\n";
    return 1;
  }

  std::cout << "Mensagem adicionada com sucesso!\n";

  return 0;
}

short write_message_to_file(std::string const& filename, std::string const& message) {
  std::ofstream message_file(filename, std::ios::app);

  if (not message_file or not message_file.is_open()) {
    return 1;
  }

  message_file << "- " << message << "\n";

  message_file.close();

  return 0;
}
