#ifndef MOBILITY_H_
#define MOBILITY_H_

#include <memory>

#include "randomGen.h"
#include "mobilityInfo.h"

class Hackmon;

class Mobility {
    virtual bool canMoveOverride() = 0;
  protected:
    Hackmon& hackmon;
  public:
    bool canMove();
    Mobility(Hackmon &);
    virtual MobilityName name() const = 0;
    virtual ~Mobility() = 0;
    virtual std::unique_ptr<Mobility> clone() const = 0;
};

#endif
