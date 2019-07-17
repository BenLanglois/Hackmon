#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

#include "hackmon.h"
#include "player.h"
#include "move.h"
#include "species.h"
#include "stats.h"
#include "gameConstants.h"
#include "actionQueue.h"

using namespace std;

template<typename T>
void getValidValueRange(T& inVar, T rangeMin, T rangeMax) {
  while (cin >> inVar) {
    if (inVar >= rangeMin && inVar <= rangeMax) break;
    else cout << "...Uh oh, that's not an option. Try again! (" << rangeMin << "<= # <= " << rangeMax << ")" << endl;
  }
}

template <typename T>
bool _isOneOf(T key, T first) {
  return key == first;
}

template <typename T, typename... Rest>
bool _isOneOf(T key, T first, Rest... rest) {
  return key == first ? true : _isOneOf(key, rest...);
}

template <typename T>
void _printValues(T first) {
  cout << first;
}

template <typename T, typename... Rest>
void _printValues(T first, Rest... rest) {
  cout << first << "/";
  _printValues(rest...);
}

template <typename T, typename... Rest>
T getValidValueOneOf(Rest... values) {
  T inVar;
  while (cin >> inVar) {
    if (_isOneOf(inVar, values...)) break;
    else cout << "...Uh oh, that's not an option. Try again! (";
    _printValues(values...); // print out valid values
    cout << ")" << endl;
  }
  return inVar;
}

void printTypeList() {
  int i = 0;
  for (auto const& type : typeString) {
    cout << ++i << ". " << type.second << endl;
  }
}

void printMoveList() {
  int i = 0;
  for (auto& move : moveList) {
    cout << ++i << ". ";
    move->printMove();
    cout << endl;
  }
}

void printItemList() {
  int i = 0;
  for (auto& item : itemList) {
    cout << ++i << ". ";
    item->printItem();
    cout << endl;
  }
}

