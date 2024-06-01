#include "Ninja.h"

Ninja::Ninja(int row, int col) : Participant('N', row, col, new RescuerBehaviour()), strength(0), poisoned(false) {}

void Ninja::incurDamage(Participant* p) {
    if (poisoned) {
        return; // Ninja is a giant snorc, does not suffer any damage
    }

    int damage = p->causeDamage();

    if (damage == RESCUE) {
        return; // Other participant is also a Ninja, do nothing
    } else if (damage == 0) {
    	delete moveBehaviour;
        moveBehaviour = new RescuedBehaviour();
    } else {
        poisoned = true;
        avatar = 'S'; // Ninja becomes a giant snorc
        strength = random(3) + 6; // Random strength between 6 and 8
        delete moveBehaviour;
        moveBehaviour = new VillainBehaviour();
    }
}

int Ninja::causeDamage() const {
    if (poisoned) {
        return strength; // Ninja is a giant snorc, return its strength
    } else {
        return RESCUE;
    }
}

bool Ninja::isSafe() const {
    if (poisoned) {
        return false; // Giant snorcs never leave the Pit
    } else{
        return row == 0; // Ninja is at the top
    }
}
