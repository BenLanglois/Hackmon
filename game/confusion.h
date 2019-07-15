#ifndef CONFUSION_H
#define CONFUSION_H

#include "mobility.h"
#include "randomGen.h"

class Confusion: public Mobility {
    RandomGenerator rng;
    int damage;
    int duration;
    virtual bool canMoveOverride() override;
    virtual MobilityName name() const override;
  public:
    Confusion(Hackmon &);
};

#endif
