#include <iostream>
using namespace std;

//Billy Rodriguez
//CS162
//Assignment 1
//******************************************************************************************************
//In this program, it’s being asked for us to help calculate the costs of going up to the mountain
//at Timberline for the day. The trip will all be dependent on the user on how many people they will
//bring, whether it’s peak time or not and when they’re going, their ages and if they’re there tubing 
//or for snowboarding or just beginners. The user will also be prompted the option to include any rental
//equipment if purchased over at Timberline. With all the following information that has been input, 
//a final calculation will be made and will determine the final cost of the trip!
//******************************************************************************************************

int main()
{

	//Welcome Message
        cout << "Welcome to the Timberline Expense calculator!\n" << endl;
	cout << "This program will help calculate the costs of going up "
	     << "the mountain at Timberline for the day!\n"<< endl;

	int menu{1};                    //this is the menu choice for the program

//Whole program will keep running until user enters a 2 to stop
while(menu == 1)
{	
	//variables
	float total_cost{0};   		//the total cost of Timberline trip
	int total_people{0};    	//the total amount of people on the trip
	int peak_time{0};       	//deciding whether it's peak time or non-peak
	int day_time{0};        	//deciding the time of day it is
	int people_age{0};      	//what age is everyone in the group
	char tubing_activity{'y'};	//to determine if they are just tubing
	char activity_check{'y'};  	//to see if they're beginners or snowboarders
	int count{1};	     		//used to keep track on individual questions for each person
	char rental_choice{'y'};	//check if group bought any rental equipment or not
	float rental_equip{0.00};  	//how much money in total they spent on equipment
	int child {0};			//when group member is 6 or below of age
	int junior_senior {0};		//when group member is 7-14 or 65+ of age
	int teen {0};			//when group member is 15-17 of age
	int adult {0};			//when group member is 18-64 of age
	float final_cost{0};		//the total cost of Timberline trip	


	do
	{
		//get menu option
	        cout << "\n1.Start 2.Stop" << endl;
		cout << "\nEnter: ";
		 cin >> menu;
		if (menu != 1 && menu != 2)		
			cout << "Invalid choice, please try again!\n" << endl; //displays error message if choice isn't valid
	}	while (menu != 1 && menu != 2);



	//when user enters 2, program ends
	if (menu == 2)
		cout << "\nGoodbye!" << endl;


	//when user enters 1, program starts
	else if (menu == 1)
	{
       		do
		{
			//get total people going on the trip
			cout << "\nAmount of people: ";
			cin >> total_people;
			cout << endl;
			if (total_people < 1)
				cout << "Invalid number of people!"
			     	<< endl << "\nPlease enter a corrent number.";
		} while (total_people < 1);


		do
		{	
			//read in users choice in whether he's going during peak/non-peak times
			cout << "\n1.Peak time \n2.Non-Peak time"<< endl;
			cout << "\nEnter choice: ";
			cin  >> peak_time;
			cout << endl;
			if (peak_time != 1 && peak_time != 2)
				cout << "Invalid choice!"
			     	<< endl << "\nPlease enter a correct choice: ";	 
		} while (peak_time != 1 && peak_time != 2);


		do
		{
			//when they're going for this trip
			cout << "\nWhen are you going to Timberline?" << endl;
			cout << "1.all day \n2.afternoon only \n3.night only" << endl;
			cout << "\nEnter choice: ";
			cin  >> day_time;
			cout << endl << endl;
			if (day_time < 1 || day_time > 3)
				cout << "Invalid choice!"
			     	<< endl << "\nPlease enter a correct choice.\n";
		} while (day_time < 1 || day_time >3);



        		//individual questions asked for each person
		 	cout << "The following questions will be asked"
        	      	<< " for each individual person in the group"
        		<< endl << endl;
	

		while (count <= total_people)
		{	
			do
			{	
				cout << "\nPerson #" << count << endl;
				cout << "What is your age?: ";
		 		cin >> people_age;	
				if (people_age < 1)
					cout << "Invalid age!\n";
		             
			} while (people_age < 1);
			do
			{
				cout << "\nAre you just interested in tubing?(y/n): ";
		 		cin >> tubing_activity;
				if (tubing_activity != 'y' && tubing_activity != 'n')
					cout << "Invalid option!"
			     		<< endl << "\nEnter(y/n): ";
			} while (tubing_activity != 'y' && tubing_activity != 'n');
	
			do
			{
				if (tubing_activity == 'n')
				{
				cout << "\nAre you a beginner/snowboarder?(y/n): ";
		 		cin >>	activity_check;
				}
				if (activity_check != 'y' && activity_check != 'n')
					cout << "Invalid choice!"
			     		<< endl << "\nEnter(y/n): ";
			} while (activity_check != 'y' && activity_check != 'n');


			//Determining age group for person
			if (people_age <= 6)
				child = 1;
			
			if (people_age >= 7 && people_age <= 14 || people_age >= 65)
				junior_senior = 1;

			if (people_age >= 15 && people_age <= 17)
				teen = 1;
			
			if (people_age >= 18 && people_age <= 64)
				adult = 1;
			

			//Calculations for peak time
			if (peak_time == 1)
			{
				if (day_time == 1)	//all-day			
				{
					if (child == 1)
						total_cost = 0.00;
					else if (junior_senior == 1)
						total_cost = 79.00;
					else if (teen == 1)
						total_cost = 119.00;
					else if (adult == 1)	
						total_cost = 145.00;
				}
				
				if (day_time == 2)	//afternoon
				{
					if (child == 1)
						total_cost = 0.00;
					else if (junior_senior == 1)
						total_cost = 79.00;
					else if (teen == 1)
						total_cost = 88.00;
					else if (adult == 1)
						total_cost = 97.00;
				}

				if (day_time == 3)	//night
				{
					if (people_age >= 7)
						total_cost = 54.00;
				}

			}


			//Calculations for non-peak time
			if (peak_time == 2)
			{

				if (day_time == 1)      //all-day
				{
					if (child == 1)
						total_cost = 0.00;
					else if (junior_senior == 1)
						total_cost = 75.00;
					else if (teen == 1)
						total_cost = 101.00;
					else if (adult == 1)
						total_cost = 114.00;
				}

				if (day_time == 2)      //afternoon
				{
					if (child == 1)
						total_cost = 0.00;
					else if (junior_senior == 1)
						total_cost = 75.00;
					else if (teen == 1)
						total_cost = 75.00;
					else if (adult == 1)
						total_cost = 88.00;
				}

				if (day_time == 3)      //night
				{
					if (people_age >= 7)
						total_cost = 54.00;
				}
			}
			

			//Calculations for beginners/snowboarders
			if (tubing_activity == 'n' && activity_check == 'y')
			{
				if (day_time == 1)	//all day
				{
					if (child == 1)
						total_cost = 0.00;
					else if (people_age >= 7 & people_age <= 17)	//junior/senior age group
						total_cost = 38.00;
					else if (adult == 1)
						total_cost = 54.00;
				}

				if (day_time == 2)      //afternoon
				{
					if (child == 1)
						total_cost = 0.00;
					else if (people_age >= 7 & people_age <= 17)    //junior/senior age group
						total_cost = 34.00;
					else if (adult == 1)
						total_cost = 44.00;
				}
			}


			//Calculation for just tubing
			if (tubing_activity == 'y')
				total_cost = 28.00;
				

		count += 1; //keeps track for each person in the group
		final_cost = final_cost + total_cost; //adds each person's total cost to the final cost value
		}



		//Have an option to include rental equipment purchased
		cout << "\nThe last question is for the whole group.";

		do
		{
			cout << "\nAny rental equipment purchased?(y/n): ";
		 	cin >> rental_choice;
			if (rental_choice != 'y' && rental_choice != 'n')
				cout << "Invalid option!"
			     	<< endl << "\nEnter(y/n): ";
		} while (rental_choice != 'y' && rental_choice != 'n');
	
		
		if (rental_choice == 'y')
		{
			do
			{		
				cout << "\nEnter total amount spent:$";
		 	 	cin >> rental_equip;
	       		if (rental_equip <= 0)
				cout << "Not possible, enter a real number.\n";	
			} while (rental_equip <= 0);
			final_cost = final_cost + rental_equip; //adds rental equipment price to final cost

			cout << "\nThe total cost of your trip will be $" << final_cost << "!";
		}	


		if (rental_choice == 'n')
			cout << "\nThe total cost of your trip will be $" << final_cost << "!\n";

		//Prompt user if they want to start the program again
		cout << "\nWould you like to use the calculator again?\n";
	  
	}
}
	return 0;		
}
