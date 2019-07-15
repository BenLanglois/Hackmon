#include "sleep.h"
#include "mobile.h"

Sleep::Sleep(Hackmon & h) : Mobility{h}, rng{RandomGenerator(5,10)}, duration{rng.getRandom()} {}

bool Sleep::canMoveOverride() {
  --duration;
  // continues until set duration
  if(duration == 0) {
    hackmon.mobility.reset(new Mobile(hackmon));
    return true;
  } 
  return false;
}
