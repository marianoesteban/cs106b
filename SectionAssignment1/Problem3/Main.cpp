#include <cctype>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "vector.h"
using namespace std;

void CountLetters(string filename)
{
    string text = readEntireFile(filename);
    Vector<int> letterCount; // first count is 'a', last is 'z'
    for (char letter = 'a'; letter <= 'z'; letter++)
        letterCount.add(0);
    for (unsigned int i = 0; i < text.size(); i++) {
        if (isalpha(text[i]))
            letterCount[tolower(text[i])-'a']++;
    }

    // print the counts
    for (int i = 0; i < letterCount.size(); i++)
        cout << char('a' + i) << ": " << letterCount[i] << endl;
}

int main() {
    CountLetters("myfile.txt");
    return 0;
}
