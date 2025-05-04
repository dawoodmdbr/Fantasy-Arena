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
	int specialCooldown;
public:
	Character();
	Character(string n, int l, int h, int a, int d, int sc);
	virtual ~Character() {}
	virtual void attackTarget(Character& c) = 0;
	virtual void useSpecialAbility(Character& target) = 0;

	void setName(string n);
	string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;

	bool canUseSpecial() const;
	void resetCooldown();
	void reduceCooldown();
	int getSpecialCooldown() const;

	bool isAlive() const;
	void heal(int a);
	void takeDamage(int damage);
	void boostAttack(int a);
	void boostDefense(int a);

	friend Character& operator-(Character& attacker, Character& target);
	friend ostream& operator<<(ostream& out, const Character& c);
	friend bool operator==(const Character& c1, const Character& c2);
};
class Warrior : public Character {
public:
	Warrior();
	Warrior(string n, int l, int h, int a, int d, bool s);
	void attackTarget(Character& c) override;
	// Rizz Attack: Attack +15
	void useSpecialAbility(Character& target) override;
};
class Mage : public Character {
public:
	Mage();
	void attackTarget(Character& c) override;
	// Skill Issue: steals 20 health
	void useSpecialAbility(Character& target) override;
};
class Archer : public Character {
public:
	Archer();
	void attackTarget(Character& c)override;
	// Tailwind: Dodges the next attack
	void useSpecialAbility(Character& target)override;
};

Warrior operator+(const Character& c1, const Character& c2);
bool operator==(const Character& c1, const Character& c2);
ostream& operator<<(ostream& out, const Character& c);
Character& operator-(Character& attacker, Character& target);
#endif