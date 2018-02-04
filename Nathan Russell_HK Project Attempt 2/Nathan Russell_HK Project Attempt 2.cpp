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

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int enemylocation = rand() % 64 + 1;
	int tries = 0;
	int guess;
	int high = 64;
	int low = 1;
	string test;

	//creates a sort of skynet personality
	//endl can be used to substute \n
	cout << "\tInitiating Skynet.......\n\n";
	cout << "=================================================================\n\n";
	cout << "\tInitializing 8x8 Grid search for enemy.......\n";
	cout << "\n\tEnemy Located within 8x8 Grid!";
	cout << "\n\n\tPrepare to decrypt Grid Information.......\n\n";

	while (true) {
		srand(static_cast<unsigned int>(time(0)));
		enemylocation = rand() % 64 + 1;
		tries = 0;
		guess = 0;
		high = 64;
		low = 1;

		do
		{
			//each guess resets the middle number between the high and low
			guess = ((high - low) / 2) + low;
			++tries;

			if (guess > enemylocation)
			{
				cout << "Search grid " << guess << " yielded no results. Lower guess recommended.....\n\n";
				//high decreases to compensate for guess
				high = guess--;

			}
			else if (guess < enemylocation)
			{
				cout << "Search grid " << guess << " yielded no results. Higher guess recommended.....\n\n";
				//low increases to compensate for guess
				low = guess++;

			}
			if (guess == enemylocation)
			{
				cout << "\n\tEnemy Located in Grid #" << enemylocation << ". Enemy located in " << tries << " attempts!\n";
				cout << "Preparing to send agents to neutralize.......\n";

			}

		} while (guess != enemylocation);

		cout << "\nDo you wish to continue? (y/n)" << endl;
		cin >> test;

		if (test == "y") {
			cout << "Restarting program......" << endl;
			continue;
		}

		if (test == "n") {
			system("pause");
			return 0;
		}
	}
	system("pause");
}
