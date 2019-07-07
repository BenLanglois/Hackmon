#ifndef ITEM_H
#define ITEM_H

#include <vector>

class Player;

class Item {
    virtual void doAction() const = 0;
  public:
    Item();
};

#endif