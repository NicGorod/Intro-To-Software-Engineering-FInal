#include "Participant.h"

Participant::Participant(char avatar, int row, int col, MoveBehaviour* behaviour) 
    : avatar(avatar), dead(false), row(row), column(col), moveBehaviour(behaviour) {}

Participant::~Participant() {
delete moveBehaviour;
}

bool Participant::collide(Participant* p) const {
    return row == p->row && column == p->column;
}

char Participant::getAvatar() const {
    return avatar;
}

bool Participant::isDead() const {
    return dead;
}

int Participant::getRow() const {
    return row;
}

int Participant::getCol() const {
    return column;
}

void Participant::setMoveBehaviour(MoveBehaviour* behaviour) {
    moveBehaviour = behaviour;
}

void Participant::move() {
    if (dead || isSafe()) {
        return;
    }
    int oldRow = getRow();
    int oldCol = getCol();
    int newRow, newCol; 
    moveBehaviour->move(oldRow, oldCol, newRow, newCol);
    row = newRow;
    column = newCol;
}
