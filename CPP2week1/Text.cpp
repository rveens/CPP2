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
	// copy s naar data;
}

Text::Text(const wchar_t *s) /* : data(new wchar_t[strlen(s)]) // constructor met wchar_t * */
{
	//strcpy(this->data, s);
}

Text::Text(string s)
{
	data = new wchar_t[s.length()];

	//strcpy(this->data, s.c_str());
}

Text::Text(const Text &s) // copy constructor
{
	// Stel 'this' in met de data van s.
}

Text::Text(Text &&s) // move constructor
{
	// Gebruik std::move om de ingewanend (data) naar this te gooien.
}

Text &Text::operator=(const Text &s) // copy assignment operator
{
	// gooi 'this' eerst weg en stop de waardes van de ander in 'this'



	return *this;
}

Text &Text::operator=(Text &&s) // move assignment operator
{
	// kijk of gegeven niet gelijk is aan 'this'. Gebruik std::move om de ingewanend (data) naar this te gooien.
	// Gooi voor de zekerheid de ingewanden van de ander weg.

	/*if (s != *this) {

	}*/

	return *this;
}

Text &Text::operator+=(Text s) // += operator
{
	// verander 'this' door s er aan toe te voegen. Geef een referentie terug.

	return *this;
}

Text &Text::operator+(Text s) // + operator
{
	// nieuw object terug met de twee aan elkaar geplakte strings.
	Text t;

	return t;
}

wchar_t &Text::operator[](int i) // [] operator
{
	return this->data[i];
}

Text::~Text() // destructor
{
	delete[] data;
}

/* stream operators in global scope */
wostream &operator<<(wostream &wos, const Text &s)
{
	wstring t(s.data);

	wos << t;

	return wos;		
}

wistream &operator>>(wistream &wis, const Text &s)
{
	wis >> s.data;

	return wis;
}