#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
#include"Arena.h"
using namespace std;
class Character {
protected:
	string name;
	int level;
	int health;
	int attack;
	int defense;
	bool special;
public:
	Character();
	Character(string n, int l, int h, int a, int d, bool s);
	virtual ~Character() {}
	virtual void attackTarget(Character& c) = 0;
	virtual void useSpecialAbility(Character& target) = 0;
	virtual void specialAbilityActive() = 0;

	string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;

	bool isAlive() const;
	void heal(int a);
	void takeDamage(int damage);
	void boostAttack(int a);
	void boostDefense(int a);


};
class Warrior : public Character {
public:
	Warrior();
	void attackTarget(Character& c);
	// Run It Back: Attack +15, if defeated, revive with 50% health
	void useSpecialAbility(Character& target);
	void specialAbilityActive();
};
class Mage : public Character {
public:
	Mage();
	void attackTarget(Character& c);
	// Healing Orb: Heal +20
	void useSpecialAbility(Character& target);
	void specialAbilityActive();
};
class Archer : public Character {
public:
	Archer();
	void attackTarget(Character& c);
	// Tailwind: Dodges the next attack
	void useSpecialAbility(Character& target);
	void specialAbilityActive();
};

#endif