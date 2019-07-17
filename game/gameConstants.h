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

std::vector<std::unique_ptr<Move>> specialMoveList;

void fillSpecialMoveList(std::vector<std::unique_ptr<Move>> &);

/* Move List */

std::vector<std::unique_ptr<Move>> moveList;

void fillMoveList(std::vector<std::unique_ptr<Move>> &);

/* Hackerdex */
std::map<Type, std::vector<Species>> hackerdex = {
  { NORMAL,
    std::vector<Species> {
      Species("Brown Puppy",
        *specialMoveList.at(BROWN_PUPPY),
        Stats(90, 6, 5, 8),
        std::vector<Family>{Family(NORMAL)}),
      Species("Sleepy Sloth",
        *specialMoveList.at(SLEEPY_SLOTH),
        Stats(130, 5, 4, 3),
        std::vector<Family>{Family(NORMAL)})}
  },
  { FIRE,
    std::vector<Species> {
      Species("Spicy Lizard",
        *specialMoveList.at(SPICY_LIZARD),
        Stats(120, 7, 5, 7),
        std::vector<Family>{Family(FIRE)}),
      Species("Flaming Dog",
        *specialMoveList.at(FLAMING_DOG),
        Stats(140, 8, 6, 7),
        std::vector<Family>{Family(FIRE)})}
  },
  { WATER,
    std::vector<Species> {
      Species("Moist Turtle",
        *specialMoveList.at(MOIST_TURTLE),
        Stats(120, 6, 6, 8),
        std::vector<Family>{Family(WATER)}),
      Species("Slow Duck",
        *specialMoveList.at(SLOW_DUCK),
        Stats(100, 4, 6, 4),
        std::vector<Family>{Family(WATER)})}
  },
  { ELECTRIC,
    std::vector<Species> {
      Species("Sparky Mouse",
        *specialMoveList.at(SPARKY_MOUSE),
        Stats(150, 7, 7, 7),
        std::vector<Family>{Family(ELECTRIC)}),
      Species("Exploding Orb",
        *specialMoveList.at(EXPLODING_ORB),
        Stats(140, 8, 2, 5),
        std::vector<Family>{Family(ELECTRIC)})}
  },
  { GRASS,
    std::vector<Species> {
      Species("Bulb Dinosaur",
        *specialMoveList.at(BULB_DINOSAUR),
        Stats(120, 5, 8, 7),
        std::vector<Family>{Family(GRASS)}),
      Species("Dancing Flower",
        *specialMoveList.at(DANCING_FLOWER),
        Stats(100, 5, 5, 9),
        std::vector<Family>{Family(GRASS)})}
  },
  { FIGHTING,
    std::vector<Species> {
      Species("Karate Kid",
        *specialMoveList.at(KARATE_KID),
        Stats(130, 8, 7, 7),
        std::vector<Family>{Family(FIGHTING)}),
      Species("Monkey Man",
        *specialMoveList.at(MONKEY_MAN),
        Stats(170, 6, 5, 8),
        std::vector<Family>{Family(FIGHTING)})}
  },
  { GROUND,
    std::vector<Species> {
      Species("Rock Guy",
        *specialMoveList.at(ROCK_GUY),
        Stats(120, 5, 9, 6),
        std::vector<Family>{Family(GROUND)}),
      Species("Armless Groundhog",
        *specialMoveList.at(ARMLESS_GROUNDHOG),
        Stats(150, 6, 6, 6),
        std::vector<Family>{Family(GROUND)})}
  },
  { PSYCHIC,
    std::vector<Species> {
      Species("Spoon Wizard",
        *specialMoveList.at(SPOON_WIZARD),
        Stats(180, 7, 5, 6),
        std::vector<Family>{Family(PSYCHIC)}),
      Species("Voodoo Anteater",
        *specialMoveList.at(VOODOO_ANTEATER),
        Stats(140, 5, 8, 7),
        std::vector<Family>{Family(PSYCHIC)})}
  }
};

/* Item List*/
std::vector<std::unique_ptr<Item>> itemList;

void fillItemList(std::vector<std::unique_ptr<Item>> &);
#endif
