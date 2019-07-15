#ifndef PARALYSIS_H_
#define PARALYSIS_H_

#include "mobility.h"
#include "randomGen.h"

class Paralysis: public Mobility {
    RandomGenerator rng;
    virtual bool canMoveOverride() override;
  public:
    Paralysis(Hackmon &);
    virtual MobilityName name() const override;
    virtual std::unique_ptr<Mobility> clone() const override;
};

#endif
