/*
  Class:      Ninja
  Purpose:    Represents a ninja participant in the simulation.

  Member Functions:
  - Ninja(int row, int col): Constructor to initialize Ninja object with initial row and column.
  - void incurDamage(Participant* p) override: Carries out the effects of a collision with another participant.
  - int causeDamage() const override: Returns the amount of damage the ninja causes in a collision.
  - bool isSafe() const override: Returns true if the ninja has left the Snorc Pit.

  Private Members:
  - int strength: Strength of the ninja.
  - bool poisoned: Flag indicating if the ninja has been poisoned and transformed into a giant snorc.
*/
#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"

class Ninja : public Participant {
public:
    Ninja() = default; // Default constructor
    Ninja(int row, int col);
    virtual void incurDamage(Participant* p) override;
    virtual int causeDamage() const override;
    virtual bool isSafe() const override;
private:
    int strength;
    bool poisoned;
};

#endif