int main() {
  string name1;
  string name2;
  unsigned numberBattling;
  vector<unique_ptr<Hackmon>> party1;
  vector<unique_ptr<Hackmon>> party2;
  vector<unique_ptr<Item>> items1;
  vector<unique_ptr<Item>> items2;

  int numberParty = 6;
  int numberOfItems = 3;
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
    cout << "Right! So your name is" << name1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> name2;

    cout << "Your very own HACKMON legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with HACKMON Awaits! Let’s go!" << endl;

    while (playerLoop) {
      cout << "Would you like to battle 1 vs 1 or 2 vs 2? (1/2)" << endl;
      numberBattling = getValidValueOneOf<int>(1, 2);

      cout << "...Okay! It’s time to get started!" << endl;

      for (int p=0; p<2; p++) {
        // reset party unique pointers

        cout << (p==0 ? name1 : name2) << " why don't you pick your HACKMON! You can choose " << numberParty << " in your party." << endl;
        cout << "You can either select a HACKMON from our Hackerdex or create your own!" << endl;

        for (int h=0; h<numberParty; h++) {
          char hackmonSelect;
          int hackmonType;
          int hackmonNumber;
          char wantNameHackmon;
          string hackmonName;
          int hackmonMove;
          vector<unique_ptr<Move>> hackmonMoves;

          string newHackmonSpecies;
          string newHackmonName;
          vector<Family> newHackmonFamily;
          int newHackmonSpecialMove;
          int newHackmonHp;
          int newHackmonAttack;
          int newHackmonDefense;
          int newHackmonSpeed;

          Species* speciesToUse;
          int itemNumber;

          cout << "For HACKMON #" << h+1 << ", would you like to see the Hackerdex (h) or create your own (o)? (h/o)" << endl;
          hackmonSelect = getValidValueOneOf<char>('h', 'o');

          cout << "Here is a list of the 8 HACKMON types:" << endl;
          printTypeList();
          cout << "Which type would you like your HACKMON to be? (1 <= # <= 8)" << endl;
          getValidValueRange(hackmonType, 1, 8);

          if (hackmonSelect == 'h') {
            // print out Hackerdex with numbers beside it
            cout << "Which HACKMON would you like to select? (1 <= # <= 20)" << endl;
            getValidValueRange(hackmonNumber, 1, 20);
          } else {

            newHackmonFamily.emplace_back(Family((Type)hackmonType)); // FIXME: remove casting
            cout << "What would you like the name of your species to be?" << endl;
            cin >> newHackmonSpecies;
          }

          cout << "Awesome! Would you like to name your HACKMON? (y/n)" << endl;
          wantNameHackmon = getValidValueOneOf<char>('y', 'n');

          if (wantNameHackmon == 'y') {
            cout << "What would you like the name of your HACKMON to be?" << endl;
            cin >> hackmonName;
          }

          int numberOfMovesToSelect = (hackmonSelect == 'h') ? 3 : 4;
          cout << "Here is a list of the " << moveList.size() << " HACKMON moves:" << endl;
          printMoveList();
          cout << "Which moves would you like your HACKMON to have? Please type " << numberOfMovesToSelect;
          cout  << " numbers separated by spaces (1 <= # <= " << moveList.size() << ")" << endl;
          for (int k=0; k<3; k++) {
            getValidValueRange(hackmonMove, 1, (int)moveList.size()-1); // FIXME: remove casting
            hackmonMoves.emplace_back(make_unique<Move>(moveList.at(hackmonMove-1)));
          }

          if (numberOfMovesToSelect == 4) {
            getValidValueRange(newHackmonSpecialMove, 1, (int)moveList.size()-1); // FIXME: remove casting
          }

          if (hackmonSelect == 'o') {
            cout << "Now lets set your HACKMON stats." << endl;
            cout << "What would you like your maximum health points(HP) to be? (1 <= # <= 200)" << endl;
            getValidValueRange(newHackmonHp, 1, 200);

            cout << "What would you like your base attack level to be? (1 <= # <= 10)" << endl;
            getValidValueRange(newHackmonAttack, 1, 10);

            cout << "What would you like your base defense level to be? (1 <= # <= 10)" << endl;
            getValidValueRange(newHackmonDefense, 1, 10);

            cout << "What would you like your base speed level to be? (1 <= # <= 10)" << endl;
            getValidValueRange(newHackmonSpeed, 1, 10);

            Species createdHackmonSpecies(
              newHackmonSpecies,
              *moveList.at(newHackmonSpecialMove),
              Stats(newHackmonHp, newHackmonAttack, newHackmonDefense, newHackmonSpeed),
              newHackmonFamily
            );

            hackerdex.at((Type)hackmonType).emplace_back(createdHackmonSpecies);
            speciesToUse = &createdHackmonSpecies; // FIXME: get from species list
          } else {
            speciesToUse = &hackerdex.at((Type)hackmonType).back();
          }

          Hackmon newHackmon = speciesToUse->createHackmon(move(hackmonMoves), hackmonName);

          if (p==0) party1.emplace_back(newHackmon); else party2.emplace_back(newHackmon);
          cout << "Great! " << newHackmon.name << "has been added to your party!" << endl << endl;

          cout << "Now, lets select some items to put in your bag! Here is a list of the available items" << endl;
          printItemList();
          cout << "Which items would you like to select? Please type " << numberOfItems;
          cout  << " numbers separated by spaces (1 <= # <= " << itemList.size() << ")" << endl;
          for (int k=0; k<numberOfItems; k++) {
            getValidValueRange(itemNumber, 1, (int)itemList.size()-1); // FIXME: remove cast
            if (p==0) items1.emplace_back(make_unique<Item>(itemList.at(itemNumber-1))); else items2.emplace_back(itemList.at(itemNumber-1));
          }
        }
      }

      Player p1(name1, move(party1), move(items1));
      Player p2(name2, move(party2), move(items2));

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

        for (int p=0; p<2; p++) {
          Player &curPlayer = (p==0 ? p1 : p2);

          cout << "Now " << curPlayer.name << ", lets choose your starting HACKMON!" << endl;
          cout << "Here is a list of your chose HACKMON!" << endl;
          curPlayer.printParty();

          cout << "Please select " << numberBattling << "HACKMON from your list above" << (numberBattling > 1 ? " (separated by spaces)." : ".") << endl;
          for (unsigned m=0; m<numberBattling; m++) {
            cin >> inBattleIndex;
            inBattleIndexes.emplace_back(inBattleIndex);
          }

          // make sure first (numberBattling) indexes in array are the starting hackmon
          for (unsigned m=0; m<numberBattling; m++) {
            if ((unsigned)inBattleIndexes.at(m) != m) {
              curPlayer.swapHackmon(m, inBattleIndexes.at(m));
            }
          }

          // FIXME: clear screen to hide p1 starting pokemon
        }

        // loop (check if all pokemon of one player have fainted)
        int loopCounter = 0;
        cout << "Time to battle!" << endl;

        const int itemPriority = 99;
        const int switchPriority = 100; // We all know that numbers stop at 100

        while (p1.partyAlive() && p2.partyAlive()) {
          cout << "-------- ROUND " << ++loopCounter << " --------" << endl << endl;

          // choose move/use item/swap for each hackmon
          ActionQueue actionQueue;
          for (int p=0; p<2; ++p) {
            Player &currPlayer = (p == 0 ? p1 : p2);
            vector<Action*> &currPlayerActions = (p == 0 ? p1Actions : p2Actions);

            for (unsigned h=0; h<numberBattling; ++h) {
              cout << currPlayer.name << " please select for " << currPlayer.party.at(h)->name << endl;

              char action;
              if (currPlayer.items.size() != 0) {
                // Able to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << "Will you make a move against your oppoent, use an item, "
                       << "or swap out your HACKMON with another in your party? (m/i/s)" << endl;
                  action = getValidValueOneOf<char>('m', 'i', 's');
                } else {
                  // Unable to switch
                  cout << "Will you make a move against your oppoent or use an item? (m/i) " << endl;
                  action = getValidValueOneOf<char>('m', 'i');
                }
              } else {
                // Unable to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << "Will you make a move against your oppoent "
                       << "or swap out your HACKMON with another in your party? (m/s)" << endl;
                  action = getValidValueOneOf<char>('m', 's');
                } else {
                  // Unable to switch
                  action = 'm';
                }
              }


              if (action == 'm') {
                  // output list of moves
                  cout << "Here is a list of the available moves:" << endl;
                  for (size_t moveIndex = 0; moveIndex < currPlayer.party.at(h)->moves.size(); ++moveIndex) {
                    // Give one-indexed list of moves
                    cout << moveIndex+1 << ": " << currPlayer.party.at(h)->moves.at(moveIndex)->name << endl;
                  }

                  // pick one from list
                  size_t selectedMoveIndex;
                  getValidValueRange(selectedMoveIndex, static_cast<size_t>(0), currPlayer.party.at(h)->moves.size()+1);
                  --selectedMoveIndex; // Make zero-indexed

                  // add to playerMove vector
                  currPlayerActions.emplace_back(currPlayer.party.at(h)->moves.at(selectedMoveIndex));

              } else if (action == 'i') {
                // output list of items
                cout << "Here is a list of the available moves:" << endl;

                // pick one from list
                // add to pMove vector

              } else {
                // output list of hackmon from numberBattling to end
                // pick one from list
                // call p.swapHackmon on indices
              }
            }
          }


          // implement items
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
        playAgain = getValidValueOneOf<char>('y', 'n');

        if (playAgain == 'y') {
          cout << "Would you like to battle with the same HACKMON? (y/n)" << endl;
          keepHackmon = getValidValueOneOf<char>('y', 'n');

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
