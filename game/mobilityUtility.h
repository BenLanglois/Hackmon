#ifndef MOBILITY_UTILITY_H
#define MOBILITY_UTILITY_H

#include <memory>

#include "mobilityInfo.h"
#include "mobile.h"
#include "confusion.h"
#include "paralysis.h"
#include "sleep.h"

class Mobility;

std::unique_ptr<Mobility> toMobility(MobilityName mobilityName, Hackmon &hackmon) {
  switch (mobilityName) {
    case MOBILE:
      return std::make_unique<Mobile>(hackmon);
    case CONFUSION:
      return std::make_unique<Confusion>(hackmon);
    case PARALYSIS:
      return std::make_unique<Paralysis>(hackmon);
    case SLEEP:
      return std::make_unique<Sleep>(hackmon);
  }
}

#endif
