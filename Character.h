#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
using namespace std;
class Character {
private:
	string name;
	int level;
	int health;
	int attack;
	int defense;
public:
	void getName() {

	}
	virtual void attackTarget(Character& c) = 0;
	virtual void useSpecialAbility() = 0;
};
class Warrior : public Character {
public:
	void useSpecialAbility();
};
class Mage : public Character {
public:
	void useSpecialAbility();
};
class Archer : public Character {
public:
	void useSpecialAbility();
};

#endif // !CHARACTER_H
