#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "hackmon.h"
#include "player.h"
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
  string name1;
  string name2;
  unsigned numberBattling;
  vector<unique_ptr<Hackmon>> party1;
  vector<unique_ptr<Hackmon>> party2;
  Player p1;
  Player p2;

  int numberParty = 6;
  bool gameLoop = true;
  bool battleLoop = true;
  bool playerLoop = true;

  while (gameLoop) {
    // pregame -----------------------------------------------------------------
    cout << "Now your story begins..." << endl;
    cout << "Hello there! Welcome to the world of HACKMON!" << endl;
    cout << "My name is ROB HACKMAN! People call me the HACKMON PROF!" << endl; // FIXME: add timers to these statementd
    cout << "This world is inhabited by creatures called HACKMON!" << endl;
    cout << "For some people, HACKMON are pets. Others use them for fights." << endl;
    cout << "Myself...I study HACKMON as a profession. First, what is your name? (player 1)" << endl;
    cin >> name1;
    cout << "Right! So your name is" << p1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> name2;

    cout << "Your very own HACKMON legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with HACKMON Awaits! Let’s go!" << endl;

    while (playerLoop) {
      cout << "Would you like to battle 1 vs 1 or 2 vs 2? (1/2)" << endl;
      getValidValueOneOf(numberBattling, (unsigned)1, (unsigned)2); // FIXME: remove casting?

      cout << "...Okay! It’s time to get started!" << endl;

      for (int i=0; i<2; i++) {
        cout << (i==0 ? name1 : name2) << " why don't you pick your HACKMON! You can choose " << numberParty << " in your party." << endl;
        cout << "You can either select a HACKMON from our Hackerdex or create your own!" << endl;

        for (int j=0; j<numberParty; j++) {
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

            if (i==0) party1.emplace_back(newHackmon); else party2.emplace_back(newHackmon);

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

            if (i==0) party1.emplace_back(newHackmon); else party2.emplace_back(newHackmon);

            cout << "Great! " << newHackmonName << " has been added to your party!" << endl << endl;
          }

          if (i==0) p1 = Player(name1, party1); else p2 = Player(name2, party2);
        }
      }

      while (battleLoop) {
        // battle ------------------------------------------------------------------
        cout << "It looks like you two trainers are ready to battle!" << endl; // FIXME: add timers to these statementd
        cout << "First lets see which HACKMON you've chosen!" << endl;
        // show players all chosen hackmon
        p1.printParty();
        p2.printParty();

        // players choose starting pokemon
        int inBattleIndex;
        vector<int> inBattleIndexes;

        for (int l=0; l<2; l++) {
          cout << "Now " << (l==0 ? p1.name : p2.name) << ", lets choose your starting HACKMON!" << endl;
          cout << "Here is a list of your chose HACKMON!" << endl;
          if (l==0) p1.printParty(); else p2.printParty();

          cout << "Please select " << numberBattling << "HACKMON from your list above" << (numberBattling > 1 ? " (separated by spaces)." : ".") << endl;
          for (unsigned m=0; m<numberBattling; m++) {
            cin >> inBattleIndex;
            inBattleIndexes.emplace_back(inBattleIndex);
          }

          // make sure first (numberBattling) indexes in array are the starting hackmon
          for (unsigned m=0; m<numberBattling; m++) {
            if (inBattleIndexes.at(m) != m) {
              if (l==0) p1.swapHackmon(m, inBattleIndexes.at(m)); else p2.swapHackmon(m, inBattleIndexes.at(m));
            }
          }

          // FIXME: clear screent to hide p1 starting pokemon
        }

        // loop (check if all pokemon of one player have fainted)
        int loopCounter = 1;
        cout << "Time to Battle!" << endl;
        while (p1.partyAlive() && p2.partyAlive()) {
          cout << "-------- ROUND " << loopCounter++ << " --------" << endl << endl;

          // choose move/use item/swap for each hackmon
          vector<Move> p1Moves; // FIXME: wrong implementation of vector of moves
          vecotr<Move> p2Moves;
          for (int p=0; p<2; p++) {
            for (unsigned h=0; h<numberBattling; h++) {
              cout << (p==0) ? p1.name : p2.name << " please select for ";
              cout << (p==0) ? *(p1.party.at(h)).name : *(p2.party.at(h)).name << endl;

              char action;
              cout << "Would you like to perform an action or swap out your HACKMON with another in your party? (a/s)" << endl;
              getValidValueOneOf(action, 'a', 's');

              if (action == 'a') {
                char moveItem;
                if ((p==0) ? p1.items.size() != 0 : p2.items.size() != 0) {
                  cout << "Would you like to move against your opponent or use an item? (m/i)" << endl;
                  getValidValueOneOf(moveItem, 'm', 'i');
                } else {
                  moveItem = 'm';
                }

                if (moveItem == 'm') {
                  cout << "Here is a list of the available moves" << endl;
                  // cout << /* moves list */ << endl;

                  // pick one from list
                  // add to pMove vector
                } else {
                  // output list of items
                  // pick one from list
                  // add to pMove vector
                }

              } else {
                // output list of hackmon from numberBattling to end
                // pick one from list
                // call p.swapHackmon on indices
              }
            }
          }

          // implement swap first
          // then items
          // then move - order based on hackmon speed
          // output active hackmon stats
        }

        // output winner
        string winner;
        if (!p1.partyAlive()) {
          winner = p2.name;
          p2.hasWon();
        } else {
          winner = p1.name;
          p1.hasWon();
        }

        // postgame ----------------------------------------------------------------
        char playAgain;
        char keepHackmon;

        cout << "ROB HACKMAN here! Congrats to " << winner << "for the win!" << endl; // FIXME: add timers to these statementd
        cout << "Here is the current scores:" << endl;
        cout << p1.name << ": " << p1.winTotal << endl;
        cout << p2.name << ": " << p2.winTotal << endl << endl;
        cout << "Would you two trainers like to battle again? (y/n)" << endl;
        getValidValueOneOf(playAgain, 'y', 'n');

        if (playAgain == 'y') {
          cout << "Would you like to battle with the same HACKMON? (y/n)" << endl;
          getValidValueOneOf(keepHackmon, 'y', 'n');

          if (keepHackmon == 'y') {
            // FIXME: reset Hackmon levels
            battleLoop = true;
          } else {
            battleLoop = false;
            playerLoop = true;
          }
        } else {
          battleLoop = false;
          playerLoop = false;
        }
      }
    }
  }
}

// cout << "" << endl;
