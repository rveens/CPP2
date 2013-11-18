
#ifdef _WIN32 
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Text.h"

/* main functie */
int main(int argc, char *argv[])
{
#ifdef _WIN32
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
    Text voornaam = "Henk";
    Text achternaam;
    achternaam = "van den Eik";
    Text naam = voornaam + " ";
    naam += achternaam;
    wcout << naam << endl; // Henk van den Eik
    naam[11] = 'r';
    wcout << naam << endl; // Henk van der Eik
    wcin.get();

    return 0;
}
