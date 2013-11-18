#ifdef _WIN32 
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "ARRAY.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void week3a()
{
	ARRAY<int> lijst(3); // maakt een array met drie elementen
	lijst[0] = 11;
	lijst[1] = 12;
	lijst[2] = 13;
	int n = lijst.length();
	for(int i = 0; i < n; i++)
	{
	   cout << "lijst[" << i << "]=" << lijst[i] << endl;
	}
	lijst[3] = 14; // moet een exception genereren
}

void week3b()
{
	ARRAY<int> lijst; // maakt een array met nul elementen
	lijst.append(13); // voegt toe aan het einde
	lijst[-1] = 12; // voegt toe aan het einde
	int n = lijst.length();
	for(int i = 0; i < n; i++)
	{
	   cout << "lijst[" << i << "]=" << lijst[i] << endl;
	}
	lijst[2] = 14; // moet een exception genereren 
}

int main(int argc, char *argv[])
{
#ifdef _WIN32
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
	week3a();
	week3b();

	return 0;
}
