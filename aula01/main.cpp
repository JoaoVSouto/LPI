#include <iostream>

int main(int argc, char const *argv[]) {
  int n1, n2;

  std::cout << "Informe dois números:\n";
  std::cin >> n1 >> n2;

  int result = n1 + n2;

  std::cout << "A soma dos números é " << result << "\n";

  return 0;
}
