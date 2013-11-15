#include "Text.h"

/* constructors */
Text::Text() : data(nullptr) // default constructor
{
	wcout << "Constructor van Test wordt aangeroepen" << endl;
}

Text::Text(const char *s) // constructor met char *
{
	size_t size = strlen(s);
	if (size > Text::maxSize)
		; // error
	else {
		size_t convertedChars = 0;
		this->data = new wchar_t[size+1]; // alloceer nieuw geheugen. + 1 voor nullbyte
#ifdef _WIN32
        mbstowcs_s(&convertedChars, this->data, size+1, s, _TRUNCATE); // kopieer de gegeven string in het geheugen in de heap.
#elif defined __linux__
        mbstowcs(this->data, s, size+1); // kopieer de gegeven string in het geheugen in de heap.
#endif
	}
}

Text::Text(const wchar_t *s) // constructor met wchar_t * */
{
	size_t size = wcslen(s);
	if (size > Text::maxSize)
		; // error
	else {
		this->data = new wchar_t[size+1]; // alloceer nieuw geheugen. + 1 voor nullbyte
#ifdef _WIN32 
		wcscpy_s(this->data, size, s); // kopieer de gegeven string in het geheugen in de heap.
#elif defined __linux__
		wcscpy(this->data, s); // kopieer de gegeven string in het geheugen in de heap.
#endif
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
#ifdef _WIN32 
		mbstowcs_s(&convertedChars, this->data, size+1, t, _TRUNCATE); // kopieer de gegeven string in het geheugen in de heap.
#elif defined __linux__
		mbstowcs(this->data, t, Text::maxSize); // kopieer de gegeven string in het geheugen in de heap.
#endif
	}
}

Text::Text(const Text &s) // copy constructor
{
	// Stel 'this' in met een kopie van de data van s.
	size_t size = (wcslen(s.data)+1) * 2;
	this->data = new wchar_t[size];

#ifdef _WIN32 
	wcscpy_s(this->data, size, s.data);
#elif defined __linux__
	wcscpy(this->data, s.data);
#endif
}

Text::Text(Text &&s) : data(std::move(s.data)) // move constructor
{
	s.data = nullptr;
}

Text &Text::operator=(const Text &s) // copy assignment operator
{
	// gooi 'this' eerst weg en stop de waardes van de ander in 'this'
	if (this->data)
		delete[] this->data;

	// alloceer nieuw
	size_t size = wcslen(s.data);
	this->data = new wchar_t[size+1];


#ifdef _WIN32 
	wcscpy_s(this->data, size, s.data);
#elif defined __linux__
	wcscpy(this->data, s.data);
#endif

	return *this;
}

Text &Text::operator=(Text &&s) // move assignment operator
{
	// kijk of gegeven niet gelijk is aan 'this'. Gebruik std::move om de ingewanend (data) naar this te gooien.
	// Gooi voor de zekerheid de ingewanden van de ander weg.

	if (s != *this) {
		this->data = s.data;

		// pointer zou nu nergens meer naar moeten wijzen.
		s.data = nullptr;
	}

	return *this;
}

Text &Text::operator+=(const Text &s) // += operator
{
	// verander 'this' door s er aan toe te voegen. Geef een referentie terug.
	size_t totalsize = (wcslen(this->data) + wcslen(s.data))*2;
	wchar_t *b = new wchar_t[totalsize]; // buffer waar ze allebei in passen.


#ifdef _WIN32 
	// kopieer de data van 'this' er in.
	wcscpy_s(b, totalsize, this->data);
	// concat de string van 's' er bij.
	wcscat_s(b, totalsize, s.data);
#elif defined __linux__
	// kopieer de data van 'this' er in.
	wcscpy(b, this->data);
	// concat de string van 's' er bij.
	wcscat(b, s.data);
#endif

	// vernietig huidige data van 'this'
	if (this->data)
		delete[] data;

	// stel de buffer in als data
	this->data = b;

	return *this;
}

Text Text::operator+(const Text &s) // + operator
{
	// nieuw object terug met de twee aan elkaar geplakte strings.
	Text t = *this;
	t += s;

	return t;
}

wchar_t &Text::operator[](int i) // [] operator
{
	if (i < 0 || i > (wcslen(this->data)-1) )
		throw std::out_of_range("operator[] out of range");
	else
		return this->data[i]; // TODO check voor errors, exception
}

bool Text::operator==(const Text &other)  // comparison operator
{
	if (!this->data || !other.data)
		return 0;
	else
		return wcscmp(this->data, other.data) == 0;
}

bool Text::operator!=(const Text &other)  // inverted comparison operator
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
