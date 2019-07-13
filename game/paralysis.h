#ifndef PARALYSIS_H_
#define PARALYSIS_H_

#include "mobility.h"

class Paralysis: public Mobility {
    virtual bool canMoveOverride() const override;
  public:
    Paralysis();
};

#endif