#ifdef _WIN32 
#include <tchar.h>
#elif defined __linux__
#include <wchar.h>
#include <cstring>
#include <stdexcept>
#else
#error undefined platform!
#endif

#include <iostream>
#include <string>

using std::string;
using std::wstring;
using std::endl;
using std::wcout;
using std::wcin;
using std::wostream;
using std::wistream;

class Text
{
// members
private:
    wchar_t *data;
    // todo: zet hier de overige data-members
public:
	const static int maxSize = 1000;
   
// functions
public:
    Text();	// default constructor
    Text(const Text &s); // copy constructor
	Text(Text &&s); // move copy constructor
	~Text(); // destructor
    Text(const char *s); // constructor met char *
    Text(const wchar_t *s); // constructor met wchar_t *
    Text(string s); // constructor met std::string

	Text &operator=(const Text &s); // copy assignment operator
	Text &operator=(Text &&s); // move assignment operator
    Text &operator+=(const Text &s); // += operator
	Text operator+(const Text &s); // + operator
    wchar_t &operator[](int i); // [] operator

	// TODO
	bool operator==(const Text &other);  // comparison operator
	bool operator!=(const Text &other);  // inverted comparison operator

	friend wostream &operator<<(wostream &wos, const Text &s); // << operator friend 
	friend wistream &operator>>(wistream &wis, const Text &s); // >> operator friend 
    
    // todo: voeg overige methodes toe
};
