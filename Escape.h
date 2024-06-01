/*
  Class:      Escape
  Purpose:    Serves as the control object for the simulation, managing participants and their movements.

  Member Functions:
  - Escape(): Constructor to initialize Escape object and dynamically allocate heroes.
  - ~Escape(): Destructor to free dynamically allocated memory.
  - void runEscape(): Executes the escape loop and prints outcome for heroes.
  - static bool withinBounds(int row, int col): Checks if given row and column are within Snorc Pit bounds.
  - void spawnSnorc(): Spawns a new snorc participant in the simulation.
  - void spawnNinja(): Spawns a new ninja participant in the simulation.
  - void moveParticipants(): Moves all participants according to escape rules.
  - Participant* checkForCollision(Participant* p): Checks for collision with another participant.
  - bool isOver(): Checks if escape conditions have been met.
  - void printPit(): Prints the current state of the Snorc Pit.
  - void printOutcome(Hero* h): Prints the outcome for the given hero.

  Private Members:
  - int numSnorcs: Number of snorcs in the simulation.
  - List<Participant> participants: List of all participants in the simulation.
  - Hero* timmy: Pointer to the first hero (Timmy).
  - Hero* harold: Pointer to the second hero (Harold).
  - Hero* timmyPtr: Pointer to Timmy used for outcome printing.
  - Hero* haroldPtr: Pointer to Harold used for outcome printing.
*/
#ifndef ESCAPE_H
#define ESCAPE_H

#include "Participant.h"
#include "List.h"
#include "Hero.h"
#include "Ninja.h"
#include "Snorc.h"
#include <ctime>

class Escape {
public:
    Escape();
    ~Escape();
    void runEscape();
    static bool withinBounds(int row, int col);
private:
    int numSnorcs;
    List<Participant> participants; // Statically allocated List object for participants
    Hero* timmyPtr;
    Hero* haroldPtr;
    void spawnSnorc();
    void spawnNinja();
    void moveParticipants();
    Participant* checkForCollision(Participant* p);
    bool isOver();
    void printPit();
    void printOutcome(Hero* h);
};

#endif
