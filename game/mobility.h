#ifndef MOBILITY_H_
#define MOBILITY_H_

#include "randomGen.h"

#include "hackmon.h";

class Mobility {
    virtual bool canMoveOverride() = 0;
  protected:
    Hackmon& hackmon;
  public:
    bool canMove();
    Mobility(Hackmon &);
};

#endif