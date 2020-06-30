#ifndef APP_H
#define APP_H

#include <string>

#include "Diary.h"

struct App {
  Diary diary;

  App(const std::string& filename);

  int run(int argc, char const* argv[]);
  void add();
  void add(const std::string message);
  void list_messages();
  void search();
  void search(const std::string& what);
  int show_usage();
};

#endif  // !APP_H
