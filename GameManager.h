#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <iostream>
#include <string>
#include"Character.h"
#include"Arena.h"

class GameManager{
private:
    Character* player1;
    Character* player2;
    Arena* arena;

public:
    GameManager();
    ~GameManager();

    void createCharacter();
    void createArena();
    void startGame();
    
};



#endif