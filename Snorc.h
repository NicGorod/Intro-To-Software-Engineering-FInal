/*
  Class:      Snorc
  Purpose:    Represents a regular snorc participant in the simulation.

  Member Functions:
  - Snorc(int row, int col, int strength): Constructor to initialize Snorc object with initial row, column, and strength.
  - void incurDamage(Participant* p) override: Does nothing as snorcs do not suffer damage in collisions.
  - int causeDamage() const override: Returns the amount of damage the snorc causes in a collision.
  - bool isSafe() const override: Always returns false as snorcs never leave the Pit.

  Private Members:
  - int strength: Strength of the snorc.
*/
#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

class Snorc : public Participant {
public:
    Snorc() = default; // Default constructor
    Snorc(int row, int col, int strength);
    void incurDamage(Participant* p) override;
    int causeDamage() const override;
    bool isSafe() const override;
private:
    int strength;
};

#endif

