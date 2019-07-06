#ifndef MOVE_H
#define MOVE_H

#include <string>

#include "action.h"
#include "family.h"


class Move: public Action {
protected:
  Hackmon *hackmon; // Non-owning pointer
  const size_t accuracy; // The percent chance that the move will hit. A value between 1 and 100 inclusive
  const Family family;

public:
  void attachHackmon(Hackmon *hackmon);

  Move(const std::string name, const Scope scope, const size_t accuracy, const Family family);
};

#endif
