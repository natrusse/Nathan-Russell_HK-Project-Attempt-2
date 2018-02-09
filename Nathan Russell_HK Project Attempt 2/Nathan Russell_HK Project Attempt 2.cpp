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
	//todo add variables for other players 
	int enemylocation = rand() % 64 + 1;
	int binaryTries = 0;
	int randomTries = 0;
	int linearTries = 0;
	int binaryGuess;
	int randomGuess;
	int linearGuess;
	int high = 64;
	int low = 1;
	bool isEnemyFoundbyBinarySearch = false;
	bool isEnemyFoundbyrandomSearch = false;
	bool isEnemyFoundbylinearSearch = false;
	string test;

	persona();

	//todo add human search player


	//linear ai search player
	while (isEnemyFoundbylinearSearch == false) {
		//starts game loop


		//each guess resets the middle number between the high and low
		linearGuess = ((high - low) / 2) + low;
		++linearTries;

		//output if guess is too high
		if (linearGuess > enemylocation)
		{
			cout << "\tSearch grid " << linearGuess << " yielded no results. Lower guess recommended because enemy location is " << enemylocation << ".\n\n";
			//high decreases to compensate for guess
			high = linearGuess--;

		}
		//output if guess is too low
		else if (linearGuess < enemylocation)
		{
			cout << "\tSearch grid " << linearGuess << " yielded no results. Higher guess recommended because enemy location is " << enemylocation << ".\n\n";
			//low increases to compensate for guess
			low = linearGuess++;

		}
		//output if the guess is the enemy location
		else if (linearGuess == enemylocation)
		{
			cout << "\n\tEnemy Located in Grid #" << enemylocation << ". Enemy located in " << linearTries << " attempts!\n";
			cout << "Preparing to send agents to neutralize.......\n";
			//ends the loop
			isEnemyFoundbylinearSearch = true;
		}
		//output if incorrect input is used
		else
		{
			cout << "linear search malfunction, please input within parameters " << high << " and" << low << "." << endl;
			continue;
		}



		//linear search code ends here
	}

	//random ai search player
	while (isEnemyFoundbyrandomSearch == false) {
		//starts game loop


		//each guess resets the middle number between the high and low
		randomGuess = ((high - low) / 2) + low;
		++randomTries;

		//output if guess is too high
		if (randomGuess > enemylocation)
		{
			cout << "\tSearch grid " << randomGuess << " yielded no results. Lower guess recommended because enemy location is " << enemylocation << ".\n\n";
			//high decreases to compensate for guess
			high = randomGuess--;

		}
		//output if guess is too low
		else if (randomGuess < enemylocation)
		{
			cout << "\tSearch grid " << randomGuess << " yielded no results. Higher guess recommended because enemy location is " << enemylocation << ".\n\n";
			//low increases to compensate for guess
			low = randomGuess++;

		}
		//output if the guess is the enemy location
		else if (randomGuess == enemylocation)
		{
			cout << "\n\tEnemy Located in Grid #" << enemylocation << ". Enemy located in " << randomTries << " attempts!\n";
			cout << "Preparing to send agents to neutralize.......\n";
			//ends the loop
			isEnemyFoundbyrandomSearch = true;
		}
		//output if incorrect input is used
		else
		{
			cout << "random search malfunction, please input within parameters " << high << " and" << low << "." << endl;
			continue;
		}



		//random search code ends here
	}

	//binary search player
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
	
	//todo add final stats (list all player tries)

	//todo ask human player to play again

	system("pause");
	return 0;
}


