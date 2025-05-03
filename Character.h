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
	Character();
	Character(string n, int l, int h, int a, int d);
	virtual ~Character() {}
	virtual void attackTarget(Character& c) = 0;
	virtual void useSpecialAbility() = 0;
};
class Warrior : public Character {
public:
	Warrior() : Character("Warrior", 1, 100, 10, 50) {}
	void attackTarget(Character& c);
	void useSpecialAbility();
};
class Mage : public Character {
public:
	Mage() : Character("Mage", 1, 85, 15, 25) {}
	void attackTarget(Character& c);
	void useSpecialAbility();
};
class Archer : public Character {
public:
	Archer() : Character("Archer", 1, 75, 20, 10) {}
	void attackTarget(Character& c);
	void useSpecialAbility() override;
};

#endif // !CHARACTER_H
