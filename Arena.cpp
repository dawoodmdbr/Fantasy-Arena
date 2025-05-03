#include "Arena.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arena::Arena() : name(""), environment(environmentType::FIRE), c1(nullptr), c2(nullptr) {}
Arena::Arena(string n, environmentType e, Character *c1, Character *c2) : name(n), environment(e), c1(c1), c2(c2) {}

string Arena::getEnvironmentName() const
{
    switch (environment)
    {
    case environmentType::FIRE:
        return "Fire";
    case environmentType::ICE:
        return "Ice";
    case environmentType::JUNGLE:
        return "Jungle";
    default:
        return "Unknown";
    }
}

void Arena::applyEnvironmentEffects()
{
    cout << "Applying environment effects for arena: " << name << endl;
    switch (environment)
    {
    case environmentType::FIRE:
        c1->takeDamage(10);
        c2->takeDamage(10);
        cout << "Both characters take 10 damage from fire!" << endl;
        break;
    case environmentType::ICE:
        c1->boostDefense(5);
        c2->boostDefense(5);
        cout << "Both characters gain 5 defense from ice!" << endl;
        break;
    case environmentType::JUNGLE:
        c1->heal(10);
        c2->heal(10);
        cout << "Both characters heal 10 health from jungle!" << endl;
        break;
    default:
        cout << "No environment effects applied." << endl;
        break;
    }
}

void Arena::triggerRandomWeather(int r)
{
    switch (r)
    {
    case 0:
        cout << "Storm hits! Attack decreased by 5." << endl;
        c1->boostAttack(-5);
        c2->boostAttack(-5);
        break;
    case 1:
        cout << "Heatwave Alert! Defense decreased by 5." << endl;
        c1->boostDefense(-5);
        c2->boostDefense(-5);
        break;
    case 2:
        cout << "Rain Ahead! health increased by 10." << endl;
        c1->heal(10);
        c2->heal(10);
        break;
    default:
        cout << "No weather effects triggered." << endl;
        break;
    }
}
void Arena::resetWeatherEffects(int r)
{
    cout << "Resetting weather effects..." << endl;
    switch (r)
    {
    case 0:
        c1->boostAttack(5);
        c2->boostAttack(5);
        break;
    case 1:
        c1->boostDefense(5);
        c2->boostDefense(5);
        break;
    }
}

void Arena::startBattle()
{
    cout << "Battle started between " << c1->getName() << " and " << c2->getName() << "in arena: " << name << endl;
    applyEnvironmentEffects();

    int round = 1;
    while (c1->isAlive() && c2->isAlive())
    {
        int random = -1;
        resetWeatherEffects(random);
        int choice;

        cout << "Round: " << round << endl;

        cout << c1->getName() << " Health: " << c1->getHealth() << ", Attack: " << c1->getAttack() << ", Defense: " << c1->getDefense() << endl;

        cout << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
    option1:
        cout << "Choose option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << c1->getName() << " attacks " << c2->getName() << endl;
            c1->attackTarget(*c2);
            break;
        case 2:
            c1->useSpecialAbility(*c1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            goto option1;
        }

        cout << c2->getName() << " Health: " << c2->getHealth() << ", Attack: " << c2->getAttack() << ", Defense: " << c2->getDefense() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Special Ability" << endl;
    option2:
        cout << "Choose option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << c2->getName() << " attacks " << c1->getName() << endl;
            c2->attackTarget(*c1);
            break;
        case 2:
            c2->useSpecialAbility(*c1);
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
        triggerRandomWeather(random);

        c1->specialAbilityActive();
        c2->specialAbilityActive();
    }
    cout << endl << "Battle Over!" << endl;
    if (c1->isAlive())
        cout << c1->getName() << " wins!" << endl;
    else if (c2->isAlive())
        cout << c2->getName() << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;
}