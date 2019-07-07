#ifndef PARALYSIS_H
#define PARALYSIS_H

#include "mobility.h"

class Paralysis: public Mobility {
    virtual bool canMoveOverride() const override;
  public:
    Paralysis();
};

#endif