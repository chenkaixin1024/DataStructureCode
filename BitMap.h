#pragma once

#include <iostream>
#include <vector>
using namespace std;


class BitSet
{
public:
	BitSet(char bitNum)
	{
		_s.resize((bitNum>>3)+1);
	}

	BitSet(string bit)
	{
		int i=0;
		int j=0;
		int idx=0;
		int len=bit.size();
		_s.resize((len>>3)+1);
		for(i=0;i<len;i++)
		{
			if(i%8==0&&i!=0)
			{
				idx=0;
				j++;
			}
			if(bit[i]=='1')
			{
				_s[j]<<=1;
				_s[j]|=1;
			}
			else
				_s[j]<<=1;
		}

		while(i%8!=0)
		{
			_s[j]<<=1;
			i++;
		}
	}
	void Set(size_t whichBit)
	{
		int i=whichBit/8;
		int j=whichBit%8;
		unsigned char num=1<<(7-j);
		_s[i]|=num;
	}

	void ReSet(size_t whichBit)
	{
		int i=whichBit/8;
		int j=whichBit%8;
		unsigned char num=~(1<<(7-j));
		_s[i]&=num;
	}

	bool Test(size_t whichBit)
	{
		int i=whichBit/8;
		int j=whichBit%8;
		unsigned char num=1<<(7-j);
		return num&_s[i]?true:false;
	}

	void ReSize(size_t size)
	{
		_s.resize((size>>8)+1);
	}

private:
	vector<unsigned char> _s;
};
