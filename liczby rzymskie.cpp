#include <iostream>
using namespace std;

int rzymskieNAarabskie(string roman) //roman to arabic
{
	int size=roman.size();
	int c=0; //which cipher
	int arabic=0; //result
	
	while(c<size && roman[c]=='M')
	{
		arabic+=1000;
		c++;
	}
	if(c>=size)
		return arabic;
		
	for(int nr=100; ; nr/=10) //return always occurs
	{
		char ten,five,one;
		switch(nr)
		{
			case 100: ten='M'; five='D'; one='C'; break;
			case 10: ten='C'; five='L'; one='X'; break;
			case 1: ten='X'; five='V'; one='I'; break;
		}
		if(c<=size-2 && (roman[c+1]==ten || roman[c+1]==five) )
		{
			if(roman[c+1]==ten)
				arabic+=nr*9;
			else
				arabic+=nr*4;
			c+=2;
		}
		else
		{
			while(c<size && (roman[c]==one || roman[c]==five) )
			{
				if(roman[c]==one)
					arabic+=nr;
				else
					arabic+=nr*5;
				c++;
			}
		}
		if(c>=size)
			return arabic;
	}
}

string arabskieNArzymskie (int arabic) //arabic to roman
{
	string roman=""; //result
	
	for(int i=1; i<=3 && arabic>0; i++, arabic/=10)
	{
		char ten,five,one;
		switch(i)
		{
			case 1: ten='X'; five='V'; one='I'; break;
			case 2: ten='C'; five='L'; one='X'; break;
			case 3: ten='M'; five='D'; one='C'; break;
		}
		int cipher=arabic%10;
		if(cipher<=3)
		{
			for(int j=0; j<cipher; j++)
				roman=one+roman;
			continue;
		}
		if(cipher==9)
		{
			roman=ten+roman;
			roman=one+roman;
			continue;
		}
		for(int j=0; j<cipher-5; j++) //6-8
			roman=one+roman;
		roman=five+roman;
		if(cipher==4)
			roman=one+roman;
	}
	
	for(int i=arabic; i>0; i--)
		roman="M"+roman;
	return roman;
}

int main()
{
	for(int i=0; i<=1001; i++)
	{
		cout<<i<<"\t"<<arabskieNArzymskie(i)<<"\t"<<rzymskieNAarabskie(arabskieNArzymskie(i))<<endl;
		if(rzymskieNAarabskie(arabskieNArzymskie(i))!=i)
			break;
	}
	system("pause");
	return 0;
}
