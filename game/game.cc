#include <string>
#include <iostream>
#include <vector>

#include "hackmon.h"
#include "move.h"
#include "species.h"
#include "stats.h"
using namespace std;

template<typename T>
void getValidValueRange(T inVar, T rangeMin, T rangeMax) {
  while (cin >> inVar) {
    if (inVar > rangeMin && inVar < rangeMax) break;
    else cout << "...Uh oh, that's not an option. Try again! (" << rangeMin+1 << "<= # <= " << rangeMax-1 << ")" << endl;
  }
}

template<typename R>
void getValidValueOneOf(R inVar, R a, R b) {
  while (cin >> inVar) {
    if (inVar == a || inVar == b) break;
    else cout << "...Uh oh, that's not an option. Try again! (" << a << "/" << b << ")" << endl;
  }
}

int main() {
  char cmd;
  string p1;
  string p2;
  unsigned numberBattling;

  while (cin >> cmd && cmd != 'q') {
    // pregame -----------------------------------------------------------------
    cout << "Now your story begins..." << endl;
    cout << "Hello there! Welcome to the world of HACKMON!" << endl;
    cout << "My name is ROB HACKMAN! People call me the HACKMON PROF!" << endl; // FIXME: add timers to these statementd
    cout << "This world is inhabited by creatures called HACKMON!" << endl;
    cout << "For some people, HACKMON are pets. Others use them for fights." << endl;
    cout << "Myself...I study HACKMON as a profession. First, what is your name? (player 1)" << endl;
    cin >> p1;
    cout << "Right! So your name is" << p1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> p2;

    cout << "Your very own Pokemon legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with Pokemon Awaits! Let’s go!" << endl;

    cout << "Would you like to battle 1 vs 1 or 2 vs 2? (1/2)" << endl;
    getValidValueOneOf(numberBattling, (unsigned)1, (unsigned)2); // FIXME: remove casting?

    cout << "...Okay! It’s time to get started!" << endl;

    for (int i=0; i<2; i++) {
      cout << (i==0 ? p1 : p2) << " why don't you pick your HACKMON! You can choose 6 in your party." << endl;
      cout << "You can either select a HACKMON from our Hackerdex or create your own!" << endl;

      for (int j=0; j<6; j++) {
        char hackmonSelect;

        cout << "For HACKMON #" << i+1 << ", would you like to see the Hackerdex (h) or create your own (o)? (h/o)" << endl;
        getValidValueOneOf(hackmonSelect, 'h', 'o');

        if (hackmonSelect == 'h') {
          int hackmonType;
          int hackmonNumber;
          char wantNameHackmon;
          string hackmonName;
          int hackmonMove;
          vector<unique_ptr<Move>> hackmonMoves;

          cout << "Here is a list of the 8 HACKMON types:" << endl;
          cout << /* type list */ << endl;
          cout << "Which type would you like your HACKMON to be? (1 <= # <= 8)" << endl;
          getValidValueRange(hackmonType, 0, 9);

          // print out Hackerdex with numbers beside it
          cout << "Which HACKMON would you like to select? (1 <= # <= 20)" << endl;
          getValidValueRange(hackmonNumber, 0, 21);

          cout << "Awesome! Would you like to name your HACKMON? (y/n)"
          getValidValueOneOf(wantNameHackmon, 'y', 'n');

          if (wantNameHackmon == 'y') {
            cout << "What would you like the name of your HACKMON to be?" << endl;
            cin >> hackmonName;
          }

          cout << "Here is a list of the # HACKMON moves:" << endl;
          cout << /* move list */ << endl;
          cout << "Which moves would you like your HACKMON to have? Please type 3 numbers separated by spaces (1 <= # <= ?)" << endl;
          for (int k=0; k<3; k++) {
            cin >> hackmonMove; // FIXME: add num check
            hackmonMoves.emplace_back(/*MoveList[hackmonMove]*/);
          }

          Hackmon newHackmon = /*typelist[hackmonType].hackmonNumber*/.createdHackmon(hackmonMoves, hackmonName);

          cout << "Great! " << newHackmon.name << "has been added to your party!" << endl << endl;

        }
        else if (hackmonSelect == 'o') {
          string newHackmonSpecies;
          string newHackmonName;
          int newHackmonType;
          int newHackmonMove;
          int newHackmonSpecialMove;
          vector<unique_ptr<Move>> newHackmonMoves;
          vector<Family> newHackmonFamily;
          int newHackmonHp;
          int newHackmonAttack;
          int newHackmonDefense;
          int newHackmonSpeed;

          cout << "What would you like the name of your species to be?" << endl;
          cin >> newHackmonSpecies;

          cout << "Here is a list of the 8 HACKMON types:" << endl;
          cout << /* type list */ << endl;
          cout << "Which type would you like your species to belong to? (1 <= # <= 8)" << endl;
          getValidValueRange(newHackmonType, 0, 9);
          newHackmonFamily.emplace_back(/* family object - typeList[newHackmonType] */);

          cout << "What would you like the name of your HACKMON to be?" << endl;
          cin >> newHackmonName;

          cout << "Here is a list of the # HACKMON moves:" << endl;
          cout << /* type move list */ << endl;
          cout << "Now please select a special move for your HACKMON based on the type" << endl;
          cin >> newHackmonSpecialMove;

          cout << "Here is a list of the # HACKMON moves:" << endl;
          cout << /* move list */ << endl;
          cout << "Which moves would you like your HACKMON to have? Please type 3 numbers separated by spaces (1 <= # <= ?)" << endl;
          for (int k=0; k<3; k++) {
            cin >> newHackmonMove;
            newHackmonMoves.emplace_back(/*MoveList[newHackmonMove]*/);
          }

          cout << "Now lets set your HACKMON stats." << endl;
          cout << "What would you like your maximum health points(HP) to be? (1 <= # <= 200)" << endl;
          getValidValueRange(newHackmonHp, 0, 201);

          cout << "What would you like your base attack level to be? (1 <= # <= 10)" << endl;
          getValidValueRange(newHackmonAttack, 0, 11);

          cout << "What would you like your base defense level to be? (1 <= # <= 10)" << endl;
          getValidValueRange(newHackmonDefense, 0, 11);

          cout << "What would you like your base speed level to be? (1 <= # <= 10)" << endl;
          getValidValueRange(newHackmonSpeed, 0, 11);

          Species createdHackmonSpecies(
            newHackmonSpecies,
            /*type move list[newHackmonSpecialMove]*/,
            Stats(newHackmonHp, newHackmonAttack, newHackmonDefense, newHackmonSpeed),
            newHackmonFamily,
          );
          // add species to species list

          Hackmon newHackmon = createdHackmonSpecies.createHackmon(newHackmonMoves, newHackmonName);

          cout << "Great! " << newHackmonName << " has been added to your party!" << endl << endl;
        }
      }
    }


    // battle ------------------------------------------------------------------
    // show players all chosen hackmon
    // players choose starting pokemon

    // loop (check if all pokemon of one player have fainted)
      // choose move/use item/swap for each hackmon
      // implement swap first
      // then items
      // then move - order based on hackmon speed
      // output active hackmon stats
    // output winner


    // postgame ----------------------------------------------------------------
    // option to play again (y/n)
    // keep same hackmon (y/n)
    // back to beginming of loop
  }
}

// cout << "" << endl;
