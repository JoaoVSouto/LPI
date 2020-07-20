#ifndef FILA_H
#define FILA_H

#include <cstddef>

template <class T>
class Fila {
 private:
  T* queue;
  std::size_t queue_size;
  std::size_t queue_capacity;
  void double_capacity();

 public:
  Fila();
  ~Fila();

  void push(T e);
  T back();
  T front();
  bool empty();
  void pop();
  std::size_t size();
};

#endif  // !FILA_H
