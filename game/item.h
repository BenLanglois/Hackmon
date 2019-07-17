#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <memory>

#include "action.h"

class Hackmon;

class Item: public Action {
  virtual void useItemOverride(Hackmon &) const = 0;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override final;
public:
  const std::string name;
  const Scope scope;
  virtual std::unique_ptr<Item> clone() const = 0;
  Item(const std::string, const Scope);
};

#endif
