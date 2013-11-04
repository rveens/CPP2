#include <tchar.h>
#include <iostream>
#include <string>
using namespace std;

class Text
{
private:
    wchar_t *data;
    // todo: zet hier de overige data-members
    
public:
    Text();
    Text(const Text &s);
    Text(const char *s);
    Text(const wchar_t *s);
    Text(string s);
    ~Text();

    Text &operator += (Text s);
    wchar_t &operator [] (int i);
    
    // todo: voeg overige methodes toe
};