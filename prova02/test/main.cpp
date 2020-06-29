#include <iostream>

#include "../include/Diary.h"

int main(int argc, char const* argv[]) {
  Diary diary("../diary.md");

  // for (size_t i = 0; i < diary.messages_size; i++) {
  //   std::cout << "- " << diary.messages[i].date.to_string()
  //             << " " << diary.messages[i].time.to_string()
  //             << " " << diary.messages[i].content << std::endl;
  // }

  return 0;
}
