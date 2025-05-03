#ifndef ARENA_H
#define ARENA_H
#include"Character.h"
#include <iostream>
using namespace std;

enum class environmentType {FIRE, ICE, JUNGLE};

class Arena{
private:
    string name;
    environmentType environment;
    Character* c1;
    Character* c2;
public:
    Arena();
    Arena(string n, environmentType e, Character* c1, Character* c2);
    
    void applyEnvironmentEffects();
    void triggerRandomWeather();   
    void startBattle();                

    string getEnvironmentName() const;
    void resetWeatherEffects();
};

#endif