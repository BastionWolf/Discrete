/* -------------------------------------------------------------------

	Name: Daniel Portillo

	Course: CS 2433-101, Fall 2020, Stringfellow

	Purpose: This program finds the highest (Leftmost) bit of a given
			 number	of a file and finds the number with the next
		     highest bit.

--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ONE = 1;

int FindHighestBit(int k1);
int GetK2(int k2, int highestBit);

void main()
{
	ifstream fin;				//These two opens up the data file for
	fin.open("HighBits.dat");   //the numbers.

	int i = 0;			//Counter for the for-loop
	int N;				//Number of cases, will be read from infile
	int k = 0;			//The number itself that will be manipulated

	int highestBit = 0;	//The index of the highest bit.
	int k2 = 0;			//The number with the next highest (Leftmost) bit

	fin >> N;			//Reads in how many cases to help set up for-loop

	//formats header
	cout << "Daniel Portillo\nHighest Bit Program 1\n\nThere are " << N
		<< " test cases.\n\nk    HighestBit   k2\n"
		<< "---------------------\n";
	
	// For-loop goes through the file and finds the highest bit, its
	// index, and the next highes bit.
	// Takes in N for the number of cases it will go through.
	for (i; i < N; i++)
	{
		fin >> k;
		highestBit = FindHighestBit(k);
		k2 = GetK2(k, highestBit);

		cout << left << setw(8) << k << setw(10) << highestBit
			<< setw(5) << k2 << '\n';
	}

	return;
}

//This function will find the highest (leftmost) bit of a number
//and return its index; it takes in the number itself.
int FindHighestBit(int k)
{

	int manipK = k;
	int indexK = 1;

	//Speciel case for 0
	if (manipK == 0)
	{
		indexK = 0;
		return indexK;
	}
	else
	{
		//Finds the index.
		while (manipK = (~manipK ^ ~ONE))
		{
			manipK = manipK >> 1;
			indexK++;

		}

		return indexK;
	}

}

//This function will read in the indes of the highest
//bit and number and manipulate them (using bit manip)
//to get the number with next highest(Leftmost) bit.
int GetK2(int k2, int highestBit)
{
	int manipK2 = k2;

	manipK2 = (manipK2 | (1 << highestBit));

	return manipK2;
}
