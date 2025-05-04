#include "GameManager.h"
#include "Character.h"
#include "Arena.h"
#include <iostream>

using namespace std;
ostream &operator<<(ostream &out, const Character &c)
{
    out << "Name: " << c.getName() << "" << endl;
    out << "Level: " << c.getLevel() << "" << endl;
    out << "Health: " << c.getHealth() << "" << endl;
    out << "Defense: " << c.getDefense() << "" << endl;
    out << "Attack: " << c.getAttack() << "" << endl;
    return out;
}

GameManager::GameManager() : player1(nullptr), player2(nullptr), arena(nullptr) {}
GameManager::GameManager(Character *p1, Character *p2, Arena *a) : player1(p1), player2(p2), arena(a) {}
GameManager::~GameManager()
{
    delete player1;
    delete player2;
    delete arena;
}

void GameManager::createCharacter()
{
    string player1Name, player2Name;
    int choice;

    // Ask for player 1's name
    cout << "Enter name for Player 1: ";
    cin >> player1Name;

    cout << "Choose character for " << player1Name << ":" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;
    cout << "Player 1: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
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
        cout << "Invalid choice. Defaulting to Warrior." << endl;
        player1 = new Warrior();
        break;
    }

    // Ask for player 2's name
    cout << "Enter name for Player 2: ";
    cin >> player2Name;

    cout << "Choose character for " << player2Name << ":" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;
    cout << "Player 2: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
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
        cout << "Invalid choice. Defaulting to Warrior." << endl;
        player2 = new Warrior();
        break;
    }

    // Set the names of the players
    player1->setName(player1Name);
    player2->setName(player2Name);
}


void GameManager::createArena()
{
    int choice;
    cout << "Choose your arena:" << endl;
    cout << "1. FIRE" << endl;
    cout << "2. ICE" << endl;
    cout << "3. JUNGLE" << endl;
    cout << "Arena: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
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
        cout << "Invalid choice. Defaulting to FIRE." << endl;
        arena = new Arena("FIRE", environmentType::FIRE, player1, player2);
        break;
    }
    system("pause");
    system("cls");
}

void GameManager::startGame()
{
    cout << "Welcome to the Battle Arena!" << endl;
    cout << "Battle started between " << player1->getName() << " and " << player2->getName() << endl;

    cout << *player1 << endl << *player2;
    arena->applyEnvironmentEffects();

    int round = 1;
    int random = -1;
    srand(time(0));
    while (player1->isAlive() && player2->isAlive())
    {

        random = rand() % 3;
        arena->triggerRandomWeather(random);
        int choice;
        int combo1 = (rand() % 10 + 1) == 8;
        int combo2 = (rand() % 10 + 1) == 8;

        cout << endl << "Round: " << round << endl << endl;

        cout << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
        if (combo1)
        {
            cout << "3. Use a combo attack!" << endl;
        }
    option1:
        cout << "Choose option(Player 1): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << player1->getName() << " attacks " << player2->getName() << endl;
            player1->attackTarget(*player2);
            break;
        case 2:
            if (player1->canUseSpecial())
            {
                player1->useSpecialAbility(*player2);
                player1->resetCooldown();
            }
            else
            {
                cout << "Special Cooldown: " << player1->getSpecialCooldown() << " rounds" << endl;
                goto option1;
            }
            break;

        case 3:
            if (combo1)
            {
                cout << player1->getName() << " uses a combo attack!" << endl;
                Warrior combo = *player1 + *player2;
                cout << "Combo Attack: " << combo.getAttack() << endl;
                combo.attackTarget(*player2);
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
                goto option1;
            }

        default:
            cout << "Invalid choice!" << endl;
            goto option1;
        }

		if (!(player2->isAlive()))
		{
			cout << player2->getName() << " is dead!" << endl;
			break;
		}

        cout << endl << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
        if (combo2)
        {
            cout << "3. Use a combo attack!" << endl;
        }
    option2:
        cout << "Choose option(Player 2): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << player2->getName() << " attacks " << player1->getName() << endl;
            player2->attackTarget(*player1);
            break;
        case 2:
            if (player2->canUseSpecial())
            {
                player2->useSpecialAbility(*player1);
                player2->resetCooldown();
            }
            else
            {
                cout << "Special Cooldown: " << player2->getSpecialCooldown() << " rounds" << endl;
                goto option2;
            }
            break;

        case 3:
            if (combo2)
            {
                cout << player2->getName() << " uses a combo attack!" << endl;
                Warrior combo = *player1 + *player2;
                cout << "Combo Attack: " << combo.getAttack() << endl;
                combo.attackTarget(*player1);
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
                goto option2;
            }
        default:
            cout << "Invalid choice!" << endl;
            goto option2;
        }

        if (round % 2 == 0)
        {
            cout << "Comparing Players" << endl;
            if (*player1 == *player2)
            {
                cout << player1->getName() << " and " << player2->getName() << " have equal power." << endl;
            }
            else
            {
                cout << player1->getName() << " and " << player2->getName() << " have different power." << endl;
            }
        }

        player1->reduceCooldown();
        player2->reduceCooldown();


        round++;

        arena->resetWeatherEffects(random);

        system("pause");
        system("cls");

    }

    cout << endl
         << "Battle Over!" << endl;
    if (player1->isAlive())
        cout << player1->getName() << " wins!" << endl;
    else if (player2->isAlive())
        cout << player2->getName() << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;
}