// Objective 1: Learning to write multi file programs in c++
// Objective 2: Visualize the prime dense diagonal lines in an Ulam Spiral.

// Used for output handling
# include <iostream>
// ussed for the squareroot of the length
# include <math.h>
// used to output the Ulam Spiral for display
# include <fstream>
// bitvector
# include "bitVec.h"

using namespace std;

int main(int argc, char** argv)
{
	// create empty bitvector (All 0s) with square length
	if(argc < 2)
	{
		cout << "Usage: ./ulam <size>\n";
		return 1;
	}
	int size = stoi(argv[1]);
	BitVec bitVec(size * size);
	
	// mark all primes in the bitvector with 1s
	for(int i = 2; i <= bitVec.getLen(); i++)
	{
		bitVec.setVal(i);
	}
	for(int i = 2; i <= sqrt(bitVec.getLen()); i++)
	{
		if(bitVec.getVal(i))
		{
			for(int j = i*i; j < bitVec.getLen(); j += i)
			{
				bitVec.delVal(j);
			}
		}
	}


	// store the values in the birvector using an Ulam Spiral
	int x = size/2 + size%2; 
	int y = size/2 + size%2;
	int RIGHT = 0;
	int UP = 1;
	int LEFT = 2;
	int DOWN = 3;
	int direction = RIGHT;
	double max = 1;
	double count = 0;
	char* spiral = new char[size * size];
	for(int i = 1; i <= bitVec.getLen(); i++)
	{
		// add value to an array
		if(bitVec.getVal(i)){spiral[((size-y)*size) + (x - 1)] = '0';}
		else{spiral[((size-y)*size) + (x - 1)] = '-';}

		if(direction == RIGHT){x++;}
		else if(direction == UP){y++;}
		else if(direction == LEFT){x--;}
		else if(direction == DOWN){y--;}
		count += 0.5;
		if(max == count)
		{
			max += 1;
			count = 0;
			direction = (direction + 1) % 4;
		}
		else if(max/2 == count)
		{
			direction = (direction + 1) % 4;
		}
	}

	// Output to file
	ofstream outfile;
	outfile.open("outspiral.txt");

	for(int y = 0; y < size; y++)
	{
		for(int x = 0; x < size; x++)
		{
			outfile << spiral[y*size + x];
		}
		outfile << "\n";
	}

	outfile.close();

	return 1;
}
