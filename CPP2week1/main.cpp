#include "Text.h"

/* main functie */
int main(int argc, char *argv[])
{
    Text voornaam = "Henk";
    Text achternaam;
    achternaam = "van den Eik";
    Text naam = voornaam + " ";
    naam += achternaam;
    wcout << naam << endl; // Henk van den Eik
    naam[11] = 'r';
    wcout << naam << endl; // Henk van der Eik
    //wcin.get();

    return 0;
}
