#include "Character.h"
#include <iostream>
using namespace std;
Character::Character() : name(""), level(1), health(100), attack(10), defense(50) {}
Character::Character(string n, int l, int h, int a, int d) : name(n), level(l), health(h), attack(a), defense(d) {}

string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
int Character::getHealth() const { return health; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }

Warrior::Warrior() : Character("Warrior", 1, 100, 10, 50) {}
Mage::Mage() : Character("Mage", 1, 80, 15, 20) {}
Archer::Archer() : Character("Archer", 1, 75, 20, 10) {}


void Character::takeDamage(int dmg)
{
    health -= dmg;
    if (health < 0)
        health = 0;
}
bool Character::isAlive() const
{
    return health > 0;
}
void Character::heal(int a)
{
    health += a;
    if (health > 100) // Assuming max health is 100
        health = 100;
}

void Warrior::attackTarget(Character& c)
{
    int damage = attack - c.getDefense();
    if (damage < 0) damage = 0;
    c.takeDamage(damage);
    cout << name << " attacks " << c.getName() << " for " << damage << " damage!" << endl;
}
void Warrior::useSpecialAbility()
{
    cout << name << " uses Run It Back!" << endl;
    // Implement special ability logic here
}
void Mage::attackTarget(Character& c)
{
    int damage = attack - c.getDefense();
    if (damage < 0) damage = 0;
    c.takeDamage(damage);
    cout << name << " attacks " << c.getName() << " for " << damage << " damage!" << endl;
}
void Mage::useSpecialAbility()
{
    cout << name << " uses Orb of Destruction!" << endl;
    // Implement special ability logic here
}
void Archer::attackTarget(Character& c)
{
    int damage = attack - c.getDefense();
    if (damage < 0) damage = 0;
    c.takeDamage(damage);
    cout << name << " attacks " << c.getName() << " for " << damage << " damage!" << endl;
}
void Archer::useSpecialAbility()
{
    cout << name << " uses Tailwind!" << endl;
    // Implement special ability logic here
}
