#include <iostream>

#include "../include/Diary.h"

int main(int argc, char const* argv[]) {
  Diary diary("diary.md");

  for (size_t i = 0; i < 50; ++i) {
    diary.add(std::to_string(i) + ". lorem");
  }

  for (size_t i = 0; i < diary.messages_capacity; ++i) {
    Message& m = diary.messages[i];

    std::cout << m.date.to_string() << " "
              << m.time.to_string() << " "
              << m.content << std::endl;
  }

  return 0;
}
