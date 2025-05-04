#include "Character.h"
#include <iostream>
using namespace std;
Character::Character() : name("Character"), level(1), health(100), attack(10), defense(50), specialCooldown(0) {}
Character::Character(string n, int l, int h, int a, int d, int sc) : name(n), level(l), health(h), attack(a), defense(d), specialCooldown(sc) {}

void Character::setName(string n) { name = n; }
string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
int Character::getHealth() const { return health; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }

bool Character::canUseSpecial() const { return specialCooldown == 0; }
void Character::resetCooldown() { specialCooldown = 4; }
void Character::reduceCooldown() {
    if (specialCooldown > 0)
        specialCooldown--;
}
int Character::getSpecialCooldown() const { return specialCooldown; }

Warrior::Warrior() : Character("Warrior", 1, 100, 35, 50, 0) {}
Warrior::Warrior(string n, int l, int h, int a, int d, bool s) : Character(n, l, h, a, d, s) {}
Mage::Mage() : Character("Mage", 1, 80, 25, 50, 0) {}
Archer::Archer() : Character("Archer", 1, 75, 20, 10, 0) {}

bool Character::isAlive() const
{
    return health > 0;
}
void Character::heal(int a)
{
    health += a;
    if (health > 100)
    {
        defense += health - 100;
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
    if (defense < 0)
        defense = 0;
}
void Character::takeDamage(int damage)
{
    if (defense > 0)
    {
        defense -= damage;
        if (defense < 0)
        {
            defense = 0;
            health += defense;
            if (health < 0)
                health = 0;
        }
    }
    else
    {
        health -= damage;
        if (health < 0)
        {
            health = 0;
            cout << name << " is defeated!" << endl;
        }
    }
    cout << name << " takes " << damage << " damage. Health: " << health << ", Defense: " << defense << endl;
}

void Warrior::attackTarget(Character &c)
{
    int damage = attack;
    if (damage < 0)
        damage = 0;
    c.takeDamage(damage);
}
void Warrior::useSpecialAbility(Character &target)
{
    cout << name << " uses Rizz Attack!" << endl;
        attack += 15;
        cout << "Rizz Attack activated! Attack increased by 15." << endl;
    attackTarget(target);
}

void Mage::attackTarget(Character &c)
{
    int damage = attack;
    if (damage < 0)
        damage = 0;
    c.takeDamage(damage);
}
void Mage::useSpecialAbility(Character &target)
{
        cout << name << " whispers: 'Skill issue' and steal some health " << endl;
        target.takeDamage(20);
        heal(20);
    attackTarget(target);
}

void Archer::attackTarget(Character &target)
{
    int damage = attack;
    if (damage < 0)
        damage = 0;
    target.takeDamage(damage);
    cout << name << " attacks " << target.getName() << " for " << damage << " damage." << endl;
}
void Archer::useSpecialAbility(Character &target)
{
    cout << name << " uses Tailwind!" << endl;
    cout << "Tailwind activated! Next attack will dodge." << endl;

    attackTarget(target);
}

Warrior operator+(const Character &c1, const Character &c2)
{
    Warrior combo("Combo", 1, 100, c1.getAttack() + c2.getAttack(), 0, false);
    return combo;
}

bool operator==(const Character &c1, const Character &c2)
{
    int power1 = c1.getHealth() + c1.getDefense();
    int power2 = c2.getHealth() + c2.getDefense();
    return power1 == power2;
}

Character &operator-(Character &attacker, Character &target)
{
    int stolen = 10;
    target.takeDamage(stolen);
    attacker.heal(stolen);
    cout << attacker.getName() << " steals " << stolen << " health from " << target.getName() << "!" << endl;
    return attacker;
}
