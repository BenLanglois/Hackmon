#ifndef GAME_CONSTANTS_H_
#define GAME_CONSTANTS_H_

#include <map>
#include <vector>
#include <string>

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

// Hackmon Type to String
const std::map<Type, std::string> typeString = {
  {NORMAL, "Normal"},
  {FIRE, "Fire"},
  {WATER, "Water"},
  {ELECTRIC, "Electric"},
  {GRASS, "Grass"},
  {FIGHTING, "Fighting"},
  {GROUND, "Ground"},
  {PSYCHIC, "Psychic"}
};

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

/* Hackerdex */
std::map<Type, std::vector<Species>> hackerdex = {
  { NORMAL,
    std::vector<Species> {
      Species(std::string("Brown Puppy"),
        specialMoveList.at(BROWN_PUPPY),
        Stats(90, 6, 5, 8),
        std::vector<Family>{Family(NORMAL)}),
      Species(std::string("Sleepy Sloth"),
        specialMoveList.at(SLEEPY_SLOTH),
        Stats(130, 5, 4, 3),
        std::vector<Family>{Family(NORMAL)})}
  },
  { FIRE,
    std::vector<Species> {
      Species(std::string("Spicy Lizard"),
        specialMoveList.at(SPICY_LIZARD),
        Stats(120, 7, 5, 7),
        std::vector<Family>{Family(FIRE)}),   
      Species(std::string("Flaming Dog"),
        specialMoveList.at(FLAMING_DOG),
        Stats(140, 8, 6, 7),
        std::vector<Family>{Family(FIRE)})}
  },
  { WATER,
    std::vector<Species> {  
      Species(std::string("Moist Turtle"),
        specialMoveList.at(MOIST_TURTLE),
        Stats(120, 6, 6, 8),
        std::vector<Family>{Family(WATER)}),   
      Species(std::string("Slow Duck"),
        specialMoveList.at(SLOW_DUCK),
        Stats(100, 4, 6, 4),
        std::vector<Family>{Family(WATER)})}
  },
  { ELECTRIC,
    std::vector<Species> {
      Species(std::string("Sparky Mouse"),
        specialMoveList.at(SPARKY_MOUSE),
        Stats(150, 7, 7, 7),
        std::vector<Family>{Family(ELECTRIC)}),   
      Species(std::string("Exploding Orb"),
        specialMoveList.at(EXPLODING_ORB),
        Stats(140, 8, 2, 5),
        std::vector<Family>{Family(ELECTRIC)})}
  },
  { GRASS,
    std::vector<Species> {
      Species(std::string("Bulb Dinosaur"),
        specialMoveList.at(BULB_DINOSAUR),
        Stats(120, 5, 8, 7),
        std::vector<Family>{Family(GRASS)}),   
      Species(std::string("Dancing Flower"),
        specialMoveList.at(DANCING_FLOWER),
        Stats(100, 5, 5, 9),
        std::vector<Family>{Family(GRASS)})}
  },
  { FIGHTING, 
    std::vector<Species> {
      Species(std::string("Karate Kid"),
        specialMoveList.at(KARATE_KID),
        Stats(130, 8, 7, 7),
        std::vector<Family>{Family(FIGHTING)}),   
      Species(std::string("Monkey Man"),
        specialMoveList.at(MONKEY_MAN),
        Stats(170, 6, 5, 8),
        std::vector<Family>{Family(FIGHTING)})}
  },
  { GROUND,
    std::vector<Species> {
      Species(std::string("Rock Guy"),
        specialMoveList.at(ROCK_GUY),
        Stats(120, 5, 9, 6),
        std::vector<Family>{Family(GROUND)}),   
      Species(std::string("Armless Groundhog"),
        specialMoveList.at(ARMLESS_GROUNDHOG),
        Stats(150, 6, 6, 6),
        std::vector<Family>{Family(GROUND)})}
  },
  { PSYCHIC,  
    std::vector<Species> {
      Species(std::string("Spoon Wizard"),
        specialMoveList.at(SPOON_WIZARD),
        Stats(180, 7, 5, 6),
        std::vector<Family>{Family(PSYCHIC)}),   
      Species(std::string("Voodoo Anteater"),
        specialMoveList.at(VOODOO_ANTEATER),
        Stats(140, 5, 8, 7),
        std::vector<Family>{Family(PSYCHIC)})}
  }
};

/* Special Move List */ 

std::vector<Move> specialMoveList = {
  StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 5),
  MobilityMove(std::string("Yawn"), SINGLE, 100, Family(NORMAL), SLEEP),
  StatMove(std::string("Fire Spin"), SINGLE, 100, Family(FIRE), HP, 5),
  DebuffMove(std::string("Heat Wave"), ALL, 50, Family(FIRE), Debuff(BURNED)),
  StatMove(std::string("Surf"), ALL, 100, Family(WATER), HP, 5),
  StatMove(std::string("Water Gun"), SINGLE, 90, Family(WATER), HP, 5),
  MobilityMove(std::string("Thunder Shock"), SINGLE, 80, Family(ELECTRIC), PARALYSIS),
  StatMove(std::string("Self-Destruct"), ALL, 100, Family(ELECTRIC), HP, 5),
  StatMove(std::string("Vine Whip"), SINGLE, 70, Family(GRASS), HP, 4),
  DebuffMove(std::string("Poison Thorn"), SINGLE, 100, Family(GRASS), Debuff(POISONED)),
  StatMove(std::string("Seismic Toss"), SINGLE, 60, Family(FIGHTING), HP, 5),
  StatMove(std::string("Low Kick"), SINGLE, 80, Family(FIGHTING), HP, 4),
  StatMove(std::string("Rock Slide"), ALL, 100, Family(GROUND), ATTACK, 3),
  StatMove(std::string("Sand Attack"), ALL, 100, Family(GROUND), DEFENSE, 1),
  MobilityMove(std::string("Psybeam"), SINGLE, 100, Family(PSYCHIC), CONFUSION),
  MobilityMove(std::string("Hypnosis"), SINGLE, 100, Family(PSYCHIC), SLEEP)
};

