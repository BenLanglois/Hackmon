#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

#include "action.h"

class Hackmon;

class Item: public Action {
  virtual void useItemOverride(Hackmon &) const = 0;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override final;
public:
  Item(const std::string, const Scope);
  virtual ~Item() = 0;
};

#endif
