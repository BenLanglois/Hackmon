#ifndef CONFUSION_H
#define CONFUSION_H

#include "mobility.h"
#include "randomGen.h"

class Confusion: public Mobility {
    RandomGenerator rng;
    int damage;
    unsigned duration;
    virtual bool canMoveOverride() override;
  public:
    Confusion(Hackmon &);
    virtual MobilityName name() const override;
    virtual std::unique_ptr<Mobility> clone() const override;
};

#endif
