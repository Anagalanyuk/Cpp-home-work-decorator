#pragma once

#include"Rasa.h"

class Elf :public Rasa
{
public:
	Elf() 
	{
	};

	int Setattack(int attack)
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

	int SetProtaction(int protection)
	{
		return m_protection += protection;
	}

	virtual void Show() const override
	{
		std::cout << "Elf" << std::endl;
		std::cout << "Attack: " << m_attack << std::endl;
		std::cout << "Speed: " << m_speed << std::endl;
		std::cout << "Health: " << m_health << std::endl;
		std::cout << "Protection: " << m_protection << std::endl;
	}

private:
	int m_attack = 15;
	int m_speed = 30;
	int m_health = 100;
	int m_protection = 0;
};

class ProfessionalElf :public Elf
{
protected:
	ProfessionalElf() 
	{
	};

	ProfessionalElf(Elf* elf):
		m_elf(elf)
	{
	}

	Elf* GetElf() const
	{
		return m_elf;
	}

private:
	Elf * m_elf = nullptr;
};

class WarriorElf :public ProfessionalElf
{
public:
	WarriorElf()
	{
	}

	WarriorElf(Elf* elf) :ProfessionalElf(elf)
	{
		m_warrior = elf;
		m_warrior->Setattack(20);
		m_warrior->SetHealth(100);
		m_warrior->SetProtaction(20);
		m_warrior->SetSpeed(10);
	}

	virtual void Show() const override
	{
		std::cout << "Warrior Elf" << std::endl;
		GetElf()->Show();
	}
private:
	Elf * m_warrior = nullptr;
};

class MageElf:public ProfessionalElf
{
public:
	MageElf()
	{
	}

	MageElf(Elf* elf) :ProfessionalElf(elf)
	{
		m_mage = elf;
		m_mage->Setattack(10);
		m_mage->SetHealth(-50);
		m_mage->SetProtaction(10);
		m_mage->SetSpeed(10);
	}

	virtual void Show()const override
	{
		std::cout << "Mage" << std::endl;
		GetElf()->Show();
	}
private:
	Elf *m_mage = nullptr;
};

class Crossbowman :public WarriorElf
{
public:
	Crossbowman(Elf* elf)
	{
		m_crossbowman = elf;
		m_crossbowman->Setattack(20);
		m_crossbowman->SetHealth(50);
		m_crossbowman->SetProtaction(-10);
		m_crossbowman->SetSpeed(10);
	}

	virtual void Show()const override
	{
		std::cout << "Crossbowman" << std::endl;
		m_crossbowman->Show();
	}
private:
	Elf * m_crossbowman = nullptr;
};

class EvileMage :public MageElf
{
public:
	EvileMage(Elf* elf)
	{
		m_evilemage = elf;
		m_evilemage->Setattack(70);
		m_evilemage->SetHealth(0);
		m_evilemage->SetProtaction(0);
		m_evilemage->SetSpeed(20);
	}

	virtual void Show() const override
	{
		std::cout << "Evile Mage" << std::endl;
		m_evilemage->Show();
	}
private:
	Elf * m_evilemage = nullptr;
};

class GoodMage :public MageElf
{
public:
	GoodMage(Elf* elf)
	{
		m_goodmage = elf;
		m_goodmage->Setattack(50);
		m_goodmage->SetHealth(30);
		m_goodmage->SetProtaction(30);
		m_goodmage->SetSpeed(30);
	}

	virtual void Show()const override
	{
		std::cout << "Good Mage" << std::endl;
		m_goodmage->Show();
	}
private:
	Elf * m_goodmage = nullptr;
};