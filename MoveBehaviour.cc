#include "MoveBehaviour.h"
#include "defs.h"


MoveBehaviour::~MoveBehaviour(){}


void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) {
    newRow = oldRow + random(5) - 2; // Random value between -2 and 2 inclusive


    // Ensure the new row is within the valid range
    if (newRow < 0 || newRow >= MAX_ROW) {
        newRow = oldRow; // Stay in the same row if out of bounds
    }

    newCol = oldCol + random(3) - 1; // Random value between -1 and 1 inclusive

    if (newCol < 0 || newCol >= MAX_COL) {
        newCol = oldCol; // Stay in the same column if out of bounds
    }
}


void VillainBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) {
    newRow = oldRow + random(3) - 1; // Random value between -1 and 1 inclusive

    if (newRow < MAX_ROW - 7 || newRow >= MAX_ROW) {
        newRow = oldRow; // Stay in the same row if out of bounds
    }

    newCol = oldCol + random(3) - 1; // Random value between -1 and 1 inclusive

    if (newCol < 0 || newCol >= MAX_COL) {
        newCol = oldCol; // Stay in the same column if out of bounds
    }
}


void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) {
    if(oldRow>=MAX_ROW-1){newRow = oldRow;}
    else{newRow = oldRow+1;}
    newCol = oldCol;
}

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) {
    if(oldRow<=0){newRow = oldRow;}
    else newRow = oldRow-1;
    newCol = oldCol;
}
