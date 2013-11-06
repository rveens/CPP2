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
Text::Text() : data(nullptr) // default constructor
{
	
}

Text::Text(const char *s) // constructor met char *
{
	size_t size = strlen(s);
	if (size > Text::maxSize)
		; // error
	else {
		size_t convertedChars = 0;
		this->data = new wchar_t[size+1]; // alloceer nieuw geheugen. + 1 voor nullbyte
		//mbstowcs(this->data, s, Text::maxSize); // kopieer de gegeven string in het geheugen in de heap.
		mbstowcs_s(&convertedChars, this->data, size+1, s, _TRUNCATE); // kopieer de gegeven string in het geheugen in de heap.
	}
}

Text::Text(const wchar_t *s) // constructor met wchar_t * */
{
	size_t size = wcslen(s);
	if (size > Text::maxSize)
		; // error
	else {
		this->data = new wchar_t[size+1]; // alloceer nieuw geheugen. + 1 voor nullbyte
		//wcscpy(this->data, s); // kopieer de gegeven string in het geheugen in de heap.
		wcscpy_s(this->data, size, s); // kopieer de gegeven string in het geheugen in de heap.
	}
}

Text::Text(string s)
{
	const char *t = s.c_str();

	size_t size = strlen(t);
	if (size > Text::maxSize)
		; // error
	else {
		size_t convertedChars = 0;
		this->data = new wchar_t[size+1]; // alloceer nieuw geheugen. + 1 voor nullbyte
		//mbstowcs(this->data, t, Text::maxSize); // kopieer de gegeven string in het geheugen in de heap.
		mbstowcs_s(&convertedChars, this->data, size+1, t, _TRUNCATE); // kopieer de gegeven string in het geheugen in de heap.
	}
}

Text::Text(const Text &s) // copy constructor
{
	// Stel 'this' in met een kopie van de data van s.
	size_t size = wcslen(s.data);
	this->data = new wchar_t[size+1];

	wcscpy_s(this->data, size, s.data);
}

Text::Text(Text &&s) : data(std::move(s.data)) // move constructor
{

}

Text &Text::operator=(const Text &s) // copy assignment operator
{
	// gooi 'this' eerst weg en stop de waardes van de ander in 'this'
	if (this->data)
		delete[] this->data;

	// alloceer nieuw
	size_t size = wcslen(s.data);
	this->data = new wchar_t[size+1];

	wcscpy_s(this->data, size, s.data);

	return *this;
}

Text &Text::operator=(Text &&s) // move assignment operator
{
	// kijk of gegeven niet gelijk is aan 'this'. Gebruik std::move om de ingewanend (data) naar this te gooien.
	// Gooi voor de zekerheid de ingewanden van de ander weg.

	if (s != *this) {
		this->data = std::move(s.data);

		// voor de zekerheid verwijderen.
		s.data = nullptr;
	}

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
	return this->data[i]; // TODO check voor errors, exception
}

bool Text::operator==(Text &other)  // comparison operator
{
	if (!this->data || !other.data)
		return 0;
	else
		return wcscmp(this->data, other.data) == 0;
}

bool Text::operator!=(Text &other)  // inverted comparison operator
{
	return !(*this == other); // gewoon de andere operator gebruiken!
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