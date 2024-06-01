/*
  Class:      Hero
  Purpose:    Represents one of the two heroes (Timmy or Harold) in the simulation.

  Member Functions:
  - Hero(char avatar, int row, int col, const string& name): Constructor to initialize Hero object with avatar, position, and name.
  - void incurDamage(Participant* p) override: Carries out the effects of a collision with another participant.
  - int causeDamage() const override: Returns the amount of damage the hero causes in a collision.
  - string getName() const: Getter for hero's name.
  - int getHealth() const: Getter for hero's health indicator.

  Private Members:
  - string name: Hero's name.
  - int health: Hero's health indicator.
  - bool rescued: if has switched to rescued movement.
*/

#ifndef HERO_H
#define HERO_H

#include "Participant.h"

class Hero : public Participant {
public:
    Hero() = default; // Default constructor
    Hero(char avatar, int row, int col, const string& name);
    void incurDamage(Participant* p) override;
    int causeDamage() const override;
    string getName() const;
    int getHealth() const;
    bool isSafe() const override;
private:
    string name;
    int health;
    bool rescued;
};

#endif

