#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
//*************************************************************
//Billy Rodriguez   CS162  Assignment 3
//This program will collect information from the user,
//specifically from their pokemon card collection. It will save
//and store all their pokemon cards but only 10 can be saved,
//any more than that and it will not take the next card.
//*************************************************************


//constants
const int SIZE{51};
const int MAX_CARDS{10};

//structure
struct pokemon_card
{
	char pokemon_name[SIZE];
	char pokemon_description[SIZE];
	char pokemon_type[SIZE];
	float card_value{0.00};
	int base_set{0};
};


//prototype functions
void match_pokemon(pokemon_card match[], int & card_counter); //match pokemon card
void main_menu(int & choice); //main menu
void read_from_file(pokemon_card card[], int & card_counter); //load pokemon cards
bool display_pokemon(pokemon_card display[], int & card_counter); //display pokemon cards
void write_to_file(pokemon_card & save); //save pokemon cards
void read_pokemon(pokemon_card collection[], int & card_counter); //new pokemon card

int main()
{
	//variables initialized
	pokemon_card collection[MAX_CARDS];
	int card_counter{0}; //keep count of cards saved
	int choice{0}; //menu choice

	cout << "Welcome to the pokemon card collection program!" << endl;
do
{
	main_menu(choice);
	
	//Enter pokemon card
	if(choice == 1)
	read_pokemon(collection, card_counter);
	
	//Display all pokemon cards	
	if(choice == 2)
	{	if (!display_pokemon(collection, card_counter))
		cout << "Nothing to display!";
	}
	
	
	//Find matching pokemon card
	if(choice == 3)
	match_pokemon(collection, card_counter);


	//Save all pokemon cards
	if(choice == 4)
	{
		for(int i{0}; i < card_counter; ++i)
		{
			write_to_file(collection[i]);
		}
	}

	//Load pokemon cards
	if(choice == 5)
	read_from_file(collection, card_counter);

	//Exit program
	if(choice == 6)
	cout << "Goodbye!";
}while(choice != 6);


	return 0;
}

//finds pokemon card
void match_pokemon(pokemon_card match[], int & card_counter)
{
	char pokemon_search[SIZE];

	cout << "Enter pokemon card: ";
	cin.get(pokemon_search, SIZE, '\n');

	//caplocks doesn't matter on first letter
	pokemon_search[0] = toupper(pokemon_search[0]);

	bool found = false;
	
	//comparing between user input and pokemon collection to find identical card	
	for(int i{0}; i < card_counter; ++i)
	{
		match[i].pokemon_name[0] = toupper(match[i].pokemon_name[0]);
		if(strcmp(match[i].pokemon_name, pokemon_search) == 0)
		{
			cout << match[i].pokemon_name << '\n' << match[i].pokemon_description
			<< '\n' << match[i].pokemon_type << "\n$" << match[i].card_value << '\n'
			<< match[i].base_set << endl;

			found = true;
		}
	}
		//no identical pokemon card found
		if (!found)
		cout << "No match found..." << endl;
}

//prompts user main-menu
void main_menu(int & choice)
{
	cout << "\n1. Enter a new pokemon card" << endl;
	cout << "2. Display all cards" << endl;
	cout << "3. Match a particular card" << endl;
	cout << "4. Save all cards" << endl;
	cout << "5. Load cards saved" << endl;
	cout << "6. Quit" << endl;
	cout << endl << "Enter Choice: ";
	cin >> choice;
	cin.ignore(100,'\n');
}

//load card information from collectables.txt external data file
void read_from_file(pokemon_card card[], int & card_counter)
{
	ifstream file_in;
	file_in.open("collectables.txt");
	if(file_in)
	{
		file_in.get(card[card_counter].pokemon_name,SIZE,'|');
		file_in.ignore(100,'|');
		
		while(!file_in.eof() && card_counter < MAX_CARDS)
		{
			file_in.get(card[card_counter].pokemon_description,SIZE,'|');
			file_in.ignore(100,'|');

			file_in.get(card[card_counter].pokemon_type,SIZE,'|');
			file_in.ignore(100,'|');

			file_in >> card[card_counter].card_value;
			file_in.ignore(100,'|');

			file_in >> card[card_counter].base_set;
			file_in.ignore(100,'\n');
			++card_counter;
			
				file_in.get(card[card_counter].pokemon_name,SIZE,'|');
				file_in.ignore(100,'|');
		
		}
		cout << endl << "<<SUCESSFULLY LOADED FILE>>";
		file_in.close();
	}
}

//display pokemon cards saved from external data file
bool display_pokemon(pokemon_card display[], int & card_counter)
{
	if(card_counter == 0) return false;	

	for (int i = 0; i < card_counter; ++i)
	{
	cout << display[i].pokemon_name << '\t' << display[i].pokemon_description
	<< '\t' << display[i].pokemon_type << "\t$" << display[i].card_value << '\t'
	<< display[i].base_set << endl;
	}
	return true;
}

//save card information to external data file
void write_to_file(pokemon_card & save)
{
	ofstream file_out;
	file_out.open("collectables.txt", ios::app);
	if(file_out)
	{

		file_out << save.pokemon_name << '|' << save.pokemon_description << '|'
		<< save.pokemon_type << '|' << save.card_value << '|' << save.base_set << endl;
		
		cout << endl << "<<SUCCESSFULLY SAVED FILE>>";
		file_out.close();
	}
}


//prompt user for pokemon card information and stop when 10 cards entered
void read_pokemon(pokemon_card collection[], int & card_counter)
{
	//when collection hits 10 pokemon cards
	if(card_counter >= MAX_CARDS)
	{
		cout << "You have reached the maximum number of cards." << endl;
		return;
	}

	cout << "Enter Pokemon name: ";
	cin.get(collection[card_counter].pokemon_name,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter Pokemon description: ";
	cin.get(collection[card_counter].pokemon_description,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter Pokemon type: ";
	cin.get(collection[card_counter].pokemon_type,SIZE,'\n');
	cin.ignore(100,'\n');

	cout << "Enter card value: $";
	cin >> collection[card_counter].card_value;
	cin.ignore(100,'\n');

	cout << "Enter base set: ";
	cin >> collection[card_counter].base_set;
	cin.ignore(100,'\n');

	++card_counter;
}