/* Move List */

std::vector<Move> moveList = {
  // normal
  StatMove(std::string("Growl"), SINGLE, 100, Family(NORMAL), ATTACK, 2),
  StatMove(std::string("Quick Attack"), SINGLE, 100, Family(NORMAL), HP, 4),
  StatMove(std::string("Swift"), SINGLE, 100, Family(NORMAL), SPEED, 3),
  StatMove(std::string("Defense Curl"), SINGLE, 60, Family(NORMAL), DEFENSE, 2),
  MobilityMove(std::string("Smokescreen"), SINGLE, 100, Family(NORMAL), CONFUSION),
  // fire
  StatMove(std::string("Flamethrower"), SINGLE, 100, Family(FIRE), HP, 2),
  StatMove(std::string("Fire Blast"), ALL, 80, Family(FIRE), HP, 3),
  StatMove(std::string("Overheat"), SINGLE, 100, Family(FIRE), ATTACK, 1),
  MobilityMove(std::string("Heat Wave"), ALL, 50, Family(FIRE), CONFUSION),
  DebuffMove(std::string("Ember"), SINGLE, 100, Family(FIRE), Debuff(BURNED)),
  // water
  StatMove(std::string("Waterfall"), ALL, 50, Family(WATER), HP, 5),
  StatMove(std::string("Bubble Beam"), SINGLE, 100, Family(WATER), DEFENSE, 1),
  StatMove(std::string("Aqua Jet"), SINGLE, 80, Family(WATER), SPEED, 3),
  MobilityMove(std::string("Splishy Splash"), SINGLE, 50, Family(WATER), PARALYSIS),
  DebuffMove(std::string("Icy Wind"), SINGLE, 100, Family(WATER), Debuff(FROZEN)),
  // electric
  StatMove(std::string("Shock Wave"), ALL, 60, Family(ELECTRIC), DEFENSE, 5),
  StatMove(std::string("Zap Cannon"), SINGLE, 80, Family(ELECTRIC), HP, 4),
  StatMove(std::string("Charge"), SINGLE, 100, Family(ELECTRIC), ATTACK, 2),
  StatMove(std::string("Thunder Wave"), ALL, 70, Family(ELECTRIC), HP, 3),
  MobilityMove(std::string("Discharge"), SINGLE, 100, Family(ELECTRIC), PARALYSIS),
  // grass
  StatMove(std::string("Leaf Storm"), ALL, 80, Family(GRASS), HP, 2),
  StatMove(std::string("Magical Leaf"), SINGLE, 60, Family(GRASS), DEFENSE, 5),
  StatMove(std::string("Charge"), SINGLE, 100, Family(GRASS), ATTACK, 2),
  DebuffMove(std::string("Stink Bomb"), ALL, 40, Family(GRASS), Debuff(POISONED)),
  MobilityMove(std::string("Sleep Powder"), SINGLE, 100, Family(GRASS), SLEEP),
  // fighting
  StatMove(std::string("Hammer Arm"), SINGLE, 90, Family(FIGHTING), SPEED, 2),
  StatMove(std::string("Double Kick"), ALL, 80, Family(FIGHTING), HP, 3),
  StatMove(std::string("Rock Smash"), SINGLE, 70, Family(FIGHTING), DEFENSE, 3),
  StatMove(std::string("Close Combat"), SINGLE, 100, Family(FIGHTING), ATTACK, 4),
  MobilityMove(std::string("Force Palm"), SINGLE, 100, Family(FIGHTING), PARALYSIS),
  // ground
  StatMove(std::string("Sand Attack"), SINGLE, 100, Family(GROUND), DEFENSE, 1),
  StatMove(std::string("Earthquake"), ALL, 60, Family(GROUND), HP, 3),
  StatMove(std::string("Stealth Rock"), SINGLE, 70, Family(GROUND), ATTACK, 3),
  DebuffMove(std::string("Quicksand"), SINGLE, 80, Family(GROUND), Debuff(FROZEN)),
  MobilityMove(std::string("Smack Down"), SINGLE, 50, Family(GROUND), CONFUSION),
  // psychic
  StatMove(std::string("Trick"), SINGLE, 80, Family(PSYCHIC), ATTACK, 1),
  StatMove(std::string("Barrier Break"), ALL, 60, Family(PSYCHIC), DEFENSE, 3),
  StatMove(std::string("Psywave"), ALL, 100, Family(PSYCHIC), HP, 2),
  MobilityMove(std::string("Telekinesis"), SINGLE, 50, Family(PSYCHIC), PARALYSIS),
  MobilityMove(std::string("Confusion"), ALL, 40, Family(PSYCHIC), CONFUSION) 
};

#endif
