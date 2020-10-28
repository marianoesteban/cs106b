#include <fstream>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "vector.h"
using namespace std;

Vector<int> ReadScores(ifstream& stream)
{
    Vector<int> vec(10, 0);

    int score;
    while (stream >> score)
        vec[score/10]++;

    return vec;
}

void PrintHistogram(Vector<int>& scores)
{
    for (int i = 0; i < 10; i++)
        cout << i*10 << "-" << (i*10)+9 << ": " << string(scores[i], 'x') << endl;
}

int main() {
    ifstream stream;
    promptUserForFile(stream, "Enter the file name:");

    Vector<int> scores = ReadScores(stream);

    PrintHistogram(scores);

    return 0;
}
