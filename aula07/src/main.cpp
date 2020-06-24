#include "../include/App.h"

int main(int argc, char const *argv[]) {
  App app("diary.md");

  return app.run(argc, argv);
}
