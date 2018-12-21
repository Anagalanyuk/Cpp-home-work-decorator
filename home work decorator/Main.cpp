#include<iostream>

#include"Human.h"

#include"Elf.h"

using namespace std;

int main()
{


	Elf elf;
	elf.Show();

	cout << endl;

	GoodMage mage(&elf);
	mage.Show();
	
	//Human foo;
	//foo.Show();

	//cout << endl;

	//Rider bar(&foo);
	//bar.Show();

	//Warrior bar(&foo);
	//bar.Show();

	//cout << endl;

	//SwordBearer foo1(&foo);
	//foo1.Show();


	system("pause");
}