#include "Arena.h"
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arena::Arena() : name(""), environment(environmentType::FIRE), c1(nullptr), c2(nullptr) {}
Arena::Arena(string n, environmentType e, Character *c1, Character *c2) : name(n), environment(e), c1(c1), c2(c2) {}
Arena::~Arena()
{
    delete c1;
    delete c2;
}


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