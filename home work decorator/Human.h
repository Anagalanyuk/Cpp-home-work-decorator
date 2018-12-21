#pragma once

#include"Rasa.h"

class Human : public Rasa // concret component
{
public:
	Human()
	{
	}

	virtual void Show() const override
	{
		std::cout << "Human" << std::endl;
		std::cout << "Attack: " << m_attack << std::endl;
		std::cout << "Speed: " << m_speed << std::endl;
		std::cout << "Health: " << m_health << std::endl;
		std::cout << "Protection: " << m_protection << std::endl;
	}

	int SetAttack(int attack)
	{
		return m_attack += attack;
	}

	int SetSpeed(int speed)
	{
		return m_speed += speed;
	}

	int SetHealth(int health)
	{
		return m_health += health;
	}

	int SetProtection(int protection)
	{
		return m_protection += protection;
	}

private:

	int m_attack = 20;
	int m_speed = 20;
	int m_health = 150;
	int m_protection = 0;
};

class Professional :public Human // decarator
{
protected:

	Professional()
	{
	};

	Professional(Human * human) :
		m_human(human)
	{
	}

	Human* GetHuman() const
	{
		return m_human;
	}
private:
	Human * m_human = nullptr;
};

class Warrior :public Professional
{
public:
	Warrior()
	{
	};

	Warrior(Human* human):Professional(human)
	{
		m_warrior = human;
		m_warrior->SetAttack(20);
		m_warrior->SetHealth(50);
		m_warrior->SetSpeed(10);
		m_warrior->SetProtection(20);
	}

	virtual void Show() const override
	{
		std::cout << "Warrior" << std::endl;
		GetHuman()->Show();
	}

private:
	Human * m_warrior;
};

class SwordBearer :public Warrior
{

public:
	SwordBearer()
	{
	};

	SwordBearer(Human* warior)
	{
		m_swordbear = warior;
		m_swordbear->SetAttack(40);
		m_swordbear->SetHealth(50);
		m_swordbear->SetProtection(40);
		m_swordbear->SetSpeed(-10);
	}

	virtual void Show() const override
	{
		std::cout << "Sword-bearer" << std::endl;
		m_swordbear->Show();
	}

private:
	Human * m_swordbear = nullptr;
};

class Archer :public Warrior
{
public:
	Archer(Human * archer)
	{
		m_archer = archer;
		m_archer->SetAttack(20);
		m_archer->SetHealth(50);
		m_archer->SetProtection(10);
		m_archer->SetSpeed(20);
	}

	virtual void Show() const override
	{
		std::cout << "Archer" << std::endl;
		m_archer->Show();
	}
private:
	Human * m_archer = nullptr;
};

class Rider :public SwordBearer
{
public:
	Rider(Human* rider)
	{
		m_rider = rider;
		m_rider->SetAttack(-10);
		m_rider->SetHealth(200);
		m_rider->SetProtection(100);
		m_rider->SetSpeed(40);
	}

	virtual void Show() const override
	{
		std::cout << "Rider" << std::endl;
		m_rider->Show();
	}
private:
	Human * m_rider = nullptr;
};