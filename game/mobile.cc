#include "mobile.h"

using namespace std;

Mobile::Mobile(Hackmon & _h) : Mobility(_h) {}

bool Mobile::canMoveOverride() {
  return true;
}

MobilityName Mobile::name() const {
  return MOBILE;
}

unique_ptr<Mobility> Mobile::clone() const {
  return make_unique<Mobile>(*this);
}
