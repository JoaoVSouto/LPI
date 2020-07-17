#ifndef VECTOR_MARKET_H
#define VECTOR_MARKET_H

#include <cstddef>
#include <iterator>

template <class T>
class VectorMarket {
 private:
  T* array;
  std::size_t array_size;
  std::size_t array_capacity;
  void double_capacity();

 public:
  VectorMarket();
  ~VectorMarket();

  T& operator[](std::size_t pos);

  void push_back(T e);
  T back();
  T front();
  bool empty();
  void pop_back();
  std::size_t size();
  T* begin();
  T* end();
};

#include "../src/VectorMarket.cpp"

#endif  // !VECTOR_MARKET_H
