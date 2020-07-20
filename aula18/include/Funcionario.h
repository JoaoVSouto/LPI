#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
 private:
  std::string nome;
  std::string id_cadastro;
  double salario;

 public:
  Funcionario();
  Funcionario(std::string nome, std::string id_cadastro, double salario);

  void set_nome(std::string nome);
  std::string get_nome();
  void set_id_cadastro(std::string id_cadastro);
  std::string get_id_cadastro();
  void set_salario(double salario);
  double get_salario();
};

#endif  // !FUNCIONARIO_H
