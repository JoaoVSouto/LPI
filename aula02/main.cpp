#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string const FIRST_ARG = "add";

  if (argc == 1 || FIRST_ARG.compare(argv[1]) != 0) {
    std::cout << "Uso: " << argv[0] << " " << FIRST_ARG << " <mensagem>\n";
    return -1;
  }

  if (argc == 2) {
    std::string mensagem;

    std::cout << "Digite uma mensagem:\n";
    std::getline(std::cin, mensagem);

    std::cout << "Mensagem adicionada!\n"
              << mensagem << "\n";
  } else {
    std::cout << "Mensagem adicionada!\n"
              << argv[2] << "\n";
  }

  return 0;
}
