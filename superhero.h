//********************************************************************************************
//Billy Rodriguez  CS162  SuperHeroes
//
//This is the headerfile declaring the superhero structure, node structure, and the constants
//********************************************************************************************

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//constant
const int SIZE{51};

//superhero structure
struct superhero
{
	char name[SIZE];
	char backstory[SIZE];
	char theme[SIZE];
	char powers[SIZE];
	int age;
};

//node structure
struct node
{
	superhero hero;
	node * next;
};

//superhero class
class Hero
{
	public:
		Hero();
		~Hero();
		void main_menu();
		void read_info();
		void display_info();
		int menu_choice;
	private:
		node * head;
};
