#include <iostream>
#include "console.h"
#include "strlib.h"
using namespace std;

string CensorString1(string text, string remove)
{
    string res = text;
    for (unsigned long i = 0; i < remove.length(); i++)
        res = stringReplace(res, charToString(remove[i]), "");
    return res;
}

void CensorString2(string & text, string remove)
{
    for (unsigned long i = 0; i < remove.length(); i++)
        text = stringReplace(text, charToString(remove[i]), "");
}

int main() {
    string str1 = "Stanford University";
    string str2 = "Llamas like to laugh";
    cout << CensorString1(str1, "nt") << endl;
    cout << str1 << endl;
    cout << CensorString1(str2, "la") << endl;
    cout << str2 << endl;

    CensorString2(str1, "nt");
    cout << str1 << endl;
    CensorString2(str2, "la");
    cout << str2 << endl;

    return 0;
}
