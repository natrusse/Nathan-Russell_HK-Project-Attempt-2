// Nathan Russell_HK Game Project-2.cpp : Defines the entry point for the console application.
// last edited 2/3/2018 at 10:28
// not currently in github, update asap

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
using std::endl;
using std::cin;
using std::cout;

void persona() {
	//creates a sort of skynet personality
		//endl can be used to substute \n
	cout << "=================================================================\n\n";
	cout << "\tInitiating Skynet.......\n\n";
	cout << "=================================================================\n\n";
	cout << "\tInitializing 8x8 Grid search for enemy.......\n";
	cout << "\n\tEnemy Located within 8x8 Grid!";
	cout << "\n\n\tPrepare to decrypt Grid Information.......\n\n";
}



int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//declaring variables
	int enemylocation = rand() % 64 + 1;
	int binaryTries = 0;
	int binaryGuess;
	int high = 64;
	int low = 1;
	bool isEnemyFoundbyBinarySearch = false;
	string test;

	persona();

	while (isEnemyFoundbyBinarySearch == false) {
		//starts game loop


			//each guess resets the middle number between the high and low
		binaryGuess = ((high - low) / 2) + low;
		++binaryTries;

		//output if guess is too high
		if (binaryGuess > enemylocation)
		{
			cout << "\tSearch grid " << binaryGuess << " yielded no results. Lower guess recommended because enemy location is " << enemylocation << ".\n\n";
			//high decreases to compensate for guess
			high = binaryGuess--;

		}
		//output if guess is too low
		else if (binaryGuess < enemylocation)
		{
			cout << "\tSearch grid " << binaryGuess << " yielded no results. Higher guess recommended because enemy location is " << enemylocation << ".\n\n";
			//low increases to compensate for guess
			low = binaryGuess++;

		}
		//output if the guess is the enemy location
		else if (binaryGuess == enemylocation)
		{
			cout << "\n\tEnemy Located in Grid #" << enemylocation << ". Enemy located in " << binaryTries << " attempts!\n";
			cout << "Preparing to send agents to neutralize.......\n";
			//ends the loop
			isEnemyFoundbyBinarySearch = true;
		}
		//output if incorrect input is used
		else
		{
			cout << "Binary search malfunction, please input within parameters " << high << " and" << low << "." << endl;
			continue;
		}



		//binary search code ends here
	}
	system("pause");
	return 0;
}


