#ifndef ARENA_H
#define ARENA_H
#include"Character.h"
#include <iostream>
using namespace std;

class Character;

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
    ~Arena();
    
    void applyEnvironmentEffects();
    void triggerRandomWeather(int r);   
    void resetWeatherEffects(int r);            

    string getEnvironmentName() const;
};

#endif