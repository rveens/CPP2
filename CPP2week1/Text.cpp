#include "text.h"

int _tmain(int argc, _TCHAR* argv[])
{
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

/* stream operators in global scope */
wostream &operator<<(wostream &wos, const Text &s)
{
	return wos;		
}

wistream &operator>>(wistream &wis, const Text &s)
{
	return wis;
}