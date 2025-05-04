#include "GameManager.h"
#include <iostream>

using namespace std;

int main() {
    GameManager game;

    // Step 1: Create characters
    game.createCharacter();

    // Step 2: Choose arena
    game.createArena();

    // Step 3: Start the game
    game.startGame();

    return 0;
}
