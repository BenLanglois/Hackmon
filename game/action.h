#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <vector>

class Player;

class Action {
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const = 0;

public:
  enum Scope {
    SINGLE,
    ALL
  };
  const std::string name;
  const Scope scope;

  void doAction(Player &, const std::vector<size_t> &) const;

  Action(const std::string, const Scope);
};

#endif
