/*
  Class:      MoveBehaviour
  Purpose:    Represents the base class for different move behaviors of participants in the simulation.

  Member Functions:
  - virtual void move(int oldRow, int oldCol, int& newRow, int& newCol) = 0: Pure virtual function to compute new position.
  - virtual ~MoveBehaviour(): Destructor for MoveBehaviour class.

  Derived Classes:
  - EscapeeBehaviour: Represents the behavior of heroes before they are rescued.
  - VillainBehaviour: Represents the behavior of snorcs (regular and giant).
  - RescuerBehaviour: Represents the behavior of ninjas before they rescue a hero.
  - RescuedBehaviour: Represents the behavior of heroes and ninjas after they are or have rescued.

*/
#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

#include "defs.h" // Include the necessary definitions

class MoveBehaviour {
public:
    MoveBehaviour() = default; // Default constructor
    virtual ~MoveBehaviour();
    virtual void move(int oldRow, int oldCol, int& newRow, int& newCol) = 0;
};

class EscapeeBehaviour : public MoveBehaviour {
public:
    EscapeeBehaviour() = default; // Default constructor
    void move(int oldRow, int oldCol, int& newRow, int& newCol) override;
};

class VillainBehaviour : public MoveBehaviour {
public:
    VillainBehaviour() = default; // Default constructor
    void move(int oldRow, int oldCol, int& newRow, int& newCol) override;
};

class RescuerBehaviour : public MoveBehaviour {
public:
    RescuerBehaviour() = default; // Default constructor
    void move(int oldRow, int oldCol, int& newRow, int& newCol) override;
};

class RescuedBehaviour : public MoveBehaviour {
public:
    RescuedBehaviour() = default; // Default constructor
    void move(int oldRow, int oldCol, int& newRow, int& newCol) override;
};

#endif
