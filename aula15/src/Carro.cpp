#include "../include/Carro.h"

#include <iostream>

int Carro::quantidade_carros;

Carro::Carro() : cor("Branco") {
  this->quantidade_carros += 1;
}

Carro::Carro(std::string cor) : cor(cor) {
  this->quantidade_carros += 1;
}

void Carro::acelerar(int velocidade) {
  this->velocidade += velocidade;
}

void Carro::freiar(int velocidade) {
  this->velocidade -= velocidade;
}

void Carro::ligar() {
  this->motor.partida();
}
