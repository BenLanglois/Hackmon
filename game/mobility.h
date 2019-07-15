#ifndef MOBILITY_H_
#define MOBILITY_H_

#include "randomGen.h"
#include "mobilityInfo.h"

class Hackmon;

class Mobility {
    virtual bool canMoveOverride() = 0;
    virtual MobilityName name() const = 0;
  protected:
    Hackmon& hackmon;
  public:
    bool canMove();
    Mobility(Hackmon &);
    bool operator==(Mobility &);
    virtual ~Mobility() = 0;
};

#endif
