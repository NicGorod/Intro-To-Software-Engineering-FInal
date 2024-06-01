#include "Snorc.h"

Snorc::Snorc(int row, int col, int strength) : Participant('s', row, col, new VillainBehaviour()), strength(strength) {}

void Snorc::incurDamage(Participant* p) {
    return; // Snorcs do not suffer any damage
}

int Snorc::causeDamage() const {
    return strength; // Return the snorc's strength
}

bool Snorc::isSafe() const {
    return false; // Snorcs are never safe
}
