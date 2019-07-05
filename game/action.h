#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <vector>

class Player;

class Action {
  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const = 0;

public:
  enum Scope {
    SINGLE,
    ALL
  };
  const std::string name;
  const Scope scope;

  void doAction(Player &player, const std::vector<size_t> &targets) const;

  Action(const std::string name, const Scope scope);
};

#endif
