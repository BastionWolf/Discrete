/* -------------------------------------------------------------------

	Name: Daniel Portillo

	Course: CS 2433-101, Fall 2020, Stringfellow

	Purpose: 

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ONE = 1;
int ZERO = 0;

int FindHighestBit( int k1);
int GetK2( int k2, int highestBit);

int main()
{
	ifstream fin;
	fin.open("HighBits.dat");

	int i = 0;
	int N;				//Number of test cases, will be read from infile
	int k = 0;			//The test case number

	int highestBit = 0;
	int k2 = 0;

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
