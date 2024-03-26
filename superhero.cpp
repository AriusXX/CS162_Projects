//********************************************************************
//Billy Rodriguez  CS162  Superheroes
//
//This shows all the functions I will be working with in the program
//********************************************************************

#include "superhero.h"

Hero::Hero()
{
	head = nullptr;		
	menu_choice = 0;
}


Hero::~Hero()
{
	node * current = head;

	while(current)
	{
		node * temp = current->next;
		delete current;
		current = temp;
	}
	
	head = nullptr;
}


//main menu
void Hero::main_menu()
{
	cout << endl << "****************************************";
	cout << "\n1.Add Superhero" << endl;
	cout << "2.Display Superheroes" << endl;
	cout << "3.Quit" << endl;
	cout << "****************************************";
	cout << endl << "Enter Choice: ";
	cin >> menu_choice;
	cin.ignore(100,'\n');
}


//Prompts user superhero to add to collection
void Hero::read_info()
{
	//create new node everytime user chooses menu choice 1
	node * newHero = new node;

	cout << "\nEnter superhero name: ";
	cin.get(newHero->hero.name,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter superhero backstory: ";
	cin.get(newHero->hero.backstory,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter superhero theme: ";
	cin.get(newHero->hero.theme,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter superhero powers: ";
	cin.get(newHero->hero.powers,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter superhero age: ";
	cin >> newHero->hero.age;
	cin.ignore(100,'\n');

	//set superhero as last in collection
	newHero->next = nullptr;

	//for first superhero
	if(!head)
		head = newHero;

	//for heroes after first
	else
	{
		node * current = head;
		while(current->next)
		{
			current = current->next;
		}
		current->next = newHero;
	}
}

void Hero::display_info()
{
	//check if there are any superheroes
	if(!head)
		cout << "No superheroes in the list..." << endl;

	//set a traversing pointer
	node * current = head;

	//traverse until last superhero and display each one
	while(current)
	{
		cout << current->hero.name << '\t' << current->hero.backstory << '\t' << current->hero.theme << 
		'\t' << current->hero.powers << '\t' << current->hero.age << endl;
		current = current->next;
	}
}
	
