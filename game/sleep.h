#ifndef SLEEP_H_
#define SLEEP_H_

#include "mobility.h"
#include "randomGen.h"

class Sleep: public Mobility {
    virtual bool canMoveOverride() override;
    RandomGenerator rng;
    unsigned duration;
  public:
    Sleep(Hackmon &);
    virtual MobilityName name() const override;
    virtual std::unique_ptr<Mobility> clone() const override;
};

#endif
