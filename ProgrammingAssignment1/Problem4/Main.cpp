#include <iostream>
#include <cctype>
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

// converts letter to digit using the Soundex table
int SoundexConvertToDigit(char letter)
{
    switch (letter) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'H':
    case 'W':
    case 'Y':
        return 0;
    case 'B':
    case 'F':
    case 'P':
    case 'V':
        return 1;
    case 'C':
    case 'G':
    case 'J':
    case 'K':
    case 'Q':
    case 'S':
    case 'X':
    case 'Z':
        return 2;
    case 'D':
    case 'T':
        return 3;
    case 'M':
    case 'N':
        return 4;
    case 'L':
        return 5;
    case 'R':
        return 6;
    default:
        error("Letter not found");
    }
}

string SoundexCode(string surname)
{
    surname = toUpperCase(surname);

    string res = charToString(surname[0]);
    for (unsigned int i = 1; i < surname.size(); i++)
        if (isalpha(surname[i]))
            res += integerToString(SoundexConvertToDigit(surname[i]));

    // remove any consecutive duplicate digits and zeros
    for (unsigned int i = 0; i < res.size()-1; i++) {
        if (res[i] == res[i+1] || res[i+1] == '0') {
            res.erase(i+1, 1);
            i--; // there is one less character now
        }
    }

    // if resulting code has length greater than 4, truncate it
    if (res.size() > 4)
        res.erase(4);
    else if (res.size() < 4) // if less than 4, pad with zeros
        res.append(4 - res.size(), '0');

    return res;
}

int main() {
    while (true) {
        string surname = getLine("Enter surname (RETURN to quit):");
        if (surname == "")
            break;
        cout << "Soundex code for " << surname << " is " << SoundexCode(surname)
             << endl;
    }

    return 0;
}
