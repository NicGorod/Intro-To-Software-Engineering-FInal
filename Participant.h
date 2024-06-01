#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "defs.h"
#include "MoveBehaviour.h" // Include the move behaviour header file

class Participant {
public:
    Participant() = default; // Default constructor
    Participant(char avatar, int row, int col, MoveBehaviour* behaviour); // Add MoveBehaviour* parameter to constructor
    virtual ~Participant();
    void move();
    virtual void incurDamage(Participant* p) = 0;
    virtual int causeDamage() const = 0;
    virtual bool isSafe() const = 0;
    bool collide(Participant* p) const;
    char getAvatar() const;
    bool isDead() const;
    int getRow() const;
    int getCol() const;
    void setMoveBehaviour(MoveBehaviour* behaviour); // Add setter for move behaviour
protected:
    char avatar;
    bool dead;
    int row;
    int column;
    MoveBehaviour* moveBehaviour; // Add member for move behaviour
};

#endif
