#include "mobile.h"

using namespace std;

Mobile::Mobile(Hackmon & _h) : Mobility(_h) {}

bool Mobile::canMoveOverride() {
  return true;
}