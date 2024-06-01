#include "Hero.h"

Hero::Hero(char avatar, int row, int col, const string& name) 
    : Participant(avatar, row, col, new EscapeeBehaviour()), name(name), health(MAX_HEALTH), rescued(false) {}

void Hero::incurDamage(Participant* p) {
    int damage = p->causeDamage();
    if (damage == RESCUE) {
        rescued = true;
        delete moveBehaviour;
        moveBehaviour = new RescuedBehaviour(); // Initialize move behavior
    } else {
        health -= damage;
        if (health <= 0) {
            health = 0;
            dead = true;
            avatar = '+'; // Change avatar to indicate death
        }
    }
}

int Hero::causeDamage() const {
    return 0;
}

string Hero::getName() const {
    return name;
}

int Hero::getHealth() const{
    return health;
}

bool Hero::isSafe() const {
    return getRow() == 0;
}
