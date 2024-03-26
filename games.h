//*************************************************************
//Billy Rodriguez  CS162  Program 4
//
//This is the header file for video game collection
//*************************************************************

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE{101};


//video game information
struct GameInfo
{
	char name[SIZE];
	char genre[SIZE];
	char date_released[SIZE];
	char main_protagonist[SIZE];
	char num_players[SIZE];
	char review[SIZE];
};


class Game_List
{
	public:
		Game_List(); 		//constructor
		~Game_List(); 		//deconstructor

		void main_menu();	//main menu
		void read_game(); 	//prompt user to enter video games
		bool display(); 	//display all video games in array
		void match_genre();	//match a particular video game genre
		void match_title();	//match a particular video game title
		int menu_choice;

	private:
		GameInfo * games;	//to create users choice on how many games they want to input
		int game_counter;	//when to stop adding games
		int num_games;		//total number of games
};


