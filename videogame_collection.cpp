//*************************************************************
//Billy Rodriguez  CS162  Program 4
//
//This program will prompt the user to enter a desirable amount
//of video games they would like to enter. The following prompt
//will ask the name of the game, the genre, date released, 
//the main protagonist of the game, number of players supported
//and a final review.
//*************************************************************

#include "games.h"

int main()
{
	cout << "Welcome to the videogame collection program!" << endl;

	//initialized variables
	Game_List game_list;
do
{
		game_list.main_menu();

		//read in a video game
		if(game_list.menu_choice == 1)
		game_list.read_game();
		
		//display all games
		if(game_list.menu_choice == 2)
		game_list.display();
		
		//match particular title
		if(game_list.menu_choice == 3)
		game_list.match_title();

		//match particular genre
		if(game_list.menu_choice == 4)
		game_list.match_genre();


}while(game_list.menu_choice != 5);	


	cout << endl << "Goodbye!" << endl;

	return 0;
}

