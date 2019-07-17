#ifndef GAME_CONSTANTS_H_
#define GAME_CONSTANTS_H_

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "type.h"
#include "hackmon.h"
#include "move.h"
#include "statMove.h"
#include "mobilityMove.h"
#include "debuffMove.h"
#include "family.h"
#include "stats.h"
#include "species.h"
#include "confusion.h"
#include "mobile.h"
#include "paralysis.h"
#include "sleep.h"
#include "potion.h"
#include "mobilityHeal.h"
#include "debuffHeal.h"

enum HACKERDEX_NAMES {
  BROWN_PUPPY,
  SLEEPY_SLOTH,
  SPICY_LIZARD,
  FLAMING_DOG,
  MOIST_TURTLE,
  SLOW_DUCK,
  SPARKY_MOUSE,
  EXPLODING_ORB,
  BULB_DINOSAUR,
  DANCING_FLOWER,
  KARATE_KID,
  MONKEY_MAN,
  ROCK_GUY,
  ARMLESS_GROUNDHOG,
  SPOON_WIZARD,
  VOODOO_ANTEATER
};
/* Special Move List */

extern std::vector<std::unique_ptr<Move>> specialMoveList;

void fillSpecialMoveList();

/* Move List */

extern std::vector<std::unique_ptr<Move>> moveList;

void fillMoveList();

/* Hackerdex */
extern std::map<Type, std::vector<Species>> hackerdex;

/* Item List*/
extern std::vector<std::unique_ptr<Item>> itemList;

void fillItemList();
#endif
