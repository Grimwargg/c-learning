#include <iostream>
using namespace std;

int main() {
	//..........................................
	//.............line breaks..................
	//cout << "Hello World!";
	//cout << "\n";	
	//cout << "My Name is Ryan";	
	//cout << "\n";	
	//cout << "Goodbye";
	//cout << "\n\n";

	//cout << "Hello World!";
	//cout << endl;
	//cout << "My Name is Ryan";
	//cout << std::endl;
	//cout << "Goodbye";
	//cout << "\n\n";


	//cout << "Hello World!" << "\n";
	//cout << "My Name is Ryan" << "\n";
	//cout << "Goodbye";
	//..........................................

	//..........................................
	//............outputing numbers.............
	//cout << 15 << " is a number\n"
	//	 << "Another number is " << 52 <<"\n";
	//..........................................

	//..........................................
	//.......variable initialization............
	bool isAlive;
	isAlive = false;	
	//or 
	//Uniform initialization
	bool isDead{ false };
	//or
	//Copy initialization
	bool isSomehow= false;

	/*
	!!!!		USE {} ONLY FOR INITIALIZATION
	*/
	string Name{ "Goblin Warrior" };
	int Level{ 10 };

	cout << "The monster's name is " << Name<< "\nand its level is " << Level;


	int MaxHealth{ 150 };
	int CurrentHealth{ MaxHealth };
	cout << "\nCurrent Health is: " << CurrentHealth;



}