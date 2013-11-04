#include <tchar.h>
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::wcout;
using std::wcin;
using std::wostream;
using std::wistream;

class Text
{
private:
    wchar_t *data;
    // todo: zet hier de overige data-members
    
public:
    Text();	// default constructor
    Text(const Text &s); // copy constructor
	Text(Text &&s); // move copy constructor
	~Text(); // destructor
    Text(const char *s); // constructor met char *
    Text(const wchar_t *s); // constructor met wchar_t *
    Text(string s); // constructor met std::string

	Text &operator=(Text &s); // copy assignment operator
	Text &operator=(Text &&s); // move assignment operator
    Text &operator += (Text s); // += operator
    wchar_t &operator [] (int i); // [] operator

	friend wostream &operator<<(wostream &wos, const Text &s); // << operator friend 
	friend wistream &operator>>(wistream &wis, const Text &s); // >> operator friend 
    
    // todo: voeg overige methodes toe
};