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

// Hackerdex
const std::map<Type, std::vector<Species>> hackerdex = {
  { NORMAL,
    std::vector<Species> {
      Species(std::string("Brown Puppy"),
        specialMoveList.at("Brown Puppy"),
        Stats(90, 6, 5, 8),
        std::vector<Family>{Family(NORMAL)}),
      Species(std::string("Sleepy Sloth"),
        specialMoveList.at("Sleepy Sloth"),
        Stats(130, 5, 4, 3),
        std::vector<Family>{Family(NORMAL)})}
  },
  { FIRE,
    std::vector<Species> {
      Species(std::string("Spicy Lizard"),
        specialMoveList.at("Spicy Lizard"),
        Stats(120, 7, 5, 7),
        std::vector<Family>{Family(FIRE)}),   
      Species(std::string("Flaming Dog"),
        specialMoveList.at("Flaming Dog"),
        Stats(140, 8, 6, 7),
        std::vector<Family>{Family(FIRE)})}
  },
  { WATER,
    std::vector<Species> {  
      Species(std::string("Moist Turtle"),
        specialMoveList.at("Moist Turtle"),
        Stats(120, 6, 6, 8),
        std::vector<Family>{Family(WATER)}),   
      Species(std::string("Slow Duck"),
        specialMoveList.at("Slow Duck"),
        Stats(100, 4, 6, 4),
        std::vector<Family>{Family(WATER)})}
  },
  { ELECTRIC,
    std::vector<Species> {
      Species(std::string("Sparky Mouse"),
        specialMoveList.at("Sparky Mouse"),
        Stats(150, 7, 7, 7),
        std::vector<Family>{Family(ELECTRIC)}),   
      Species(std::string("Exploding Orb"),
        specialMoveList.at("Exploding Orb"),
        Stats(140, 8, 2, 5),
        std::vector<Family>{Family(ELECTRIC)})}
  },
  { GRASS,
    std::vector<Species> {
      Species(std::string("Bulb Dinosaur"),
        specialMoveList.at("Bulb Dinosaur"),
        Stats(120, 5, 8, 7),
        std::vector<Family>{Family(GRASS)}),   
      Species(std::string("Dancing Flower"),
        specialMoveList.at("Dancing Flower"),
        Stats(100, 5, 5, 9),
        std::vector<Family>{Family(GRASS)})}
  },
  { FIGHTING, 
    std::vector<Species> {
      Species(std::string("Karate Kid"),
        specialMoveList.at("Karate Kid"),
        Stats(130, 8, 7, 7),
        std::vector<Family>{Family(FIGHTING)}),   
      Species(std::string("Monkey Man"),
        specialMoveList.at("Monkey Man"),
        Stats(170, 6, 5, 8),
        std::vector<Family>{Family(FIGHTING)})}
  },
  { GROUND,
    std::vector<Species> {
      Species(std::string("Rock Guy"),
        specialMoveList.at("Rock Guy"),
        Stats(120, 5, 9, 6),
        std::vector<Family>{Family(GROUND)}),   
      Species(std::string("Armless Groundhog"),
        specialMoveList.at("Armless Groundhog"),
        Stats(150, 6, 6, 6),
        std::vector<Family>{Family(GROUND)})}
  },
  { PSYCHIC,  
    std::vector<Species> {
      Species(std::string("Spoon Wizard"),
        specialMoveList.at("Spoon Wizard"),
        Stats(180, 7, 5, 6),
        std::vector<Family>{Family(PSYCHIC)}),   
      Species(std::string("Voodoo Anteater"),
        specialMoveList.at("Voodoo Anteater"),
        Stats(140, 5, 8, 7),
        std::vector<Family>{Family(PSYCHIC)})}
  }
};

