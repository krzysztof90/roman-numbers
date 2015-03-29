#include <iostream>
using namespace std;

int rzymskieNAarabskie(string roman) //roman to arabic
{
	int size=roman.size();
	int c=0; //which cipher
	int arabic=0;
	while(c<size && roman[c]=='M')
	{
		arabic+=1000;
		c++;
	}
	if(c>=size)
		return arabic;
		
	if(c<=size-2 && (roman[c+1]=='M' || roman[c+1]=='D') )
	{
		if(roman[c+1]=='M')
		{
			arabic+=900;
			c+=2;
		}
		else
		{
			arabic+=400;
			c+=2;
		}
	}
	else
	{
		while(c<size && (roman[c]=='C' || roman[c]=='D') )
		{
			if(roman[c]=='C')
			{
				arabic+=100;
				c++;
			}
			else
			{
				arabic+=500;
				c++;
			}
		}
	}
	if(c>=size)
		return arabic;
		
	if(c<=size-2 && (roman[c+1]=='C' || roman[c+1]=='L') )
	{
		if(roman[c+1]=='C')
		{
			arabic+=90;
			c+=2;
		}
		else 
		{
			arabic+=40;
			c+=2;
		}
	}
	else
	{
		while(c<size && (roman[c]=='X' || roman[c]=='L') )
		{
			if(roman[c]=='X')
			{
				arabic+=10;
				c++;
			}
			else
			{
				arabic+=50;
				c++;
			}
		}
	}
	if(c>=size)
		return arabic;

	if(c<=size-2 && (roman[c+1]=='X' || roman[c+1]=='V') )
	{
		if(roman[c+1]=='X')
		{
			arabic+=9;
			c+=2;
		}
		else
		{
			arabic+=4;
			c+=2;
		}
	}
	else
	{
		while(c<size && (roman[c]=='I' || roman[c]=='V') )
		{
			if(roman[c]=='I')
			{
				arabic+=1;
				c++;
			}
			else
			{
				arabic+=5;
				c++;
			}
		}
	}
	return arabic;
}

string arabskieNArzymskie (int arabic) //arabic to roman
{
	string roman="";
	
	if(arabic>0)
	{
		switch(arabic%10)
		{
			case 1: roman="I"; break;
			case 2: roman="II"; break;
			case 3: roman="III"; break;
			case 4: roman="IV"; break;
			case 5: roman="V"; break;
			case 6: roman="VI"; break;
			case 7: roman="VII"; break;
			case 8: roman="VIII"; break;
			case 9: roman="IX"; break;
		}
		arabic/=10;
	}
	
	if(arabic>0)
	{
		switch(arabic%10)
		{
			case 1: roman="X"+roman; break;
			case 2: roman="XX"+roman; break;
			case 3: roman="XXX"+roman; break;
			case 4: roman="XL"+roman; break;
			case 5: roman="L"+roman; break;
			case 6: roman="LX"+roman; break;
			case 7: roman="LXX"+roman; break;
			case 8: roman="LXXX"+roman; break;
			case 9: roman="XC"+roman; break;
		}
		arabic/=10;
	}
	
	if(arabic>0)
	{
		switch(arabic%10)
		{
			case 1: roman="C"+roman; break;
			case 2: roman="CC"+roman; break;
			case 3: roman="CCC"+roman; break;
			case 4: roman="CD"+roman; break;
			case 5: roman="D"+roman; break;
			case 6: roman="DC"+roman; break;
			case 7: roman="DCC"+roman; break;
			case 8: roman="DCCC"+roman; break;
			case 9: roman="CM"+roman; break;
  	}
	  arabic/=10;
	}
	for(int i=arabic; i>0; i--)
		roman="M"+roman;
	return roman;
}

int main()
{
	return 0;
}
