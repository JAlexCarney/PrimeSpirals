# include <iostream>
# include "bitVec.h"

using namespace std;

BitVec :: BitVec(int length)
{
	len = length;
	data = new char [(len/8)+1];
	for(int i = 0; i < (len/8)+1; i++)
	{
		data[i] = 0;	
	}
}

int BitVec :: getLen()
{
	return len;
} 

bool BitVec :: getVal(int pos)
{
	return (bool) ( data[ pos / 8 ] & ( 0x01 << ( pos % 8 ) ) );
}

void BitVec :: setVal(int pos)
{
	data[ pos / 8 ] = data[ pos / 8 ] | ( 0x01 << ( pos % 8 ) );
}

void BitVec :: delVal(int pos)
{
	data[ pos / 8 ] = data[ pos / 8 ] & ( ~ ( 0x01 << ( pos % 8 ) ) );
}

void BitVec :: print()
{
	for(int i = 0; i < len; i++)
	{
		if(getVal(i))
		{
			cout << "1";
		}else{
			cout << "0";
		}
	}
	cout << "\n";
}
