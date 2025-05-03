#include "Character.h"
#include <iostream>
using namespace std;
Character::Character() : name("Character"), level(1), health(100), attack(10), defense(50) {}
Character::Character(string n, int l, int h, int a, int d) : name(n), level(l), health(h), attack(a), defense(d) {}

string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
int Character::getHealth() const { return health; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }

Warrior::Warrior() : Character("Warrior", 1, 100, 10, 50) {}
Mage::Mage() : Character("Mage", 1, 80, 15, 20) {}
Archer::Archer() : Character("Archer", 1, 75, 20, 10) {}



bool Character::isAlive() const
{
    return health > 0;
}
void Character::heal(int a)
{
    health += a;
    if (health > 100){
        defense+= health - 100;
        health = 100;
    }
    if (health < 0)
        health = 0;
}
void Character::boostAttack(int a)
{
    attack += a;
    if (attack < 0)
        attack = 0;
    if (attack > 100)
        attack = 100;
}
void Character::boostDefense(int a)
{
    defense += a;
    if(defense < 0)
        defense = 0;
}
void Character::takeDamage(int damage)
{
    if(defense > 0){
        defense -= damage;
        if(defense < 0){
            defense = 0;
            health += defense; 
            if(health < 0)
                health = 0;
        }
    } else {
        health -= damage;
        if(health < 0)
            health = 0;
            cout<< name << " is defeated!" << endl;
    }
    cout<< name << " takes " << damage << " damage. Health: " << health << ", Defense: " << defense << endl;



void Warrior::attackTarget(Character& c)
{
    int damage = attack - c.getDefense();
    if (damage < 0) damage = 0;
    c.takeDamage(damage);
    cout << name << " attacks " << c.getName() << endl;
}
void Warrior::useSpecialAbility()
{
    cout << name << " uses Run It Back!" << endl;
    if (!runItBack) {
        attack += 15;
        runItBack = true;
        cout << "Run it back activated! Attack increased by 15." << endl;
        cout << "If " << name << " is defeated this turn, they will revive with 50% health." << endl;
    } else {
        cout << "Special ability already active!\n";
    }
}





void Mage::attackTarget(Character& c)
{
    int damage = attack - c.getDefense();
    if (damage < 0) damage = 0;
    c.takeDamage(damage);
    cout << name << " attacks " << c.getName() << endl;
}
void Mage::useSpecialAbility()
{
    cout << name << " uses Healing Orb!" << endl;
    if(!healingOrb){
        heal(20);
        healingOrb = true;
    } else {
        cout << "Special ability already active!" << endl;
    }
}






void Archer::attackTarget(Character& target) {
    if (tailWind) {
        cout << name << " dodges the attack using 'Tailwind'!\n";
        tailWind = false; 
        return; 
    }

    int damage = attack - target.getDefense();
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    cout << name << " attacks " << target.getName() << " for " << damage << " damage.\n";
}
void Archer::useSpecialAbility()
{
    cout << name << " uses Tailwind!" << endl;
    if(!tailWind){
        tailWind = true;
        cout << "Tailwind activated! Next attack will dodge." << endl;
    } else {
        cout << "Special ability already active!" << endl;
    }
}

