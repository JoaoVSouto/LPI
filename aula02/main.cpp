#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string const FIRST_ARG = "add";

  if (argc == 1 || FIRST_ARG.compare(argv[1]) != 0) {
    std::cout << "Uso: " << argv[0] << " " << FIRST_ARG << " <mensagem>\n";
    return -1;
  }

  std::string mensagem;

  if (argc == 2) {
    std::cout << "Digite uma mensagem:\n";
    while (std::getline(std::cin, mensagem) && not mensagem.length()) continue;
  }

  std::cout << "Mensagem adicionada!\n"
            << (mensagem.length() ? mensagem : argv[2]) << "\n";

  return 0;
}
