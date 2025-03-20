#include <stdio.h>

char toupper(char ch)
{
	if(ch >= 'a' && ch <= 'z')
	{
		return ch - 32;
	}
}

char tolower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
	{
		return ch + 32;
	}
}
int main()
{
	
	return 0;
}
