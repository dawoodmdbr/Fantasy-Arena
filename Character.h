#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
using namespace std;
class Character {
protected:
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

	string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;

	void takeDamage(int dmg);
	bool isAlive() const;
	void heal(int a);


};
class Warrior : public Character {
private:
	bool runItBack;
public:
	Warrior();
	void attackTarget(Character& c);
	void useSpecialAbility();
};
class Mage : public Character {
private:
	bool orbCooldown;
public:
	Mage();
	void attackTarget(Character& c);
	void useSpecialAbility();
};
class Archer : public Character {
private:
	bool tailWind;
public:
	Archer();
	void attackTarget(Character& c);
	void useSpecialAbility() override;
};

#endif // !CHARACTER_H
