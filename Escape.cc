#include "Escape.h"

Escape::Escape() {
    // Seed the PRNG
    srand((unsigned)time(NULL));

    numSnorcs = 0;

    int col1 = random(10) + 7; // Random number between 7 and 16 inclusive
    int col2;
    do {
        col2 = random(10) + 7; // Random number between 7 and 16 inclusive
    } while (col2 == col1); // Ensure the two heroes start at different columns

    // Create hero objects with random columns and add them to the participants collection
    timmyPtr = new Hero('T', MAX_ROW - 1, col1, "Timmy");
    haroldPtr = new Hero('H', MAX_ROW - 1, col2, "Harold");
    participants += timmyPtr;
    participants += haroldPtr;
}


Escape::~Escape() {}


void Escape::runEscape() {
    while (!isOver()) {
        spawnSnorc();
        spawnNinja();
        moveParticipants(); // Move participants according to the rules
        printPit(); // Print the Pit after each iteration
        usleep(300000); // Sleep for 300 milliseconds
    }
    printOutcome(timmyPtr); // Print the outcome for Timmy
    printOutcome(haroldPtr); // Print the outcome for Harold
}


bool Escape::isOver() {

    // Check if either have either escaped or died
    if ((timmyPtr->isSafe() || timmyPtr->isDead())&&(haroldPtr->isSafe() || haroldPtr->isDead())) {
        return true;
    }

    // If neither hero has escaped or died, the escape is not over
    return false;
}

bool Escape::withinBounds(int row, int col) {
        return row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL;
    }


void Escape::spawnSnorc() {
    if (numSnorcs >= MAX_SNORCS) {
        return; // Maximum snorcs reached, no more can be spawned
    }

    int spawnChance = random(100); // Generate a number between 0 and 99
    if (spawnChance < SNORC_SPAWN) { 
        int row = MAX_ROW-random(5)-1; 
        int col = random(MAX_COL);

        Snorc* newSnorc = new Snorc(row, col, random(3) + 2); // Random strength between 2 and 4

        participants += newSnorc;
        numSnorcs++;
    }
}


void Escape::spawnNinja() {
    int spawnChance = random(100); 
    if (spawnChance < NINJA_SPAWN) {
        int col = random(MAX_COL); 
        Ninja* newNinja = new Ninja(1, col); // Ninja positioned at top, not specified exactly where so just put 1
        participants += newNinja;
    }
}


void Escape::moveParticipants() {
    Participant* participantsArray[MAX_ARR];
    int size;
    participants.convertToArray(participantsArray, size);

    // Loop over the array of participants
    for (int i = 0; i < size; ++i) {
        Participant* currParticipant = participantsArray[i];

        // Move the participant to a new row and column
        currParticipant->move();
        // Check for collisions with other participants
        Participant* collidedParticipant = checkForCollision(currParticipant);
        if (collidedParticipant != nullptr && !collidedParticipant->isDead() && !collidedParticipant->isSafe()) {
            // If there is a collision and the other participant is neither dead nor safely out of the Snorc Pit,
            currParticipant->incurDamage(collidedParticipant);
            collidedParticipant->incurDamage(currParticipant);
        }
    }
}

Participant* Escape::checkForCollision(Participant* p) {
    Participant* participantsArray[MAX_ARR]; 
    int size;
    participants.convertToArray(participantsArray, size);

    for (int i = 0; i < size; ++i) {
        Participant* currParticipant = participantsArray[i];
        if (currParticipant != p && currParticipant->collide(p)) {
            // Collision found, return the participant
            return currParticipant;
        }
    }

    // No collision found, return nullptr
    return nullptr;
}

void Escape::printPit() {
    //declare a temporary 2D grid and initialize it with spaces
    char pit[MAX_ROW][MAX_COL];
    for (int i = 0; i < MAX_ROW; ++i) {
        for (int j = 0; j < MAX_COL; ++j) {
            pit[i][j] = ' ';
        }
    }
    Participant* participantsArray[MAX_ARR];
    int size;
    participants.convertToArray(participantsArray, size);

    //Loop through the participants array and place each participant’s avatar in the temporary grid
    for (int i = 0; i < size; ++i) {
        Participant* participant = participantsArray[i];
        int row = participant->getRow();
        int col = participant->getCol();


        pit[row][col] = participant->getAvatar();
    }

    cout << "---------------------------" << endl;
    for (int i = 0; i < MAX_ROW; ++i) {
        cout << "|";
        for (int j = 0; j < MAX_COL; ++j) {
            cout << pit[i][j];
        }
        cout << "|";
        if (i == MAX_ROW - 2)
            cout << setw(7) << timmyPtr->getName() << " :  " << timmyPtr->getHealth();
        if (i == MAX_ROW - 1)
            cout << setw(8) << haroldPtr->getName() << " : " << haroldPtr->getHealth();

        cout<<endl;
    }
    cout << "---------------------------" << endl;

}

void Escape::printOutcome(Hero* h) {
    cout << "Outcome for hero " << h->getName() << ": ";
    if (h->isSafe()) {
        cout << "Escaped" << endl;
    } else if (h->isDead()) {
        cout << "Deceased" << endl;
    }
}
