#include "mobile.h"

using namespace std;

Mobile::Mobile(Hackmon & _h) : Mobility(_h) {
  duration = -1;
}

bool Mobile::canMoveOverride() const {
  return true;
}