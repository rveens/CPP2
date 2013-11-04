#include "text.h"

/* main functie */
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


/* Text implementation */


/* constructors */
Text::Text() : data(new wchar_t[0]) // default constructor
{

}

Text::Text(const char *s) // constructor met char *
{
	delete[] this->data; // data eerst weggooien.
	this->data = new wchar_t[sizeof(s)]; // data alloceren zodat de nieuwe er in past.
	// copy 
}

Text::Text(const wchar_t *s) // constructor met wchar_t *
{

}

Text::Text(string s)
{

}

Text::Text(const Text &s) // copy constructor
{
	
}

Text::Text(Text &&s) // move constructor
{
	
}

Text::~Text() // destructor
{
	delete[] data;
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