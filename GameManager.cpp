#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() : player1(nullptr), player2(nullptr), arena(nullptr) {}
GameManager::GameManager(Character* p1, Character* p2, Arena* a) : player1(p1), player2(p2), arena(a) {}
GameManager::~GameManager() {
    delete player1;
    delete player2;
    delete arena;
}

void GameManager::createCharacter(){
    int choice;

    cout<<"Choose your character:" << endl;
    cout<<"1. Warrior" << endl;
    cout<<"2. Mage" << endl;
    cout<<"3. Archer" << endl;
    option1:
    cout<<"Player 1: ";
    cin>>choice;
    cin.ignore(); 
    
    switch(choice){
        case 1:
            player1 = new Warrior();
            break;
        case 2:
            player1 = new Mage();
            break;
        case 3:
            player1 = new Archer();
            break;
        default:
            cout<<"Invalid choice. Defaulting to Warrior." << endl;
            player1 = new Warrior();
            break;
    }
    option2:
    cout<<"Player 2: ";
    cin>>choice;
    cin.ignore(); 
    
    switch(choice){
        case 1:
            player2 = new Warrior();
            break;
        case 2:
            player2 = new Mage();
            break;
        case 3:
            player2 = new Archer();
            break;
        default:
            cout<<"Invalid choice. Defaulting to Warrior." << endl;
            player2 = new Warrior();
            break;
    }
}

void GameManager::createArena(){
    int choice;
    cout<<"Choose your arena:" << endl;
    cout<<"1. FIRE" << endl;
    cout<<"2. ICE" << endl;
    cout<<"3. JUNGLE" << endl;
    cin>>choice;
    cin.ignore(); 

    switch(choice){
        case 1:
            arena = new Arena("FIRE", environmentType::FIRE, player1, player2);
            break;
        case 2:
            arena = new Arena("ICE", environmentType::ICE, player1, player2);
            break;
        case 3:
            arena = new Arena("JUNGLE", environmentType::JUNGLE, player1, player2);
            break;
        default:
            cout<<"Invalid choice. Defaulting to FIRE." << endl;
            arena = new Arena("FIRE", environmentType::FIRE, player1, player2);
            break;
    }
}


void GameManager::startGame()
{
    cout << "Battle started between " << player1->getName() << " and " << player2->getName() << endl;
    arena->applyEnvironmentEffects();

    int round = 1;
    while (player1->isAlive() && player2->isAlive())
    {
        int random = -1;
        arena->resetWeatherEffects(random);
        int choice;

        cout << "Round: " << round << endl;

        cout << player1->getName() << " Health: " << player1->getHealth() << ", Attack: " << player1->getAttack() << ", Defense: " << player1->getDefense() << endl;

        cout << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
    option1:
        cout << "Choose option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << player1->getName() << " attacks " << player2->getName() << endl;
            player1->attackTarget(*player2);
            break;
        case 2:
            player1->useSpecialAbility(*player1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            goto option1;
        }

        cout << player2->getName() << " Health: " << player2->getHealth() << ", Attack: " << player2->getAttack() << ", Defense: " << player2->getDefense() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
    option2:
        cout << "Choose option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << player2->getName() << " attacks " << player1->getName() << endl;
            player2->attackTarget(*player1);
            break;
        case 2:
            player2->useSpecialAbility(*player1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            goto option2;
        }

        round++;


        system("pause");
        system("cls");

        srand(time(0));
        random = rand() % 3;
        arena->triggerRandomWeather(random);

        player1->specialAbilityActive();
        player2->specialAbilityActive();
    }

    cout << endl << "Battle Over!" << endl;
    if (player1->isAlive())
        cout << player1->getName() << " wins!" << endl;
    else if (player2->isAlive())
        cout << player2->getName() << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;
}