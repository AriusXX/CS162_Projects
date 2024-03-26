//*************************************************************
//Billy Rodriguez  CS162  Program 4
//
//These are all the functions for the program.
//*************************************************************

#include "games.h"

//constructor
Game_List::Game_List()
{
	games = nullptr;
	game_counter = 0;
	num_games = 0;
	menu_choice = 0;

	//allow user to add the amount of games they want
	cout << endl << "How many games would you like to enter?: ";
	cin >> num_games;
	cin.ignore(100,'\n');

	games = new GameInfo[num_games];



}

//deconstructor
Game_List::~Game_List()
{
	if(games != NULL)
		delete [] games;
	game_counter = 0;
	num_games = 0;
	menu_choice = 0;
}


//main menu
void Game_List::main_menu()
{
	cout << endl << "****************************************";
	cout << "\n1.Add game" << endl;
	cout << "2.Display Games" << endl;
	cout << "3.Match a particular title" << endl;
	cout << "4.Match a particular genre" << endl;
	cout << "5.Quit" << endl;
	cout << "****************************************";
	cout << endl << "Enter Choice: ";
	cin >> menu_choice;
	cin.ignore(100,'\n');
}


//user input for a video game
void Game_List::read_game()
{
	//allow user to pick size length of their review
	int * review;
	review = nullptr;
	int review_size = 0;

	//when games exceed users # of videogames choice, display this message
	if(game_counter >= num_games)
	{
		cout << "You have reached the maximum video games." << endl;
		return;
	}
		
	cout << "Game Name: ";
	cin.get(games[game_counter].name,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Genre: ";
	cin.get(games[game_counter].genre,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Date Released: ";
	cin.get(games[game_counter].date_released,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Main Protagonist: ";
	cin.get(games[game_counter].main_protagonist,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Number of players: ";
	cin.get(games[game_counter].num_players,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "How long of a review would you like to add?" << endl;
	cout << "Length Size: ";
	cin >> review_size;
	cin.ignore(100,'\n');
	review = new int(review_size);
	cout << "Review: ";
	cin.get(games[game_counter].review,review_size,'\n');
	cin.ignore(100,'\n');

	++game_counter;

	delete review;
}

//display video games
bool Game_List::display()
{
	if(game_counter == 0) return false;

	for(int i{0}; i < game_counter; ++i)
	{
		cout << games[i].name << '\t' << games[i].genre << '\t' << games[i].date_released
		<< '\t' << games[i].main_protagonist << '\t' << games[i].num_players << '\t' << games[i].review << endl;
	}
	return true;
}

//match with a corresponding video game title
void Game_List::match_title()
{

	char title_search[SIZE];
	int search_length{0};

	cout << "Enter videogame title: ";
	cin.get(title_search,SIZE,'\n');
	cin.ignore(100,'\n');

	search_length = strlen(title_search);

	for(int i{0}; i < search_length; ++i)
		title_search[i] = toupper(title_search[i]);

	bool found = false;

	for(int i{0}; i < game_counter; ++i)
	{
		char uppercase_name[SIZE];
		int length_name{0};
		strcpy(uppercase_name, games[i].name);
		length_name = strlen(uppercase_name);

		//capitalize all words to find a match regardless of capslock
		for(int j{0}; j < length_name; ++j)
		{
			uppercase_name[j] = toupper(uppercase_name[j]);
		}
		if(strcmp(uppercase_name, title_search) == 0)
		{
		cout << games[i].name << '\t' << games[i].genre << '\t' << games[i].date_released
		<< '\t' << games[i].main_protagonist << '\t' << games[i].num_players << '\t' << games[i].review << endl;
		
		found = true;
		}
	}

	if(!found)
		cout << "No match found..." << endl;
}


//match with a corresponding video game genre
void Game_List::match_genre()
{
	char genre_search[SIZE];
	int genre_length{0};

	cout << "Enter videogame genre: ";
	cin.get(genre_search,SIZE,'\n');
	cin.ignore(100,'\n');

	genre_length = strlen(genre_search);

	for(int i{0}; i < genre_length; ++i)
		genre_search[i] = toupper(genre_search[i]);

	bool found = false;

	for(int i{0}; i < game_counter; ++i)
	{
		char uppercase_name[SIZE];
		int length_name{0};
		strcpy(uppercase_name, games[i].genre);
		length_name = strlen(uppercase_name);	

		//capitalize all words to find a match regardless of capslock
		for(int j{0}; j < length_name; ++j)
		{
			uppercase_name[j] = toupper(uppercase_name[j]);
		}
		if(strcmp(uppercase_name, genre_search) == 0)
		{
		cout << games[i].name << '\t' << games[i].genre << '\t' << games[i].date_released
		<< '\t' << games[i].main_protagonist << '\t' << games[i].num_players << '\t' << games[i].review << endl;
		
		found = true;
		}
	}

	if(!found)
		cout << "No match found..." << endl;
}


