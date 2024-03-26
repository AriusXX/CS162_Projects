#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//**************************************************************
//Biily Rodriguez  CS162  Program 2
//
//The purpose of this program is to help the user autocorrect
//from any of the supported words after pressing the tab key.
//The supported words are "another", "therefore", "their" and
//"however". The program will not autocorrect for the following
//words, "a", "the", and "and".
//**************************************************************

//constants declared
int const SIZE{251};

//prototype functions
void welcome();
int get_sentence(char sentence[]);
void copy_sentence(char copy[], char sentence[], int length);
void autocorrect(char copy[], bool first, bool second, bool third, bool fourth);
void check_word(char word[]);



int main()
{
	//variables initialized
	char sentence[SIZE];
	char copy[SIZE];
	int length;
	char choice;

	//loop program
	do
	{
	for(int i{0}; i < SIZE; ++i) //resets array for new startup
	{
		copy[i] = '\0';		
	}

	//call functions
	welcome();
	length = get_sentence(sentence);
	copy_sentence(copy, sentence, length);
	
	cout << endl << copy << endl;

	cout << endl << "Do you want to continue? (y/n):";
	cin >> choice;
	cin.ignore(100,'\n');
	} while(tolower(choice) == 'y');

	cout << "Thanks for using my program!" << endl;

	return 0;
}

//check if tab word matches with any of the supported words
void check_word(char word[])
{
	//check if word matches up
	bool first = false;
	bool second = false;
	bool third = false;
	bool fourth = false;

	//supported words	
	char first_word[8] = "another";
	char second_word[10] = "therefore";
	char third_word[6] = "their";
	char fourth_word[8] = "however";

	//unsupported words
	char first_not[2] = {'a', '\0'};
	char second_not[4] = "the";
	
	//converting word to all lowercase
	for(int i{0}; word[i] != '\0'; ++i)
	{
		word[i] = tolower(word[i]);
	}

	//iterating through word to see which word it matches
	if (strncmp(word, first_word, strlen(word)) == 0 && strncmp(word, first_not, strlen(word)) != 0)
		first = true;
	if (strncmp(word, second_word, strlen(word)) == 0 && strncmp(word, second_not, strlen(word)) != 0)
		second = true;	
	if (strncmp(word, third_word, strlen(word)) == 0 && strncmp(word, second_not, strlen(word)) != 0)
		third = true;
	if (strncmp(word, fourth_word, strlen(word)) == 0)
		fourth = true;


		//sending in boolean values to autocorrect
		autocorrect(word, first, second, third, fourth);


	

}


//takes in the matching supported word and autocorrects it
void autocorrect(char word[], bool first, bool second, bool third, bool fourth)
{
	//supported words
	char first_word[8] = "another";
	char second_word[10] = "therefore";
	char third_word[6] = "their";
	char fourth_word[8] = "however";

	//autocorrecting to the correct word
	if(first)
	{
		int len = strlen(first_word);
		strncpy(word, first_word, len);
		word[len] = '\0';
	}


	if(second)
	{

		int len = strlen(second_word);
		strncpy(word, second_word, len);
		word[len] = '\0';
	}


	if(third)
	{

		int len = strlen(third_word);
		strncpy(word, third_word, len);
		word[len] = '\0';
	}

	if(fourth)
	{

		int len = strlen(fourth_word);
		strncpy(word, fourth_word, len);
		word[len] = '\0';
	}

}




//create user's new sentence
void copy_sentence(char copy[], char sentence[], int length)
{
	int copy_index = 0;
	char word[10] = {'\0'};
	
	//iterating through each character in the sentence
	for(int i = 0; i <= length; ++i)
	{
		//looking at each word separate
		if(sentence[i] == '\t' || sentence[i] == ' ' || sentence[i] == '\0')
		{
			//a word with a tab found
			if(sentence[i] == '\t')
			{
				//only for autocorrected word
				if (strlen(word) > 0)
				{
				check_word(word);
				strcat(copy, word); //append autocorrect word to sentence
				strcat(copy, " "); //append space
				word[0] = '\0';
				}
			}
			//words without needing autocorrect
			else
			{
				strcat(copy, word);
				if(sentence[i] != '\0')
				{
				strcat(copy, " "); //appending space
				}
				word[0] = '\0';
			}
		}
			else
			{
			//append character to word
			strncat(word, &sentence[i], 1);
			}
	}
}



//read in user's sentence
int get_sentence(char sentence[])
{
	cout << "<hit tab to autocorrect [another, therefore, their, however]>\n" << endl;
	cout << "<NOT SUPPORTED WORDS [ a, the, and ]>\n" << endl;
	cout << "Enter a sentence:";
	cin.get(sentence,SIZE,'\n');
	cin.ignore(100,'\n');
	
	//error due to overexceeding 250 word limit
	if (strlen(sentence) >= SIZE - 1)
	{
		cout << "Sentence exceeds 250 words!" << endl;
		sentence[0] = '\0';
		return 0;
	}
	return strlen(sentence);
}


//welcome message to the user
void welcome()
{
	cout << "Welcome to the autocorrect program!" << endl;
	cout << "\nIn the following program, you will be "
	     << "prompted to input a sentence with having "
	     << "the power to autocorrect any of the following "
	     << "words by simply pressing tab." << endl;
}


