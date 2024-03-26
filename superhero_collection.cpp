//********************************************************************
//Billy Rodriguez  CS162  Superheroes
//
//This program will prompt the user to enter their favorite superheros
//and keep track of their collection.
//********************************************************************

#include "superhero.h"

int main()
{
	cout << "Welcome to the superheroes program!" << endl;
	cout << "This program will keep track of the superheros in your collection!" << endl;

	Hero heroes;

//main menu
do
{	
	heroes.main_menu();

	if(heroes.menu_choice == 1)
	heroes.read_info();

	if(heroes.menu_choice == 2)
	heroes.display_info();
	
}while(heroes.menu_choice != 3);




	return 0;
}
