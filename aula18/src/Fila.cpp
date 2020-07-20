#include "../include/Fila.h"

#include <algorithm>
#include <iostream>

template <class T>
Fila<T>::Fila() : queue(nullptr), queue_size(0), queue_capacity(2) {
  this->queue = new T[this->queue_capacity];
}

template <class T>
Fila<T>::~Fila() {
  delete[] this->queue;
}

template <class T>
void Fila<T>::push(T e) {
  if (this->queue_size >= this->queue_capacity) {
    this->double_capacity();
  }

  this->queue[this->queue_size] = e;
  this->queue_size += 1;
}

template <class T>
T Fila<T>::back() {
  return this->queue[this->queue_size - 1];
}

template <class T>
T Fila<T>::front() {
  return this->queue[0];
}

template <class T>
bool Fila<T>::empty() {
  return this->queue_size == 0;
}

template <class T>
void Fila<T>::pop() {
  if (this->empty()) {
    return;
  }

  for (std::size_t i = 0; i < this->queue_size - 1; ++i) {
    this->queue[i] = this->queue[i + 1];
  }

  this->queue_size -= 1;
}

template <class T>
std::size_t Fila<T>::size() {
  return this->queue_size;
}

template <class T>
void Fila<T>::double_capacity() {
  this->queue_capacity *= 2;

  T* temp_array = new T[this->queue_capacity];
  std::copy(this->queue, this->queue + this->queue_size, temp_array);

  delete[] this->queue;
  this->queue = temp_array;
}
