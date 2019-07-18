#include <vector>
#include <string>
#include <memory>

#include "gameConstants.h"

using namespace std;

vector<unique_ptr<Move>> moveList;
vector<unique_ptr<Move>> specialMoveList;
vector<unique_ptr<Item>> itemList;

void fillSpecialMoveList() {
  specialMoveList.emplace_back(make_unique<StatMove>("Tail Whip", SINGLE, 100, Family(NORMAL), DEFENSE, 5));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Yawn", SINGLE, 100, Family(NORMAL), SLEEP));
  specialMoveList.emplace_back(make_unique<StatMove>("Fire Spin", SINGLE, 100, Family(FIRE), HP, 5));
  specialMoveList.emplace_back(make_unique<DebuffMove>("Heat Wave", ALL, 50, Family(FIRE), Debuff(BURNED)));
  specialMoveList.emplace_back(make_unique<StatMove>("Surf", ALL, 100, Family(WATER), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Water Gun", SINGLE, 90, Family(WATER), HP, 5));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Thunder Shock", SINGLE, 80, Family(ELECTRIC), PARALYSIS));
  specialMoveList.emplace_back(make_unique<StatMove>("Self-Destruct", ALL, 100, Family(ELECTRIC), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Vine Whip", SINGLE, 70, Family(GRASS), HP, 4));
  specialMoveList.emplace_back(make_unique<DebuffMove>("Poison Thorn", SINGLE, 100, Family(GRASS), Debuff(POISONED)));
  specialMoveList.emplace_back(make_unique<StatMove>("Seismic Toss", SINGLE, 60, Family(FIGHTING), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Low Kick", SINGLE, 80, Family(FIGHTING), HP, 4));
  specialMoveList.emplace_back(make_unique<StatMove>("Rock Slide", ALL, 100, Family(GROUND), ATTACK, 3));
  specialMoveList.emplace_back(make_unique<StatMove>("Sand Attack", ALL, 100, Family(GROUND), DEFENSE, 1));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Psybeam", SINGLE, 100, Family(PSYCHIC), CONFUSION));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Hypnosis", SINGLE, 100, Family(PSYCHIC), SLEEP));
}

void fillMoveList() {
    // normal
  moveList.emplace_back(make_unique<StatMove>("Growl", SINGLE, 100, Family(NORMAL), ATTACK, 2));
  moveList.emplace_back(make_unique<StatMove>("Quick Attack", SINGLE, 100, Family(NORMAL), HP, 4));
  moveList.emplace_back(make_unique<StatMove>("Swift", SINGLE, 100, Family(NORMAL), SPEED, 3));
  moveList.emplace_back(make_unique<StatMove>("Defense Curl", SINGLE, 60, Family(NORMAL), DEFENSE, 2));
  moveList.emplace_back(make_unique<MobilityMove>("Smokescreen", SINGLE, 100, Family(NORMAL), CONFUSION));
  // fire
  moveList.emplace_back(make_unique<StatMove>("Flamethrower", SINGLE, 100, Family(FIRE), HP, 2));
  moveList.emplace_back(make_unique<StatMove>("Fire Blast", ALL, 80, Family(FIRE), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Overheat", SINGLE, 100, Family(FIRE), ATTACK, 1));
  moveList.emplace_back(make_unique<MobilityMove>("Heat Wave", ALL, 50, Family(FIRE), CONFUSION));
  moveList.emplace_back(make_unique<DebuffMove>("Ember", SINGLE, 100, Family(FIRE), Debuff(BURNED)));
  // water
  moveList.emplace_back(make_unique<StatMove>("Waterfall", ALL, 50, Family(WATER), HP, 5));
  moveList.emplace_back(make_unique<StatMove>("Bubble Beam", SINGLE, 100, Family(WATER), DEFENSE, 1));
  moveList.emplace_back(make_unique<StatMove>("Aqua Jet", SINGLE, 80, Family(WATER), SPEED, 3));
  moveList.emplace_back(make_unique<MobilityMove>("Splishy Splash", SINGLE, 50, Family(WATER), PARALYSIS));
  moveList.emplace_back(make_unique<DebuffMove>("Icy Wind", SINGLE, 100, Family(WATER), Debuff(FROZEN)));
  // electric
  moveList.emplace_back(make_unique<StatMove>("Shock Wave", ALL, 60, Family(ELECTRIC), DEFENSE, 5));
  moveList.emplace_back(make_unique<StatMove>("Zap Cannon", SINGLE, 80, Family(ELECTRIC), HP, 4));
  moveList.emplace_back(make_unique<StatMove>("Charge", SINGLE, 100, Family(ELECTRIC), ATTACK, 2));
  moveList.emplace_back(make_unique<StatMove>("Thunder Wave", ALL, 70, Family(ELECTRIC), HP, 3));
  moveList.emplace_back(make_unique<MobilityMove>("Discharge", SINGLE, 100, Family(ELECTRIC), PARALYSIS));
  // grass
  moveList.emplace_back(make_unique<StatMove>("Leaf Storm", ALL, 80, Family(GRASS), HP, 2));
  moveList.emplace_back(make_unique<StatMove>("Magical Leaf", SINGLE, 60, Family(GRASS), DEFENSE, 5));
  moveList.emplace_back(make_unique<StatMove>("Charge", SINGLE, 100, Family(GRASS), ATTACK, 2));
  moveList.emplace_back(make_unique<DebuffMove>("Stink Bomb", ALL, 40, Family(GRASS), Debuff(POISONED)));
  moveList.emplace_back(make_unique<MobilityMove>("Sleep Powder", SINGLE, 100, Family(GRASS), SLEEP));
  // fighting
  moveList.emplace_back(make_unique<StatMove>("Hammer Arm", SINGLE, 90, Family(FIGHTING), SPEED, 2));
  moveList.emplace_back(make_unique<StatMove>("Double Kick", ALL, 80, Family(FIGHTING), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Rock Smash", SINGLE, 70, Family(FIGHTING), DEFENSE, 3));
  moveList.emplace_back(make_unique<StatMove>("Close Combat", SINGLE, 100, Family(FIGHTING), ATTACK, 4));
  moveList.emplace_back(make_unique<MobilityMove>("Force Palm", SINGLE, 100, Family(FIGHTING), PARALYSIS));
  // ground
  moveList.emplace_back(make_unique<StatMove>("Sand Attack", SINGLE, 100, Family(GROUND), DEFENSE, 1));
  moveList.emplace_back(make_unique<StatMove>("Earthquake", ALL, 60, Family(GROUND), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Stealth Rock", SINGLE, 70, Family(GROUND), ATTACK, 3));
  moveList.emplace_back(make_unique<DebuffMove>("Quicksand", SINGLE, 80, Family(GROUND), Debuff(FROZEN)));
  moveList.emplace_back(make_unique<MobilityMove>("Smack Down", SINGLE, 50, Family(GROUND), CONFUSION));
  // psychic
  moveList.emplace_back(make_unique<StatMove>("Trick", SINGLE, 80, Family(PSYCHIC), ATTACK, 1));
  moveList.emplace_back(make_unique<StatMove>("Barrier Break", ALL, 60, Family(PSYCHIC), DEFENSE, 3));
  moveList.emplace_back(make_unique<StatMove>("Psywave", ALL, 100, Family(PSYCHIC), HP, 2));
  moveList.emplace_back(make_unique<MobilityMove>("Telekinesis", SINGLE, 50, Family(PSYCHIC), PARALYSIS));
  moveList.emplace_back(make_unique<MobilityMove>("Confusion", ALL, 40, Family(PSYCHIC), CONFUSION));
}

void fillItemList() {
  // hp potion
  itemList.emplace_back(make_unique<Potion>("Potion", SINGLE, HP, 50));
  itemList.emplace_back(make_unique<Potion>("Super Potion", SINGLE, HP, 100));
  itemList.emplace_back(make_unique<Potion>("Multi-Potion", ALL, HP, 30));
  // mobility heals
  itemList.emplace_back(make_unique<MobilityHeal>("Awakening", SINGLE, SLEEP));
  itemList.emplace_back(make_unique<MobilityHeal>("Paralyze Heal", SINGLE, PARALYSIS));
  // debuff heals
  itemList.emplace_back(make_unique<DebuffHeal>("Antidote", SINGLE, POISONED));
  itemList.emplace_back(make_unique<DebuffHeal>("Burn Heal", SINGLE, BURNED));
  itemList.emplace_back(make_unique<DebuffHeal>("Ice Heal", SINGLE, FROZEN));
}

std::vector<Species> hackerdex;

void fillHackerdex() {
  hackerdex.emplace_back(
    Species("Brown Puppy",
      *specialMoveList.at(BROWN_PUPPY),
      Stats(17, 6, 5, 8),
      std::vector<Family>{Family(NORMAL)})
  );
  hackerdex.emplace_back(
    Species("Sleepy Sloth",
      *specialMoveList.at(SLEEPY_SLOTH),
      Stats(19, 5, 4, 3),
      std::vector<Family>{Family(NORMAL)})
  );
  hackerdex.emplace_back(
    Species("Spicy Lizard",
      *specialMoveList.at(SPICY_LIZARD),
      Stats(20, 7, 5, 7),
      std::vector<Family>{Family(FIRE)})
  );
  hackerdex.emplace_back(
    Species("Flaming Dog",
      *specialMoveList.at(FLAMING_DOG),
      Stats(22, 8, 6, 7),
      std::vector<Family>{Family(FIRE)})
  );
  hackerdex.emplace_back(
    Species("Moist Turtle",
      *specialMoveList.at(MOIST_TURTLE),
      Stats(22, 6, 6, 8),
      std::vector<Family>{Family(WATER)})
  );
  hackerdex.emplace_back(
    Species("Slow Duck",
      *specialMoveList.at(SLOW_DUCK),
      Stats(20, 4, 6, 4),
      std::vector<Family>{Family(WATER)})
  );
  hackerdex.emplace_back(
    Species("Sparky Mouse",
      *specialMoveList.at(SPARKY_MOUSE),
      Stats(18, 7, 7, 7),
      std::vector<Family>{Family(ELECTRIC)})
  );
  hackerdex.emplace_back(
    Species("Exploding Orb",
      *specialMoveList.at(EXPLODING_ORB),
      Stats(23, 8, 2, 5),
      std::vector<Family>{Family(ELECTRIC)})
  );
  hackerdex.emplace_back(
    Species("Bulb Dinosaur",
      *specialMoveList.at(BULB_DINOSAUR),
      Stats(21, 5, 8, 7),
      std::vector<Family>{Family(GRASS)})
  );
  hackerdex.emplace_back(
    Species("Dancing Flower",
      *specialMoveList.at(DANCING_FLOWER),
      Stats(22, 5, 5, 9),
      std::vector<Family>{Family(GRASS)})
  );
  hackerdex.emplace_back(
    Species("Karate Kid",
      *specialMoveList.at(KARATE_KID),
      Stats(18, 8, 7, 7),
      std::vector<Family>{Family(FIGHTING)})
  );
  hackerdex.emplace_back(
    Species("Monkey Man",
      *specialMoveList.at(MONKEY_MAN),
      Stats(20, 6, 5, 8),
      std::vector<Family>{Family(FIGHTING)})
  );
  hackerdex.emplace_back(
    Species("Rock Guy",
      *specialMoveList.at(ROCK_GUY),
      Stats(22, 5, 9, 6),
      std::vector<Family>{Family(GROUND)})
  );
  hackerdex.emplace_back(
    Species("Armless Groundhog",
      *specialMoveList.at(ARMLESS_GROUNDHOG),
      Stats(21, 6, 6, 6),
      std::vector<Family>{Family(GROUND)})
  );
  hackerdex.emplace_back(
    Species("Spoon Wizard",
      *specialMoveList.at(SPOON_WIZARD),
      Stats(19, 7, 5, 6),
      std::vector<Family>{Family(PSYCHIC)})
  );
  hackerdex.emplace_back(
    Species("Voodoo Anteater",
      *specialMoveList.at(VOODOO_ANTEATER),
      Stats(22, 5, 8, 7),
      std::vector<Family>{Family(PSYCHIC)})
  );

  vector<string> design;

  design.emplace_back("     __\n");
  design.emplace_back("(___()'`;\n");
  design.emplace_back("/,    /`\n");
  design.emplace_back("\\\\\"--\\\\\n");
  hackerdex.at(0).addArt(design);

  design.clear();
  design.emplace_back("     ^ ^\n");
  design.emplace_back(" (\"\\(-_-)/\")\n");
  design.emplace_back("    (( ))\n");
  design.emplace_back("((...) (...))\n");
  hackerdex.at(1).addArt(design);

  design.clear();
  design.emplace_back("       /\\\n");
  design.emplace_back("      p  q\n");
  design.emplace_back("  _\\| \\  / |/_\n");
  design.emplace_back("    \\//  \\/\n");
  design.emplace_back("     `|  |`\n");
  design.emplace_back("      |  | ,/_\n");
  design.emplace_back("  _\\, |  |//\\\n");
  design.emplace_back("   /\\|  ;/\n");
  design.emplace_back("     \\;  \\\n");
  design.emplace_back("       '. \\\n");
  design.emplace_back("  .-.    \\ |\n");
  design.emplace_back("  `   '.__//\n");
  design.emplace_back("       `\"`\n");
  hackerdex.at(2).addArt(design);

  design.clear();
  design.emplace_back("     /\\    /\\\n");
  design.emplace_back("  /\\/  \\/\\/  \\/\\\n");
  design.emplace_back("/   _______     \\\n");
  design.emplace_back("|  |    |    \\   |\n");
  design.emplace_back("|   \\   /  ^ |   /\n");
  design.emplace_back(" \\ / \\_/   0  \\ /\n");
  design.emplace_back("  /            \\\n");
  design.emplace_back(" /    ____      0\n");
  design.emplace_back("/      /  \\___ _/\n");
  hackerdex.at(3).addArt(design);

  design.clear();
  design.emplace_back("              __\n");
  design.emplace_back("   .,-;-;-,. /'_\\\n");
  design.emplace_back(" _/_/_/_|_\\_\\) /\n");
  design.emplace_back("'-<_><_><_><_>=/\\\n");
  design.emplace_back(" `/_/====/_/-'\\_\\\n");
  design.emplace_back("  \"\"     \"\"    \"\"\n");
  hackerdex.at(4).addArt(design);

  design.clear();
  design.emplace_back("          ..\n");
  design.emplace_back("         ( '`<\n");
  design.emplace_back("          )(\n");
  design.emplace_back("   ( ----'  '.\n");
  design.emplace_back("   (         ;\n");
  design.emplace_back("    (_______,'\n");
  design.emplace_back("~^~^~^~^~^~^~^~^~\n");
  hackerdex.at(5).addArt(design);

  design.clear();
  design.emplace_back("          ___\n");
  design.emplace_back(" _  _  .-'   '-.\n");
  design.emplace_back("(.)(.)/         \\\n");
  design.emplace_back(" /@@             ;\n");
  design.emplace_back("o_\\-mm-......-mm`~~~~~~\n");
  hackerdex.at(6).addArt(design);

  design.clear();
  design.emplace_back("        ,--.!,\n");
  design.emplace_back("     __/   -*-\n");
  design.emplace_back("   ,d08b.  '|`\n");
  design.emplace_back("   0088MM\n");
  design.emplace_back("   `9MMP'\n");
  hackerdex.at(7).addArt(design);

  design.clear();
  design.emplace_back(" ,--.\n");
  design.emplace_back("`.`_.`\\\n");
  design.emplace_back("     \\ \\\n");
  design.emplace_back("      \\ \\\n");
  design.emplace_back("       \\ \\\n");
  design.emplace_back("        \\ `-''^^^^^''-.\n");
  design.emplace_back("         \\             `-._\n");
  design.emplace_back("         >>   >  <  <__    ^'-----...,,_\n");
  design.emplace_back("        //__/`---'\\__\\`'\"\"\"\"'\"'\"'\"'''''``\n");
  design.emplace_back("       `\"`\"\"      `\"\"`\"\n");
  hackerdex.at(8).addArt(design);

  design.clear();
  design.emplace_back("         __/)\n");
  design.emplace_back("      .-(__(=:\n");
  design.emplace_back("   |\\ |    \\)\n");
  design.emplace_back("   \\ ||\n");
  design.emplace_back("    \\||\n");
  design.emplace_back("     \\|\n");
  design.emplace_back("      |\n");
  hackerdex.at(9).addArt(design);

  design.clear();
  design.emplace_back("  ,.\n");
  design.emplace_back("  \\-'__\n");
  design.emplace_back(" / o.__o____\n");
  design.emplace_back(" \\/_/ /.___/--,\n");
  design.emplace_back("   ||\\'\n");
  design.emplace_back("   | /\n");
  design.emplace_back("   \\_\\\n");
  design.emplace_back("   -''\n");
  hackerdex.at(10).addArt(design);

  design.clear();
  design.emplace_back("      __\n");
  design.emplace_back(" w  c(..)o   (\n");
  design.emplace_back("  \\__(-)    __)\n");
  design.emplace_back("      /\\   (\n");
  design.emplace_back("     /(_)___)\n");
  design.emplace_back("     w /|\n");
  design.emplace_back("      | \\\n");
  design.emplace_back("      m  m\n");
  hackerdex.at(11).addArt(design);

  design.clear();
  design.emplace_back("    _______\n");
  design.emplace_back("---'   ____)\n");
  design.emplace_back("      (_____)\n");
  design.emplace_back("      (_____)\n");
  design.emplace_back("      (____)\n");
  design.emplace_back("---.__(___)\n");
  hackerdex.at(12).addArt(design);

  design.clear();
  design.emplace_back("    ....,\n");
  design.emplace_back("   /     \\\n");
  design.emplace_back("   | |   |\n");
  design.emplace_back("   0,    |\n");
  design.emplace_back("  ,|     |,\n");
  design.emplace_back(":\":\":\":\":\":\":\n");
  hackerdex.at(13).addArt(design);

  design.clear();
  design.emplace_back("     __/\\__\n");
  design.emplace_back(". _  \\''//\n");
  design.emplace_back("-( )-/_||_\\\n");
  design.emplace_back(" .'. \\_()_/\n");
  design.emplace_back("  |   | . \\\n");
  design.emplace_back("  |   | .  \\\n");
  design.emplace_back(" .'. ,\\_____'.\n");
  hackerdex.at(14).addArt(design);

  design.clear();
  design.emplace_back("       _.---._    /\\\\\n");
  design.emplace_back("    ./'       \"--`\\//\n");
  design.emplace_back("  ./              o \\\\\n");
  design.emplace_back(" /./\\  )______   \\__ \\\\\n");
  design.emplace_back("./  / /\\ \\   | \\ \\  \\ \\\n");
  design.emplace_back("   / /  \\ \\  | |\\ \\  \\7\\\n");
  design.emplace_back("    "     "    "  "\n");
  hackerdex.at(15).addArt(design);
}

vector<string> RobHackman;

void fillRobHackman() {
  RobHackman.emplace_back("           .--\"\"-.");
  RobHackman.emplace_back("          /   ..  \\");
  RobHackman.emplace_back("         |___|__|_|____");
  RobHackman.emplace_back("         | /_   _`|");
  RobHackman.emplace_back("         \\( O \\ O )");
  RobHackman.emplace_back("          |    > |");
  RobHackman.emplace_back("          |\\ \\_/ /");
  RobHackman.emplace_back("          | \\___/|");
  RobHackman.emplace_back("      ___/:      :\\__");
  RobHackman.emplace_back("    /`   \\:      :/  `\\");
  RobHackman.emplace_back("   /     `\\      /`    \\");
  RobHackman.emplace_back("  ;        '\\  /'.___.  ;");
  RobHackman.emplace_back("  |          \\/  |ROB|  |");
  RobHackman.emplace_back("  |   |          \\___/  |");
}

vector<string> HackmonTitle;

void fillTitle() {
  HackmonTitle.emplace_back("  _    _            _                          ");
  HackmonTitle.emplace_back(" | |  | |          | |                         ");
  HackmonTitle.emplace_back(" | |__| | __ _  ___| | ___ __ ___   ___  _ __  ");
  HackmonTitle.emplace_back(" |  __  |/ _` |/ __| |/ / '_ ` _ \\ / _ \\| '_ \\ ");
  HackmonTitle.emplace_back(" | |  | | (_| | (__|   <| | | | | | (_) | | | |");
  HackmonTitle.emplace_back(" |_|  |_|\\__,_|\\___|_|\\_\\_| |_| |_|\\___/|_| |_|");
}
