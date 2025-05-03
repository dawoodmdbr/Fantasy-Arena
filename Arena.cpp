#include"Arena.h"
#include<iostream>
using namespace std;

Arena::Arena(): name(""), environment(0), c1(nullptr), c2(nullptr) {}
Arena::Arena(string n, environmentType e, Character* c1, Character* c2): name(n), environment(e), c1(c1), c2(c2) {}

string Arena::getEnvironmentName() const {
    switch(environment) {
        case environmentType::FIRE: return "Fire";
        case environmentType::ICE: return "Ice";
        case environmentType::JUNGLE: return "Jungle";
        default: return "Unknown";
    }
}
void Arena::resetWeatherEffects() {
    cout << "Resetting weather effects for arena: " << name << endl;
}


void Arena::applyEnvironmentEffects(){
    cout<<"Applying environment effects for arena: " << name << endl;
    switch(environment){
        case environmentType::FIRE:
            c1->takeDamage(10);
            c2->takeDamage(10);
            cout<<"Both characters take 10 damage from fire!"<<endl;
            break;
        case environmentType::ICE:
            c1->boostDefense(5);
            c2->boostDefense(5);
            cout<<"Both characters gain 5 defense from ice!"<<endl;
            break;
        case environmentType::JUNGLE:
            c1->heal(10);
            c2->heal(10);
            cout<<"Both characters heal 10 health from jungle!"<<endl;
            break;
        default:
            cout << "No environment effects applied." << endl;
            break;
    }
}
