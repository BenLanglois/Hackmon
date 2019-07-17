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
#include "globalConstants.h"
#include "actionQueue.h"
#include "switch.h"

using namespace std;

template<typename T>
void getValidValueRange(T& inVar, T rangeMin, T rangeMax) {
  while (true) {
    if ((cin >> inVar) && inVar >= rangeMin && inVar <= rangeMax) {
      break;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "...Uh oh, that's not an option. Try again! (" << rangeMin << "<= # <= " << rangeMax << ")" << endl;
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

void printHackerdexAtType(int t) {
  int i = 0;
  vector<Species> speciesForType = hackerdex.at((Type)t);
  for (auto& sp : speciesForType) {
    cout << ++i << ". ";
    cout << sp.speciesName << endl;
  }
}

int main() {
  fillSpecialMoveList();
  fillMoveList();
  fillItemList();
  fillHackerdex();

  string name1;
  string name2;
  vector<unique_ptr<Hackmon>> party1;
  vector<unique_ptr<Hackmon>> party2;
  vector<unique_ptr<Item>> items1;
  vector<unique_ptr<Item>> items2;

  bool gameLoop = true;
  bool battleLoop = true;
  bool playerLoop = true;

  while (gameLoop) {
    // pregame -----------------------------------------------------------------
    cout << "\033c" << endl; // clears terminal
    cout << "Now your story begins..." << endl;
    cout << "Hello there! Welcome to the world of HACKMON!" << endl;
    cout << "My name is ROB HACKMAN! People call me the HACKMON PROF!" << endl; // FIXME: add timers to these statementd
    cout << "This world is inhabited by creatures called HACKMON!" << endl;
    cout << "For some people, HACKMON are pets. Others use them for fights." << endl;
    cout << "Myself...I study HACKMON as a profession." << endl << endl;
    cout << "First, what is your name? (player 1)" << endl;
    cin >> name1;
    cout << endl << "Right! So your name is " << name1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> name2;

    cout << endl << "Your very own HACKMON legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with HACKMON Awaits! Let’s go!" << endl << endl;

    while (playerLoop) {
      name1 = "";
      name2 = "";
      party1.clear();
      party2.clear();
      items1.clear();
      items2.clear();

      cout << "Would you like to battle 1 vs 1 or 2 vs 2? (1/2)" << endl;
      numberBattling = getValidValueOneOf<int>(1, 2);

      cout << "...Okay! It’s time to get started!" << endl;

      for (int p=0; p<2; p++) {
        // reset party unique pointers
        int itemNumber;

        cout << endl << endl << (p==0 ? name1 : name2) << " why don't you pick your HACKMON! You can choose " << numberParty << " in your party." << endl;
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

          cout << endl << "For HACKMON #" << h+1 << ", would you like to see the Hackerdex (h) or create your own (o)? (h/o)" << endl;
          hackmonSelect = getValidValueOneOf<char>('h', 'o');

          cout << endl << "Here is a list of the 8 HACKMON types:" << endl;
          printTypeList();
          cout << "Which type would you like your HACKMON to be? (1 <= # <= 8)" << endl;
          getValidValueRange(hackmonType, 1, 8);
          --hackmonType;

          if (hackmonSelect == 'h') {
            cout << endl << "Here is a list of the HACKMON of type " << typeString.at((Type)hackmonType) << "." << endl;
            printHackerdexAtType(hackmonType);
            cout << "Which HACKMON would you like to select? (1 <= # <= " << hackerdex.at((Type)hackmonType).size() << ")" << endl;
            getValidValueRange(hackmonNumber, 1, (int)hackerdex.at((Type)hackmonType).size());
            hackmonNumber--;
          } else {

            newHackmonFamily.emplace_back(Family((Type)hackmonType)); // FIXME: remove casting
            cout << "What would you like the name of your species to be?" << endl;
            cin >> newHackmonSpecies;
          }

          cout << endl << "Awesome! Would you like to name your HACKMON? (y/n)" << endl;
          wantNameHackmon = getValidValueOneOf<char>('y', 'n');

          if (wantNameHackmon == 'y') {
            cout << "What would you like the name of your HACKMON to be?" << endl;
            cin >> hackmonName;
          }

          int numberOfMovesToSelect = (hackmonSelect == 'h') ? 3 : 4;
          cout << endl << "Here is a list of the " << moveList.size() << " HACKMON moves:" << endl;
          printMoveList();
          cout << "Which moves would you like your HACKMON to have? Please type " << numberOfMovesToSelect;
          cout  << " numbers separated by spaces (1 <= # <= " << moveList.size() << ")" << endl;
          for (int k=0; k<3; k++) {
            getValidValueRange(hackmonMove, 1, (int)moveList.size()); // FIXME: remove casting
            hackmonMoves.emplace_back(moveList.at(hackmonMove-1)->clone());
          }

          if (numberOfMovesToSelect == 4) {
            getValidValueRange(newHackmonSpecialMove, 1, (int)moveList.size()); // FIXME: remove casting
            --newHackmonSpecialMove; // reindex to 0
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
            speciesToUse = &hackerdex.at((Type)hackmonType).back(); // FIXME: get from species list
          } else {
            speciesToUse = &hackerdex.at((Type)hackmonType).at(hackmonNumber);
          }

          unique_ptr<Hackmon> newHackmon = speciesToUse->createHackmon(move(hackmonMoves), hackmonName);

          if (p==0) party1.emplace_back(move(newHackmon)); else party2.emplace_back(move(newHackmon));
          cout << endl << "Great! " << (p==0 ? party1.back()->name : party2.back()->name) << " has been added to your party!" << endl << endl;
        }

        cout << "Now, lets select some items to put in your bag! Here is a list of the available items:" << endl;
        printItemList();
        cout << "Which items would you like to select? Please type " << numberOfItems;
        cout  << " numbers separated by spaces (1 <= # <= " << itemList.size() << ")" << endl;
        for (int k=0; k<numberOfItems; k++) {
          getValidValueRange(itemNumber, 1, (int)itemList.size()); // FIXME: remove cast
          if (p==0) items1.emplace_back(itemList.at(itemNumber-1)->clone()); else items2.emplace_back(itemList.at(itemNumber-1)->clone());
        }
      }

      Player p1(name1, move(party1), move(items1));
      Player p2(name2, move(party2), move(items2));

      while (battleLoop) {
        // battle ------------------------------------------------------------------
        cout << endl << "It looks like you two trainers are ready to battle!" << endl; // FIXME: add timers to these statementd

        // players choose starting pokemon
        int inBattleIndex;
        vector<int> inBattleIndexes;

        for (int p=0; p<2; p++) {
          Player &curPlayer = (p==0 ? p1 : p2);

          cout << "Now " << curPlayer.name << ", lets choose your starting HACKMON!" << endl << endl;
          cout << "Lets see which HACKMON you both have chosen!" << endl;
          // show players all chosen hackmon
          p1.printParty();
          p2.printParty();

          cout << "Please select " << numberBattling << " HACKMON from your list above" << (numberBattling > 1 ? " (separated by spaces)." : ".") << endl;
          for (unsigned m=0; m<numberBattling; m++) {
            getValidValueRange(inBattleIndex, 1, numberParty);
            inBattleIndexes.emplace_back(--inBattleIndex);
          }
          cout << endl;

          // make sure first (numberBattling) indexes in array are the starting hackmon
          for (unsigned m=0; m<numberBattling; m++) {
            if ((unsigned)inBattleIndexes.at(m) != m) {
              curPlayer.swapHackmon(m, inBattleIndexes.at(m));
            }
          }

          cout << "\033c" << endl; // clears terminal
        }

        // loop (check if all pokemon of one player have fainted)
        int loopCounter = 0;
        cout << endl << "Time to battle!" << endl << endl;

        const int itemPriority = 99;
        const int switchPriority = 100; // We all know that numbers stop at 100

        // Need this to store the switch actions somewhere
        Switch theSwitch;

        while (p1.partyAlive() && p2.partyAlive()) {
          cout << "-------- ROUND " << ++loopCounter << " --------" << endl << endl;

          // The priority queue of actions
          ActionQueue actionQueue;
          // The list of actions to be used this round
          vector<unique_ptr<Item>> itemsThisRound;

          // choose move/use item/swap for each hackmon
          for (int p=0; p<2; ++p) {
            Player &currPlayer = (p == 0 ? p1 : p2);
            Player &otherPlayer = (p == 0 ? p2 : p1);

            for (unsigned h=0; h<numberBattling; ++h) {
              if (!currPlayer.isAlive(h)) {
                continue;
              }
              Hackmon &currHackmon = *currPlayer.party.at(h);
              cout << currPlayer.name << ", please select for " << currHackmon.name << endl << endl;
              cout << currHackmon.name << "'s stats:" << endl;
              currHackmon.stats.printStats();
              cout << "   MOBILITY: " << mobilityStringVerb.at(currHackmon.mobility->name());
              cout << "   DEBUFF: " << debuffString.at(currHackmon.debuff.name) << endl << endl;

              char action;
              if (currPlayer.items.size() > 0) {
                // Able to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << "Will you make a move against your opponent, use an item, "
                       << "or swap out your HACKMON with another in your party? (m/i/s)" << endl;
                  action = getValidValueOneOf<char>('m', 'i', 's');
                } else {
                  // Unable to switch
                  cout << "Will you make a move against your opponent or use an item? (m/i) " << endl;
                  action = getValidValueOneOf<char>('m', 'i');
                }
              } else {
                // Unable to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << "Will you make a move against your opponent "
                       << "or swap out your HACKMON with another in your party? (m/s)" << endl;
                  action = getValidValueOneOf<char>('m', 's');
                } else {
                  // Unable to switch
                  action = 'm';
                }
              }


              if (action == 'm') {
                  // Hackmon does a move
                  cout << endl << "Here is a list of the available moves:" << endl;
                  for (size_t moveIndex = 0; moveIndex < currHackmon.moves.size(); ++moveIndex) {
                    // Give one-indexed list of moves
                    cout << moveIndex+1 << ": ";
                    currHackmon.moves.at(moveIndex)->printMove();
                    cout << endl;
                  }

                  // pick one from list
                  size_t selectedMoveIndex;
                  getValidValueRange<size_t>(selectedMoveIndex, 1, currHackmon.moves.size());
                  --selectedMoveIndex; // Make zero-indexed

                  // Hard-coded move logic for 1v1 and 2v2 battles starts here ------------
                  Move &selectedMove = *currHackmon.moves.at(selectedMoveIndex);
                  vector<size_t> targets;

                  if (numberBattling == 1) {
                    targets.emplace_back(0);
                  } else {
                    if (selectedMove.scope == SINGLE) {
                      // select targets (if needed)
                      if (!otherPlayer.isAlive(0)) {
                        targets.emplace_back(1);
                      } else if (!otherPlayer.isAlive(1)) {
                        targets.emplace_back(0);
                      } else {
                        // Both possible targets are still alive
                        cout << "Which enemy should " << currHackmon.name << " target? (1/2)" << endl;
                        cout << "1. " << otherPlayer.party.at(0)->name << endl;
                        cout << "2. " << otherPlayer.party.at(1)->name << endl;
                        size_t targetIndex;
                        getValidValueRange<size_t>(targetIndex, 1, 2);
                        --targetIndex;
                        targets.emplace_back(targetIndex);
                      }

                    } else {
                      // attack all targets
                      if (otherPlayer.isAlive(0)) {
                        targets.emplace_back(0);
                      }
                      if (otherPlayer.isAlive(1)) {
                        targets.emplace_back(1);
                      }
                    }
                  }
                  // Hard-coded move logic for 1v1 and 2v2 battles ends here --------------

                  // add to playerMove vector
                  int speed = currHackmon.stats.getStat(SPEED);
                  if (currHackmon.debuff.stat == SPEED) {
                    speed -= currHackmon.debuff.strength;
                  }
                  actionQueue.push(speed, &selectedMove, &otherPlayer, targets);

              } else if (action == 'i') {
                // output list of items
                cout << endl << "Here is a list of the available items:" << endl;
                for (size_t index = 0; index < currPlayer.items.size(); ++index) {
                  cout << index + 1 << ". ";
                  currPlayer.items.at(index)->printItem();
                  cout << endl;
                }
                cout << endl << "Please select a item (1 <= # <= " << currPlayer.items.size() << ")" << endl;
                size_t selectedItemIndex;
                getValidValueRange<size_t>(selectedItemIndex, 1, currPlayer.items.size());
                --selectedItemIndex; // zero-index

                // Hard-coded item logic for 1v1 and 2v2 battles starts here ------------
                Item &selectedItem = *currPlayer.items.at(selectedItemIndex);
                vector<size_t> targets;

                if (numberBattling == 1) {
                  targets.emplace_back(0);
                } else {
                  if (selectedItem.scope == SINGLE) {
                    // select targets (if needed)
                    if (!currPlayer.isAlive(0)) {
                      targets.emplace_back(1);
                    } else if (!currPlayer.isAlive(1)) {
                      targets.emplace_back(0);
                    } else {
                      // Both possible targets are still alive
                      cout << "Which HACKMON should receive the item?" << endl;
                      cout << "1. " << currPlayer.party.at(0)->name << endl;
                      cout << "2. " << currPlayer.party.at(1)->name << endl;
                      size_t targetIndex;
                      getValidValueRange<size_t>(targetIndex, 1, 2);
                      --targetIndex;
                      targets.emplace_back(targetIndex);
                    }
                  } else {
                    // give item to all hackmon
                    if (currPlayer.isAlive(0)) {
                      targets.emplace_back(0);
                    }
                    if (currPlayer.isAlive(1)) {
                      targets.emplace_back(1);
                    }
                  }
                }
                // Hard-coded item logic for 1v1 and 2v2 battles ends here --------------

                // Move item from player's item list to itemsThisRound vector
                itemsThisRound.emplace_back(unique_ptr<Item> {nullptr});
                swap(itemsThisRound.back(), currPlayer.items.at(selectedItemIndex));
                currPlayer.items.erase(currPlayer.items.begin() + selectedItemIndex);
                actionQueue.push(itemPriority, itemsThisRound.back().get(), &currPlayer, targets);

              } else {
                // Switch Hackmon
                cout << "Which Hackmon will you swap " << currHackmon.name << " for?" << endl;
                for (size_t index = 0; index < numberParty - currPlayer.nextAlive; ++index) {
                  cout << index + 1 << ". " << currPlayer.party.at(index + currPlayer.nextAlive)->name << endl;
                }
                size_t selectedHackmonIndex;
                getValidValueRange<size_t>(selectedHackmonIndex, 1, numberParty - currPlayer.nextAlive);
                selectedHackmonIndex += currPlayer.nextAlive - 1; // Set to actual index into party vector
                actionQueue.push(switchPriority, &theSwitch, &currPlayer, vector<size_t>{h, selectedHackmonIndex});
              }
            }

            cout << "\033c" << endl; // clears terminal
          }

          // Execute all actions selected by the players
          while (!actionQueue.isEmpty()) {
            actionQueue.doNextAction();
          }

          // output active hackmon stats
          cout << endl << endl;
          cout << "----- ROUND " << loopCounter << " STATS -----" << endl;
          for (int p=0; p<2; ++p) {
            Player &currPlayer = (p == 0 ? p1 : p2);
            cout << currPlayer.name << ":" << endl;
            for (unsigned h=0; h<numberBattling; ++h) {
              cout << currPlayer.party.at(h)->name << ": ";
              currPlayer.party.at(h)->stats.printStats();
              cout << "   MOBILITY: " << mobilityStringVerb.at(currPlayer.party.at(h)->mobility->name());
              cout << "   DEBUFF: " << debuffString.at(currPlayer.party.at(h)->debuff.name) << endl;
            }
            cout << endl;
          }
          cout << endl << endl;
        }

        // output winner (if winner)
        string winner;
        if (!p1.partyAlive()) {
          winner = p2.name;
          p2.hasWon();
        } else {
          winner = p1.name;
          p1.hasWon();
        }

        // reset hackmon
        for (int p=0; p<2; ++p) {
          Player &currPlayer = (p == 0 ? p1 : p2);
          for (auto& hackmon : currPlayer.party) {
            hackmon->restore();
          }
        }

        // postgame ----------------------------------------------------------------
        char playAgain;
        char keepHackmon;

        cout << "ROB HACKMAN here! Congrats to " << winner << " for the win!" << endl; // FIXME: add timers to these statement
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
