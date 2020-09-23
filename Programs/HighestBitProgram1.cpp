/* -------------------------------------------------------------------

	Name: Daniel Portillo

	Course: CS 2433-101, Fall 2020, Stringfellow

	Purpose: This program finds the highest (Leftmost) bit of a given
	         number	of a file and finds the number with the next
		 highest bit.

*/--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ONE = 1;

int FindHighestBit( int k1);
int GetK2( int k2, int highestBit);

int main()
{
	ifstream fin;
	fin.open("HighBits.dat");

	int i = 0;			//Counter for the for-loop
	int N;				//Number of cases, will be read from infile
	int k = 0;			//The number itself that will be manipulated

	int highestBit = 0;		//The index of the highest bit.
	int k2 = 0;			//The number with the next highest (Leftmost) bit

	fin >> N;

	cout << "Daniel Portillo\nHighest Bit Program 1\n\nThere are " << N
		<< " test cases.\n\nk    HighestBit   k2\n"
		<< "---------------------\n";

	for (i; i < N; i++)
	{
		fin >> k;
		highestBit = FindHighestBit(k);
		k2 = GetK2(k, highestBit);

		cout << left << setw(8) << k << setw(10) << highestBit
			<< setw(5) << k2 << '\n';
	}
	
	return 0;
}

int FindHighestBit(int k)
{
	 
	int manipK = k;
	int indexK = 1;

	if (manipK == 0 )
	{
		indexK = 0;
		return indexK;
	}
	else
	{
		while ( manipK = (~manipK ^ ~ONE))	 
		{
			manipK = manipK >> 1;
			indexK++;

		} 
		
		return indexK;
	}
	
}

int GetK2 (int k2, int highestBit)
{
	int manipK2 = k2;

	manipK2 = (manipK2 | (1 << highestBit)) ;

	return manipK2;
}
