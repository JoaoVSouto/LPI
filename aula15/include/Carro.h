#ifndef CARRO_H
#define CARRO_H

#include <string>

#include "Motor.h"

class Carro {
 public:
  std::string tipo;
  std::string placa;
  std::string cor;
  int num_portas;
  int velocidade;
  Motor motor;

  static int quantidade_carros;

  Carro();
  Carro(std::string cor);

  void acelerar(int velocidade);
  void freiar(int velocidade);
  void ligar();
};

#endif  // !CARRO_H
