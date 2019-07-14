#ifndef MOBILITY_H_
#define MOBILITY_H_

#include "randomGen.h"

#include "hackmon.h";

class Mobility {
    virtual bool canMoveOverride() const = 0;
  protected:
    Hackmon& hackmon;
    int duration;
  public:
    bool canMove() const;
    Mobility(Hackmon &);
};

#endif