// Move List
std::map<std::string, Move> specialMoveList = {
  { std::string("Brown Puppy"),
    StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 5)},
  { std::string("Sleepy Sloth"),
    MobilityMove(std::string("Yawn"), SINGLE, 100, Family(NORMAL), SLEEP)},
  { std::string("Spicy Lizard"),
    StatMove(std::string("Fire Spin"), SINGLE, 100, Family(FIRE), HP, 5)},
  { std::string("Flaming Dog"),
    DebuffMove(std::string("Heat Wave"), ALL, 50, Family(FIRE), BURNED)},
  { std::string("Moist Turtle"),
    StatMove(std::string("Surf"), ALL, 100, Family(WATER), HP, 5)},
  { std::string("Slow Duck"),
    StatMove(std::string("Water Gun"), SINGLE, 90, Family(WATER), HP, 5)},
  { std::string("Sparky Mouse"),
    MobilityMove(std::string("Thunder Shock"), SINGLE, 80, Family(ELECTRIC), PARALYSIS)},
  { std::string("Exploding Orb"),
    StatMove(std::string("Self-Destruct"), ALL, 100, Family(ELECTRIC), HP, 5)},
  { std::string("Bulb Dinosaur"),
    StatMove(std::string("Razor Leaf"), SINGLE, 70, Family(GRASS), HP, 4)},
  { std::string("Dancing Flower"),
    DebuffMove(std::string("Poison Jab"), SINGLE, 100, Family(GRASS), Debuff(POISONED))},
  { std::string("Karate Kid"),
    StatMove(std::string("Seismic Toss"), SINGLE, 60, Family(FIGHTING), HP, 5)},
  { std::string("Monkey Man"),
    StatMove(std::string("Low Kick"), SINGLE, 80, Family(FIGHTING), HP, 4)},
  { std::string("Rock Guy"),
    StatMove(std::string("Rock Slide"), ALL, 100, Family(GROUND), ATTACK, 3)},
  { std::string("Armless Groundhog"),
    StatMove(std::string("Sand Attack"), ALL, 100, Family(GROUND), DEFENSE, 1)},
  { std::string("Spoon Wizard"),
    MobilityMove(std::string("Psybeam"), SINGLE, 100, Family(PSYCHIC), CONFUSION)},
  { std::string("Voodoo Anteater"),
    MobilityMove(std::string("Dream Eater"), SINGLE, 100, Family(PSYCHIC), SLEEP)}
};

// Move List
std::map<Type, std::vector<Move>> moveList {
      DebuffMove(std::string(), SINGLE, 100, Family(GRASS), Debuff(POISONED))}
      StatMove(std::string(), SINGLE, 100, Family(NORMAL), DEFENSE, 5)}
      MobilityMove(std::string(), SINGLE, 100, Family(PSYCHIC), SLEEP)}

  { NORMAL,
    std::vector<Move>{
      // growl
      StatMove(std::string("Growl"), SINGLE, 100, Family(NORMAL), ATTACK, 2)}
      // quick attack
      StatMove(std::string("Quick Attack"), SINGLE, 100, Family(NORMAL), HP, 4)}
      // swift
      StatMove(std::string("Swift"), SINGLE, 100, Family(NORMAL), SPEED, 3)}
      // defense curl
      StatMove(std::string("Defense Curl"), SINGLE, 100, Family(NORMAL), DEFENSE, 2)}
      // 
      StatMove(std::string("Defense Curl"), SINGLE, 100, Family(NORMAL), DEFENSE, 2)}

    }
  },
  { FIRE,
    std::vector<Move>{

    }
  },
  { WATER,
    std::vector<Move>{

    }
  },
  { ELECTRIC,
    std::vector<Move>{

    }
  },
  { GRASS,
    std::vector<Move>{

    }
  },
  { FIGHTING,
    std::vector<Move>{

    }
  },
  { GROUND,
    std::vector<Move>{

    }
  },
  { PSYCHIC,
    std::vector<Move>{

    }
  }
}

// 
// normal
// - Brown Puppy
// - Sleepy Sloth
// fire
// - Spicy Lizard
// - Flaming Dog
// water
// - Moist Turtle
// - Slow Duck
// electric
// - Sparky Mouse
// - Exploding Orb
// grass
// - Bulb Dinosaur
// - Dancing Flower
// fighting
// - Karate Kid
// - Monkey Man
// ground
// - Rock Guy
// - Armless Groundhog
// psychic
// - Spoon Wizard
// - Voodoo Anteater
// Special Move List
#endif