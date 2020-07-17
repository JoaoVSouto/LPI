#include "../include/VectorMarket.h"

#include <algorithm>

#ifndef VECTOR_MARKET_CPP
#define VECTOR_MARKET_CPP

template <class T>
VectorMarket<T>::VectorMarket() : array(nullptr), array_size(0), array_capacity(2) {
  this->array = new T[this->array_capacity];
}

template <class T>
VectorMarket<T>::~VectorMarket() {
  delete[] this->array;
}

template <class T>
T& VectorMarket<T>::operator[](std::size_t pos) {
  return *(this->array + pos);
}

template <class T>
void VectorMarket<T>::push_back(T e) {
  if (this->array_size >= this->array_capacity) {
    this->double_capacity();
  }

  this->array[this->array_size] = e;
  this->array_size += 1;
}

template <class T>
T VectorMarket<T>::back() {
  return this->array[this->array_size - 1];
}

template <class T>
T VectorMarket<T>::front() {
  return this->array[0];
}

template <class T>
bool VectorMarket<T>::empty() {
  return this->array_size == 0;
}

template <class T>
void VectorMarket<T>::pop_back() {
  if (this->empty()) {
    return;
  }

  this->array_size -= 1;
}

template <class T>
std::size_t VectorMarket<T>::size() {
  return this->array_size;
}

template <class T>
void VectorMarket<T>::double_capacity() {
  this->array_capacity *= 2;

  T* temp_array = new T[this->array_capacity];
  std::copy(this->begin(), this->end(), temp_array);

  delete[] this->array;
  this->array = temp_array;
}

template <class T>
T* VectorMarket<T>::begin() {
  return &this->array[0];
}

template <class T>
T* VectorMarket<T>::end() {
  return &this->array[this->array_size];
}

#endif  // !VECTOR_MARKET_CPP
