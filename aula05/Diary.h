#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

struct Diary {
  Message messages[];

  bool add_new_message(const Message& message);
  void list_messages();
};

#endif  // !DIARY_H
