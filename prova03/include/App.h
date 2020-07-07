#ifndef APP_H
#define APP_H

#include <string>

#include "Config.h"
#include "Diary.h"

struct App {
  Config config;
  Diary diary;

  App();

  int run(int argc, char const* argv[]);
  void add();
  void add(const std::string message);
  void list_messages(const std::string& format);
  void search();
  void search(const std::string& what);
  void interactive_mode();
  int show_usage();

 private:
  void show_menu();
};

#endif  // !APP_H
