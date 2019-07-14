#include <string>
#include <iostream>
#include <vector>

#include "hackmon.h"
#include "move.h"
#include "species.h"
#include "stats.h"
using namespace std;

template<typename T>
void getValidValue(T inVar, T rangeMin, T rangeMax) {
  while (cin >> inVar) {
    if (inVar > rangeMin && inVar < rangeMax) break;
    else cout << "...Uh oh, that's not an option. Try again! (" << rangeMin+1 << "<= # <= " << rangeMax-1 << ")" << endl;
  }
}

int main() {
  char cmd;
  string p1;
  string p2;
  unsigned numberBattling;

  char hackmonSelect;
  int hackmonNumber;

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

  while (cin >> cmd && cmd != 'q') {
    // pregame -----------------------------------------------------------------
    cout << "Now your story begins..." << endl;
    cout << "Hello there! Welcome to the world of HACKMON!" << endl;
    cout << "My name is ROB HACKMAN! People call me the HACKMON PROF!" << endl;
    cout << "This world is inhabited by creatures called HACKMON!" << endl;
    cout << "For some people, HACKMON are pets. Others use them for fights." << endl;
    cout << "Myself...I study HACKMON as a profession. First, what is your name? (player 1)" << endl;
    cin >> p1;
    cout << "Right! So your name is" << p1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> p2;

    cout << "Your very own Pokemon legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with Pokemon Awaits! Let’s go!" << endl;

    cout << "Would you like to battle 1 v 1 or 2 v 2? (1/2)" << endl;
    while (cin >> numberBattling) {
      if (numberBattling == 1 || numberBattling == 2) break;
      else cout << "...Uh oh, that's not an option. Try again! (1/2)" << endl;
    }

    cout << "...Okay! It’s time to get started!" << endl;

    for (int i=0; i<2; i++) {
      cout << (i==0 ? p1 : p2) << " why don't you pick your Hackmon! You can choose 6 in your party." << endl;
      cout << "You can either select a Hackmon from our Hackerdex or create your own!" << endl;

      for (int j=0; j<6; j++) {
        cout << "For Hackmon #" << i+1 << ", would you like to see the Hackerdex (h) or create your own (o)? (h/o)" << endl;

        while (cin >> hackmonSelect) {
          if (hackmonSelect == 'h' || hackmonSelect == 'o') break;
          else cout << "...Uh oh, that's not an option. Try again! (h/o)" << endl;
        }

        if (hackmonSelect == 'h') {
          // print out Hackerdex with numbers beside it

          cout << "Which Hackmon would you like to select? (1 <= # <= 20)" << endl;
          getValidValue(hackmonNumber, 0, 21);

          cout << "Great! " << /* hackerdex[hackmonNumber].name */ << "has been added to your party!" << endl;

        }
        else if (hackmonSelect == 'o') {
          cout << "What would you like the name of your species to be?" << endl;
          cin >> newHackmonSpecies;

          cout << "Here is a list of the 8 Hackmon types:" << endl;
          cout << /* type list */ << endl;
          cout << "Which type would you like your species to belong to? (1 <= # <= 8)" << endl;
          getValidValue(newHackmonType, 0, 9);
          newHackmonFamily.emplace_back(/* family object - typeList[newHackmonType] */);

          cout << "What would you like the name of your Hackmon to be?" << endl;
          cin >> newHackmonName;

          cout << "Here is a list of the # Hackmon moves:" << endl;
          cout << /* type move list */ << endl;
          cout << "Now please select a special move for your Hackmon based on the type" << endl;
          cin >> newHackmonSpecialMove;

          cout << "Here is a list of the # Hackmon moves:" << endl;
          cout << /* move list */ << endl;
          cout << "Which moves would you like your Hackmon to have? Please type 3 numbers separated by spaces (1 <= # <= ?)" << endl;
          for (int k=0; k<3; k++) {
            cin >> newHackmonMove;
            newHackmonMoves.emplace_back(/*MoveList[newHackmonMove]*/);
          }

          cout << "Now lets set your Hackmon stats." << endl;
          cout << "What would you like your maximum health points(HP) to be? (1 <= # <= 200)" << endl;
          getValidValue(newHackmonHp, 0, 201);

          cout << "What would you like your base attack level to be? (1 <= # <= 10)" << endl;
          getValidValue(newHackmonAttack, 0, 11);

          cout << "What would you like your base defense level to be? (1 <= # <= 10)" << endl;
          getValidValue(newHackmonDefense, 0, 11);

          cout << "What would you like your base speed level to be? (1 <= # <= 10)" << endl;
          getValidValue(newHackmonSpeed, 0, 11);

          Species createdHackmonSpecies(
            newHackmonSpecies,
            /*type move list[newHackmonSpecialMove]*/,
            Stats(newHackmonHp, newHackmonAttack, newHackmonDefense, newHackmonSpeed),
            newHackmonFamily,
          );
          // add species to species list

          Hackmon newHackmon = createdHackmonSpecies.createHackmon(newHackmonMoves, newHackmonName);

          cout << "Great! " << newHackmonName << " has been added to your party!" << endl;
        }
      }
    }

    // each player pick hackmon
    //     -> option to create own hackmon


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
