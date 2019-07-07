#ifndef STATS_H
#define STATS_H

class Stats {
  public:
    const int maxHp;
    const int baseAttack;
    const int baseDefense;
    const int baseSpeed;
    int hp;
    int attack;
    int defense;
    int speed;

    Stat(const int mapHp, const int baseAttack, const int baseDefense, const int baseSpeed, int hp, int attack, int defense, int speed):
      maxHp{maxHp}, baseAttack{baseAttack}, baseDefense{baseDefense}, baseSpeed{baseSpeed}, hp{hp}, attack{attack},
      defense{defense}, speed{defense};
};

#endif
